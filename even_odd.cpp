#include <iostream>
#include <memory>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <exception>
#include <functional>
#include <type_traits>

// ====================================================================
// 1. Extern, mutable, volatile & const volatile demonstration
// ====================================================================
// using namespace std;

// Simulate an extern variable (imagine this is defined in another file)
extern int sharedValue;  // Declaration: defined elsewhere

// In this file, we define it:
int sharedValue = 42;

// A class using mutable and const volatile
class DataHolder {
public:
    DataHolder(int val) : value(val) {}

    // Log access even in const methods
    void logAccess() const {
        // mutable member can be changed even in const functions
        ++accessCount;
        // We simulate a volatile hardware register (for demonstration)
        std::cout << "Access count: " << accessCount << " [Hardware value: " << hwValue << "]\n";
    }

    int getValue() const { return value; }

private:
    int value;
    mutable int accessCount{0};
    // Simulated hardware register that might change unexpectedly:
    const volatile int hwValue = 100;
};

// ====================================================================
// 2. Function Pointer Callback and RAII for Locking (Multithreading)
// ====================================================================

using Callback = void(*)(int);

// A simple callback function
void sampleCallback(int data) {
    std::cout << "Callback invoked with data: " << data << std::endl;
}

// A function that registers and calls a callback
void registerAndCallCallback(Callback cb) {
    if (cb)
        cb(sharedValue); // Using the extern variable here
}

// A thread-safe counter using RAII for lock management
class ThreadSafeCounter {
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mutex_);
        ++counter;
    }

    int get() const {
        // Using atomic read for thread safety (or could lock here as well)
        return counter.load();
    }

private:
    mutable std::mutex mutex_;
    std::atomic<int> counter{0};
};

// ====================================================================
// 3. Virtual Functions, Diamond Inheritance, and Covariant Return
// ====================================================================

// Base class for diamond inheritance
class Base {
public:
    virtual ~Base() = default;
    virtual void info() const { std::cout << "Base info\n"; }
    // Covariant return: clone returns a Base pointer
    virtual Base* clone() const { return new Base(*this); }
};

// Two intermediate classes that virtually inherit from Base
class DerivedA : virtual public Base {
public:
    void info() const override { std::cout << "DerivedA info\n"; }
};

class DerivedB : virtual public Base {
public:
    void info() const override { std::cout << "DerivedB info\n"; }
};

// A class that inherits from both DerivedA and DerivedB (diamond)
class Diamond : public DerivedA, public DerivedB {
public:
    void info() const override { std::cout << "Diamond info\n"; }
    // Covariant return: return Diamond pointer
    Diamond* clone() const override { return new Diamond(*this); }
};

// ====================================================================
// 4. Variadic Template & SFINAE for type printing
// ====================================================================

// A helper function to print multiple arguments using a fold expression
template<typename... Args>
void printAll(Args&&... args) {
    ((std::cout << args << " "), ...) << std::endl;
}

// A function template enabled only for integral types using SFINAE
template<typename T>
std::enable_if_t<std::is_integral_v<T>, void> printIfIntegral(T value) {
    std::cout << "Integral value: " << value << std::endl;
}

// ====================================================================
// 5. Type Erasure for a Callable Wrapper (AnyCallable)
// ====================================================================

class AnyCallable {
public:
    template<typename Callable>
    AnyCallable(Callable c) : impl_(std::make_unique<Model<Callable>>(std::move(c))) {}

    void operator()() { impl_->invoke(); }

private:
    struct Concept {
        virtual ~Concept() = default;
        virtual void invoke() = 0;
    };

    template<typename Callable>
    struct Model : Concept {
        Model(Callable c) : callable(std::move(c)) {}
        void invoke() override { callable(); }
        Callable callable;
    };

    std::unique_ptr<Concept> impl_;
};

// ====================================================================
// 6. Exception Handling and RAII in Destructors
// ====================================================================

class Resource {
public:
    Resource() { std::cout << "Acquiring resource.\n"; }
    ~Resource() {
        // Avoid throwing exceptions from destructors
        try {
            std::cout << "Releasing resource.\n";
        } catch (...) {
            // Log error and do not throw
        }
    }
};

// A function that throws an exception to demonstrate stack unwinding
void riskyFunction() {
    Resource res; // RAII ensures this resource is released even if an exception is thrown
    throw std::runtime_error("Something went wrong!");
}

// ====================================================================
// 7. std::move and std::forward usage in a simple class
// ====================================================================

class Movable {
public:
    Movable(std::string data) : data_(std::move(data)) {
        std::cout << "Constructed with data: " << data_ << std::endl;
    }
    // Move constructor
    Movable(Movable&& other) noexcept : data_(std::move(other.data_)) {
        std::cout << "Moved object.\n";
    }
    // Deleted copy constructor to enforce move semantics
    Movable(const Movable&) = delete;

private:
    std::string data_;
};

// ====================================================================
// Main Function: Demonstrates the advanced features
// ====================================================================

int main() {
    // 1. Extern, mutable, and volatile demonstration
    DataHolder dh(10);
    dh.logAccess();
    std::cout << "DataHolder value: " << dh.getValue() << "\n";

    // 2. Function pointer callback and RAII locking in multithreading
    registerAndCallCallback(sampleCallback);
    ThreadSafeCounter counter;
    auto threadFunc = [&counter]() {
        for (int i = 0; i < 1000; ++i) {
            counter.increment();
        }
    };

    std::thread t1(threadFunc);
    std::thread t2(threadFunc);
    t1.join();
    t2.join();
    std::cout << "ThreadSafeCounter value: " << counter.get() << "\n";

    // 3. Virtual functions, diamond inheritance, and covariant return types
    Diamond diamond;
    Base* basePtr = &diamond;
    basePtr->info();  // Should print "Diamond info"
    std::unique_ptr<Base> cloned(basePtr->clone());
    cloned->info();

    // 4. Variadic template printing and SFINAE enabled function
    printAll("Multiple", "arguments", 1, 2, 3.14);
    printIfIntegral(100);
    // printIfIntegral(3.14); // This line would cause a compile error because 3.14 is not integral

    // 5. Type erasure with AnyCallable
    AnyCallable anyCallable([] { std::cout << "Called through type erasure!\n"; });
    anyCallable();

    // 6. Exception handling demonstration
    try {
        riskyFunction();
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << "\n";
    }

    // 7. Using std::move in a move constructor
    Movable m1("Sample Data");
    Movable m2(std::move(m1));

    // Demonstrate reinterpret_cast: Convert int* to char*
    int value = 0x12345678;
    int* intPtr = &value;
    char* charPtr = reinterpret_cast<char*>(intPtr);
    std::cout << "Byte representation of int value:";
    for (std::size_t i = 0; i < sizeof(int); ++i)
        std::cout << " " << std::hex << (0xff & static_cast<int>(charPtr[i]));
    std::cout << std::dec << "\n";

    return 0;
}

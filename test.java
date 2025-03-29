import java.util.*

class Add{
    add(int a, int b){
    System.out.println("output 1"+(a+b));
    }
    add(int a,int b,int c){
    System.out.println("output 2:"+(a+b+c));
    }
    add(int a, float b){
    System.out.println("output 3:"+(a+b));
    }
    public static void main(String args[]){
    add(5,10);
    add(1,2,3);
    add(2,5.3);
    }
};

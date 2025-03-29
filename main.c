//Linear search 1D
// #include <stdio.h>
// int LinearSearch(int arr[],int n,int key){
//   for(int i=0;i<n;i++){
//     if(arr[i]==key){
//       return i;
//     }
//   }
// }
// int main(){
//   int n,key;
//   printf("enter the siZE OF ARR: ");
//   scanf("%d",)
// }
//Linear Search 1D
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n, key;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the key to search: ");
  scanf("%d", &key);

  int index = linearSearch(arr, n, key);
  if (index != -1) {
    printf("Key %d found at index %d\n", key, index);
  } else {
    printf("Key %d not found in the array\n", key);
  }
  return 0;
}
// //Linear search 2d
// #include <stdio.h>

// int matrix(int m, int n, int array[][10]) {
//   printf("Enter %d elements: ", (m * n));
//   for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//       scanf("%d", &array[i][j]);
//     }
//   }
//   for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//       printf("%d\t", array[i][j]);
//     }
//     printf("\n");
//   }
// }

// int linearsearch(int m, int n, int matrix[][10], int item) {
//   int count = 0;
//   for (int i = 0; i < m; i++) {
//     for (int j = 0; j < n; j++) {
//       if (matrix[i][j] == item) {
//         printf("Item found at [%d, %d] \n", i, j);
//         count++;
//       }
//     }
//   }
//   if (count == 0)
//     printf("Item Not found\n");
// }

// int main() {
//   int m, n, item, array[10][10];
//   printf("Enter the number of rows and columns: ");
//   scanf("%d %d", &m, &n);
//   matrix(m, n, array);
//   printf("Enter the item to find: ");
//   scanf("%d", &item);
//   linearsearch(m, n, array, item);
//   return 0;
// }

//binary search iterative
// #include <stdio.h>

// int binarySearch(int arr[], int l, int r, int x)
// {
// while (l <= r)
// {
// int m = l + (r-l)/2;

// if (arr[m] == x)
// return m;

// if (arr[m] < x)
// l = m + 1;

// else
// r = m - 1;
// }

// return -1;
// }
// int main(void)
// {
// int arr[] = {2, 3, 4, 10, 40};
// int n = sizeof(arr)/ sizeof(arr[0]);
// int x = 10;
// int result = binarySearch(arr, 0, n-1, x);
// (result == -1)? printf("Element is not present in array")
// : printf("Element is present at index %d", result);
// return 0;
// }
//insertion Sort
// #include <stdio.h>

// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;
        
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int arr[] = {12, 11, 13, 5, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     printf("Original array: ");
//     printArray(arr, n);
    
//     insertionSort(arr, n);
    
//     printf("Sorted array: ");
//     printArray(arr, n);
    
//     return 0;
// }
//Selection sort
// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
        
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
        
//         if (minIndex != i) {
//             swap(&arr[i], &arr[minIndex]);
//         }
//     }
// }

// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     printf("Original array: ");
//     printArray(arr, n);
    
//     selectionSort(arr, n);
    
//     printf("Sorted array: ");
//     printArray(arr, n);
    
//     return 0;
// }
// #include <stdio.h>

// int binarySearch(int arr[], int l, int r, int x)
// {
// if (r >= l)
// {
// int mid = l + (r - l)/2;

// if (arr[mid] == x) return mid;

// if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

// return binarySearch(arr, mid+1, r, x);
// }

// return -1;
// }
// int main(void)
// {
// int arr[] = {2, 3, 4, 10, 40};
// int n = sizeof(arr)/ sizeof(arr[0]);
// int x = 10;
// int result = binarySearch(arr, 0, n-1, x);
// (result == -1)? printf("Element is not present in array")
// : printf("Element is present at index %d", result);
// return 0;
// }

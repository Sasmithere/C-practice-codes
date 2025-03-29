#include "stdio.h"

int findPeakElement(int nums[], int n) {
  int left = 0;
  int right = n - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid + 1]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
}

void PrintArray(int nums[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", nums[i]);
  }
}

int main() {
  int nums[] = {1, 2, 3, 1};
  printf("Given array: ");
  PrintArray(nums, 4);
  printf("\n");
  printf("The peak element is : %d\n", findPeakElement(nums, 4));
}
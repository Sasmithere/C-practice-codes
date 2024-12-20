/*Remove duplicates from a given array: Given a sorted integer array arr, 
write a program in C to return the array after removing the duplicates, with all the other 
elements in place.*/
#include <stdio.h>

int removeDuplicates(int arr[], int size) {
	if (size == 0 || size == 1) {
		return size;
	}

	int j = 0; // Index of the next unique element

	for (int i = 0; i < size - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			arr[j++] = arr[i];
		}
	}

	arr[j++] = arr[size - 1]; // Add the last element

	return j;
}

int main() {
	int arr[] = {1, 2, 2, 3, 4, 4, 5};
	//int size = sizeof(arr) / sizeof(arr[0]);
	int size = 7;

	size = removeDuplicates(arr, size);

	printf("Array after removing duplicates: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

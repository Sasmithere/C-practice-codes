//quicksort

#include <stdio.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int lb, int ub)
{
	int pivot = arr[ub];
	int i = (lb - 1);
	for (int j = lb; j <= ub - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[ub]);
	return (i + 1);
}


void quickSort(int arr[], int lb, int ub)
{
	if (lb < ub) {
		int pi = partition(arr, lb, ub);
		quickSort(arr, lb, pi - 1);
		quickSort(arr, pi + 1, ub);
	}
}

int main()
{
	int arr[30],N,i;
  printf("enter the size off array :");
  scanf("%d",&N);
  for(i=0;i<N;i++){
    printf("Enter %d element of array :",i);
    scanf("%d",&arr[i]);
  }
  printf("Array before sorting :\n");
  for(i=0;i<N;i++){
    printf("%d  ",arr[i]);
  }
	quickSort(arr, 0, N-1);
	printf("\nSorted array: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	return 0;
}

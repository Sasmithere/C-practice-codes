#include <stdio.h>

void MergeSort(int *, int, int);
void Merge(int *, int, int, int);

int main(void) 
{
  int i, n, a[50], lb, ub;
  printf("Enter array size : ");
  scanf("%d", &n);
  printf("\nEnter the array elements : ");
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("\n\nArray before sorting : ");
  for(i = 0; i < n; i++)
    printf("%d  ", a[i]);
  lb = 0;
  ub = n - 1; // Fix the upper bound here
  MergeSort(a, lb, ub);
  printf("\n\nArray after sorting : ");
  for(i = 0; i < n; i++)
    printf("%d  ", a[i]);
  return 0;
}

void MergeSort(int *a, int lb, int ub)
{
  if(lb < ub)
  {
    int mid = (lb + ub) / 2;
    MergeSort(a, lb, mid);
    MergeSort(a, mid + 1, ub);
    Merge(a, lb, mid, ub);
  }
}

void Merge(int *a, int lb, int mid, int ub)
{
  int i = lb;
  int j = mid + 1;
  int k = lb;
  int b[50];

  while(i <= mid && j <= ub)
  {
    if(a[i] < a[j])
    {
      b[k] = a[i];
      i++;
    }
    else
    {
      b[k] = a[j];
      j++;
    }
    k++;
  }

  while(i <= mid)
  {
    b[k] = a[i];
    i++;
    k++;
  }

  while(j <= ub)
  {
    b[k] = a[j];
    j++;
    k++;
  }

  for(k = lb; k <= ub; k++)
    a[k] = b[k];
}

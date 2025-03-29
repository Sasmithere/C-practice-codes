#include <stdio.h>
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int** res, int* returnSize, int* sol, int solSize, int start) {
	// Add the current subset to the result
	res[*returnSize] = (int*)malloc(solSize * sizeof(int));
	for (int i = 0; i < solSize; i++) {
		res[*returnSize][i] = sol[i];

	}
	(*returnSize)++;

	// Generate all possible subsets
	for (int i = start; i < numsSize; i++) {
		sol[solSize] = nums[i];
		backtrack(nums, numsSize, res, returnSize, sol, solSize + 1, i + 1);
	}
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int maxSize = 1 << numsSize; // 2^numsSize
	int** res = (int**)malloc(maxSize * sizeof(int*));
	*returnColumnSizes = (int*)malloc(maxSize * sizeof(int));
	*returnSize = 0;

	int* sol = (int*)malloc(numsSize * sizeof(int));
	backtrack(nums, numsSize, res, returnSize, sol, 0, 0);

	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = i;
	}

	free(sol);
	return res;
}

int main() {
	int nums[] = {1, 2, 3};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize;
	int* returnColumnSizes;

	int** result = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

	// Print the result
	for (int i = 0; i < returnSize; i++) {
		printf("[");
		for (int j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d", result[i][j]);
			if (j < returnColumnSizes[i] - 1) {
				printf(", ");
			}
		}
		printf("]\n");
		free(result[i]);
	}

	free(result);
	free(returnColumnSizes);

	return 0;
}

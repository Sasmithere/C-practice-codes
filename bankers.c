#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

void bankersAlgorithm(int alloc[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int avail[MAX_RESOURCES]) {
    int n = MAX_PROCESSES;
    int m = MAX_RESOURCES;
    int f[MAX_PROCESSES] = {0};
    int ans[MAX_PROCESSES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
    int i, j, k, y, ind = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (j = 0; j < m; j++) {
        work[j] = avail[j];
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        work[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the safe sequence:\n");
    for (i = 0; i < n - 1; i++) {
        printf("P%d -> ", ans[i]);
    }
    printf("P%d\n", ans[n - 1]);
}

int main() {
    int alloc[MAX_PROCESSES][MAX_RESOURCES] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int avail[MAX_RESOURCES] = {3, 3, 2};

    bankersAlgorithm(alloc, max, avail);

    return 0;
}
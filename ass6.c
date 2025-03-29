#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int is_safe(int processes[], int available[], int maximum[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safe_seq[MAX_PROCESSES];

    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    int work[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < MAX_PROCESSES) {
        int found = 0;
        for (int p = 0; p < MAX_PROCESSES; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }
                if (j == MAX_RESOURCES) {
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[p][k];
                    }

                    safe_seq[count] = p;
                    finish[p] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if (!found) {
            printf("System is in unsafe state!\n");
            return 0;
        }
    }

    printf("System is in safe state.\n");
    printf("Safe sequence: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d ", safe_seq[i]);
    }
    printf("\n");

    return 1;
}

int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int available[] = {3, 3, 2};
    int maximum[MAX_PROCESSES][MAX_RESOURCES] = {{7, 5, 3}, {6, 4, 3}, {9, 0, 2}, {4, 6, 2}, {5, 3, 3}};
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    if (!is_safe(processes, available, maximum, allocation)) {
        return 1;
    }

    return 0;
}

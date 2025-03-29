#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

void optimalPageReplacement(int pages[MAX_PAGES], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int hit = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            int replaceIndex = INT_MIN;
            int farthestIndex = INT_MIN;

            for (int j = 0; j < MAX_FRAMES; j++) {
                int nextOccurrence = INT_MAX;

                for (int k = i + 1; k < n; k++) {
                    if (pages[k] == frames[j]) {
                        nextOccurrence = k;
                        break;
                    }
                }

                if (nextOccurrence > farthestIndex) {
                    farthestIndex = nextOccurrence;
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = currentPage;
            pageFaults++;
        }
    }

    printf("Page Faults using Optimal: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);

    optimalPageReplacement(pages, n);

    return 0;
}
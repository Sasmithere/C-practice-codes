#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

void lruPageReplacement(int pages[MAX_PAGES], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int pageFaults = 0;
    int counter[MAX_FRAMES] = {0};

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int hit = -1;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                hit = j;
                break;
            }
        }

        if (hit != -1) {
            counter[hit]++;
        } else {
            int replaceIndex = -1;

            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
                if (replaceIndex == -1 || counter[j] < counter[replaceIndex]) {
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = currentPage;
            counter[replaceIndex] = 1;
            pageFaults++;
        }
    }

    printf("Page Faults using LRU: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);

    lruPageReplacement(pages, n);

    return 0;
}
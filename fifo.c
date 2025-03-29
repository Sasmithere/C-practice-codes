#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

void fifoPageReplacement(int pages[MAX_PAGES], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int frameIndex = 0;
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
            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % MAX_FRAMES;
            pageFaults++;
        }
    }

    printf("Page Faults using FIFO: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);

    fifoPageReplacement(pages, n);

    return 0;
}
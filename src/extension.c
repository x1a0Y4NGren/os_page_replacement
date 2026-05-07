#include "extension.h"

#include <stdlib.h>

#include "algorithms.h"
#include "common.h"

/* Member D: extension experiments and optional improved algorithm. */

void generate_random_page_stream(int pages[], int n)
{
    int i;

    if (pages == 0 || n <= 0) {
        return;
    }

    for (i = 0; i < n; i++) {
        pages[i] = rand() % VIRTUAL_PAGE_COUNT;
    }
}

void generate_loop_page_stream(int pages[], int n)
{
    int i;
    int loop_pages[] = {0, 1, 2, 3, 4, 5, 2, 3};
    int loop_len = (int)(sizeof(loop_pages) / sizeof(loop_pages[0]));

    if (pages == 0 || n <= 0) {
        return;
    }

    for (i = 0; i < n; i++) {
        pages[i] = loop_pages[i % loop_len];
    }
}

double run_improved_algorithm(const int pages[], int n, int frame_count)
{
    /*
     * TODO(Member D): replace this placeholder with a real improved algorithm,
     * such as CLOCK or an adaptive LRU variant, and compare it with OPT/FIFO/LRU.
     */
    return run_lru(pages, n, frame_count);
}

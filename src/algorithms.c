#include "algorithms.h"

#include <limits.h>

/* Member B: implement OPT, FIFO and LRU here. */

static int find_page(const int frames[], int frame_count, int page)
{
    int i;

    for (i = 0; i < frame_count; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1;
}

static int first_empty_frame(const int frames[], int frame_count)
{
    int i;

    for (i = 0; i < frame_count; i++) {
        if (frames[i] == -1) {
            return i;
        }
    }
    return -1;
}

double run_opt(const int pages[], int n, int frame_count)
{
    int frames[32];
    int hits = 0;
    int i;

    if (pages == 0 || n <= 0 || frame_count <= 0) {
        return 0.0;
    }

    for (i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int hit_index = find_page(frames, frame_count, page);

        if (hit_index >= 0) {
            hits++;
        } else {
            int empty = first_empty_frame(frames, frame_count);
            int replace_index = empty;

            if (empty < 0) {
                int farthest_next_use = -1;
                int j;

                for (j = 0; j < frame_count; j++) {
                    int k;
                    int next_use = INT_MAX;

                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j]) {
                            next_use = k;
                            break;
                        }
                    }

                    if (next_use > farthest_next_use) {
                        farthest_next_use = next_use;
                        replace_index = j;
                    }
                }
            }

            frames[replace_index] = page;
        }
    }

    return (double)hits / (double)n;
}

double run_fifo(const int pages[], int n, int frame_count)
{
    int frames[32];
    int hits = 0;
    int next_replace = 0;
    int i;

    if (pages == 0 || n <= 0 || frame_count <= 0) {
        return 0.0;
    }

    for (i = 0; i < frame_count; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];

        if (find_page(frames, frame_count, page) >= 0) {
            hits++;
        } else {
            int empty = first_empty_frame(frames, frame_count);

            if (empty >= 0) {
                frames[empty] = page;
            } else {
                frames[next_replace] = page;
                next_replace = (next_replace + 1) % frame_count;
            }
        }
    }

    return (double)hits / (double)n;
}

double run_lru(const int pages[], int n, int frame_count)
{
    int frames[32];
    int last_used[32];
    int hits = 0;
    int i;

    if (pages == 0 || n <= 0 || frame_count <= 0) {
        return 0.0;
    }

    for (i = 0; i < frame_count; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int hit_index = find_page(frames, frame_count, page);

        if (hit_index >= 0) {
            hits++;
            last_used[hit_index] = i;
        } else {
            int empty = first_empty_frame(frames, frame_count);
            int replace_index = empty;

            if (empty < 0) {
                int oldest_time = INT_MAX;
                int j;

                for (j = 0; j < frame_count; j++) {
                    if (last_used[j] < oldest_time) {
                        oldest_time = last_used[j];
                        replace_index = j;
                    }
                }
            }

            frames[replace_index] = page;
            last_used[replace_index] = i;
        }
    }

    return (double)hits / (double)n;
}

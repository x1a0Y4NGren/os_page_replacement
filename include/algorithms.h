#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/* Member B: page replacement algorithm interfaces. */

double run_opt(const int pages[], int n, int frame_count);
double run_fifo(const int pages[], int n, int frame_count);
double run_lru(const int pages[], int n, int frame_count);

#endif

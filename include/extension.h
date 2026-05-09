#ifndef EXTENSION_H
#define EXTENSION_H

/* Member D: extension experiment interfaces. */

void generate_random_page_stream(int pages[], int n);
void generate_loop_page_stream(int pages[], int n);
double run_improved_algorithm(const int pages[], int n, int frame_count);
void run_extension_experiments(void);

#endif

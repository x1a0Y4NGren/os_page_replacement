#include "extension.h"

#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "common.h"


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
    int frames[MAX_FRAME_COUNT];
    int reference_bits[MAX_FRAME_COUNT];
    int hand = 0;
    int hits = 0;
    int i;

    if (pages == 0 || n <= 0 || frame_count <= 0 || frame_count > MAX_FRAME_COUNT) {
        return 0.0;
    }

    for (i = 0; i < frame_count; i++) {
        frames[i] = -1;
        reference_bits[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        int j;

        for (j = 0; j < frame_count; j++) {
            if (frames[j] == page) {
                reference_bits[j] = 1;
                hits++;
                found = 1;
                break;
            }
        }

        if (found) {
            continue;
        }

        while (1) {
            if (frames[hand] == -1 || reference_bits[hand] == 0) {
                frames[hand] = page;
                reference_bits[hand] = 1;
                hand = (hand + 1) % frame_count;
                break;
            }

            reference_bits[hand] = 0;
            hand = (hand + 1) % frame_count;
        }
    }

    return (double)hits / (double)n;
}

static void print_extension_table(const int pages[], int n)
{
    int frame_count;

    printf("Frame    OPT      FIFO     LRU      CLOCK\n");
    for (frame_count = MIN_FRAME_COUNT; frame_count <= MAX_FRAME_COUNT; frame_count++) {
        double opt = run_opt(pages, n, frame_count);
        double fifo = run_fifo(pages, n, frame_count);
        double lru = run_lru(pages, n, frame_count);
        double clock = run_improved_algorithm(pages, n, frame_count);

        printf("%-8d %.4f   %.4f   %.4f   %.4f\n",
               frame_count, opt, fifo, lru, clock);
    }
}

void run_extension_experiments(void)
{
    int pages[INSTRUCTION_COUNT];

    printf("\nExtension experiment: random page stream\n");
    generate_random_page_stream(pages, INSTRUCTION_COUNT);
    print_extension_table(pages, INSTRUCTION_COUNT);

    printf("\nExtension experiment: loop page stream\n");
    generate_loop_page_stream(pages, INSTRUCTION_COUNT);
    print_extension_table(pages, INSTRUCTION_COUNT);
}

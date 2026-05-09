#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "common.h"
#include "extension.h"
#include "sequence.h"

/* Member A: main program and module integration only. */

static void print_algorithm_table(const int pages[], int n)
{
    int frame_count;

    printf("Frame    OPT      FIFO     LRU\n");
    for (frame_count = MIN_FRAME_COUNT; frame_count <= MAX_FRAME_COUNT; frame_count++) {
        double opt = run_opt(pages, n, frame_count);
        double fifo = run_fifo(pages, n, frame_count);
        double lru = run_lru(pages, n, frame_count);

        printf("%-8d %.4f   %.4f   %.4f\n", frame_count, opt, fifo, lru);
    }
}

static void run_basic_experiment(double sequential_ratio)
{
    int instructions[INSTRUCTION_COUNT];
    int pages[INSTRUCTION_COUNT];

    generate_instruction_sequence(instructions, INSTRUCTION_COUNT, sequential_ratio);
    convert_to_page_stream(instructions, pages, INSTRUCTION_COUNT);

    printf("\nSequential ratio: %.0f%%\n", sequential_ratio * 100.0);
    print_algorithm_table(pages, INSTRUCTION_COUNT);
}

static void run_extension_preview(void)
{
    run_extension_experiments();
}

int main(void)
{
    srand(1);

    printf("Page Replacement Experiment\n");
    printf("Instruction count: %d, virtual pages: %d, frames: %d-%d\n",
           INSTRUCTION_COUNT, VIRTUAL_PAGE_COUNT, MIN_FRAME_COUNT, MAX_FRAME_COUNT);

    /* Required default experiment: 50% sequential execution. */
    run_basic_experiment(DEFAULT_SEQUENTIAL_RATIO);

    /* Reserved experiment entries for comparison in the report. */
    run_basic_experiment(0.25);
    run_basic_experiment(0.75);

    /* Extension entry. Keep concise so default output remains report-friendly. */
    run_extension_preview();

    return 0;
}

#ifndef COMMON_H
#define COMMON_H

/* Member A: shared constants used by all modules. */

#define INSTRUCTION_COUNT 320
#define VIRTUAL_PAGE_COUNT 32
#define INSTRUCTIONS_PER_PAGE 10
#define MIN_FRAME_COUNT 4
#define MAX_FRAME_COUNT 32

#define DEFAULT_SEQUENTIAL_RATIO 0.50

typedef struct {
    double opt;
    double fifo;
    double lru;
} HitRateRow;

#endif

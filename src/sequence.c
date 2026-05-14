#include "sequence.h"

#include <stdlib.h>

#include "common.h"


static int clamp_instruction(int value)
{
    if (value < 0) {
        return 0;
    }
    if (value >= INSTRUCTION_COUNT) {
        return INSTRUCTION_COUNT - 1;
    }
    return value;
}

static int random_between(int low, int high)
{
    if (high < low) {
        return clamp_instruction(low);
    }
    return low + rand() % (high - low + 1);
}

void generate_instruction_sequence(int instructions[], int n, double sequential_ratio)
{
    int count = 0;
    int current;
    int sequential_target;
    int sequential_used = 0;
    int front_target;
    int front_used = 0;
    int back_target;
    int back_used = 0;

    if (instructions == 0 || n <= 0) {
        return;
    }

    if (sequential_ratio < 0.0) {
        sequential_ratio = 0.0;
    }
    if (sequential_ratio > 1.0) {
        sequential_ratio = 1.0;
    }

    sequential_target = (int)(n * sequential_ratio + 0.5);
    if (sequential_target > n - 1) {
        sequential_target = n - 1;
    }
    front_target = (n - sequential_target) / 2;
    back_target = n - sequential_target - front_target;

    current = rand() % INSTRUCTION_COUNT;

    while (count < n) {
        int must_use_sequential = sequential_used < sequential_target &&
                                  (front_used >= front_target && back_used >= back_target);
        int can_use_sequential = count > 0 && sequential_used < sequential_target;
        int choose_sequential = 0;

        if (can_use_sequential) {
            int remaining = n - count;
            int sequential_remaining = sequential_target - sequential_used;
            choose_sequential = must_use_sequential ||
                                (rand() % remaining < sequential_remaining);
        }

        if (choose_sequential) {
            current = (current + 1) % INSTRUCTION_COUNT;
            sequential_used++;
        } else {
            int choose_front;

            if (front_used >= front_target) {
                choose_front = 0;
            } else if (back_used >= back_target) {
                choose_front = 1;
            } else {
                choose_front = rand() % 2;
            }

            if (choose_front && current > 0) {
                current = random_between(0, current);
                front_used++;
            } else if (current + 2 < INSTRUCTION_COUNT) {
                current = random_between(current + 2, INSTRUCTION_COUNT - 1);
                back_used++;
            } else {
                current = rand() % INSTRUCTION_COUNT;
                if (front_used < front_target) {
                    front_used++;
                } else {
                    back_used++;
                }
            }
        }

        instructions[count++] = current;
    }
}

void convert_to_page_stream(const int instructions[], int pages[], int n)
{
    int i;

    if (instructions == 0 || pages == 0 || n <= 0) {
        return;
    }

    for (i = 0; i < n; i++) {
        int instruction = clamp_instruction(instructions[i]);
        pages[i] = instruction / INSTRUCTIONS_PER_PAGE;
    }
}

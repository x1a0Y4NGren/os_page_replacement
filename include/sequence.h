#ifndef SEQUENCE_H
#define SEQUENCE_H

/* Member C: instruction sequence generation interfaces. */

void generate_instruction_sequence(int instructions[], int n, double sequential_ratio);
void convert_to_page_stream(const int instructions[], int pages[], int n);

#endif

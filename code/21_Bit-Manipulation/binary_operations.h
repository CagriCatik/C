#ifndef BINARY_OPERATIONS_H
#define BINARY_OPERATIONS_H

#include <stdint.h>

// Function prototypes
void decimal_to_binary(uint32_t n, char *binary_representation);
uint32_t binary_to_decimal(const char *binary_representation);
void perform_bitwise_operations(uint32_t x, uint32_t y);

#endif // BINARY_OPERATIONS_H

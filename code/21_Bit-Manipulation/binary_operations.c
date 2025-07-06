#include <stdio.h>
#include <string.h>
#include "binary_operations.h"

// Convert decimal to binary string
void decimal_to_binary(uint32_t n, char *binary_representation) {
    for (int i = 31; i >= 0; i--) {
        binary_representation[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binary_representation[32] = '\0'; // Null-terminate the string
}

// Convert binary string to decimal
uint32_t binary_to_decimal(const char *binary_representation) {
    uint32_t result = 0;
    int len = strlen(binary_representation);
    for (int i = 0; i < len; i++) {
        if (binary_representation[i] == '1') {
            result |= (1 << (len - i - 1));
        }
    }
    return result;
}

// Perform common bitwise operations
void perform_bitwise_operations(uint32_t x, uint32_t y) {
    char binary_x[33], binary_y[33];
    decimal_to_binary(x, binary_x);
    decimal_to_binary(y, binary_y);

    printf("x: %s\n", binary_x);
    printf("y: %s\n", binary_y);

    printf("x & y: ");
    decimal_to_binary(x & y, binary_x);
    printf("%s\n", binary_x);

    printf("x | y: ");
    decimal_to_binary(x | y, binary_x);
    printf("%s\n", binary_x);

    printf("x ^ y: ");
    decimal_to_binary(x ^ y, binary_x);
    printf("%s\n", binary_x);

    printf("~x: ");
    decimal_to_binary(~x, binary_x);
    printf("%s\n", binary_x);

    printf("x << 2: ");
    decimal_to_binary(x << 2, binary_x);
    printf("%s\n", binary_x);

    printf("x >> 2: ");
    decimal_to_binary(x >> 2, binary_x);
    printf("%s\n", binary_x);
}

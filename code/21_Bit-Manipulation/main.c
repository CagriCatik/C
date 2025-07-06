#include <stdio.h>
#include <stdlib.h>
#include "binary_operations.h"
#include "bit_fields.h"

int main() {
    printf("=== Bit Manipulation Utility ===\n");

    // Convert Decimal to Binary
    uint32_t number = 105;
    char binary[33];
    decimal_to_binary(number, binary);
    printf("Decimal %u to Binary: %s\n", number, binary);

    // Convert Binary to Decimal
    const char *binary_string = "01101001";
    printf("Binary %s to Decimal: %u\n", binary_string, binary_to_decimal(binary_string));

    // Perform Bitwise Operations
    printf("\n--- Bitwise Operations ---\n");
    perform_bitwise_operations(170, 204);

    // Demonstrate Bit Fields
    printf("\n--- Bit Fields ---\n");
    demonstrate_bit_fields();

    return 0;
}

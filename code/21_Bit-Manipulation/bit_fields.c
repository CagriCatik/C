#include <stdio.h>
#include "bit_fields.h"

// Define a struct with bit fields
struct PackedData {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int value : 6;
};

void demonstrate_bit_fields() {
    struct PackedData data = {1, 0, 15}; // Initialize with sample values

    printf("Flag1: %u, Flag2: %u, Value: %u\n",
           data.flag1, data.flag2, data.value);

    // Update bit field values
    data.flag1 = 0;
    data.flag2 = 1;
    data.value = 63;

    printf("Updated - Flag1: %u, Flag2: %u, Value: %u\n",
           data.flag1, data.flag2, data.value);
}

#include <stdio.h>

int main() {
    // Integer data type
    int integerNumber = 10;
    printf("Integer Number: %d\n", integerNumber);

    // Floating-point data types
    float floatValue = 3.14;
    printf("Float Value: %.2f\n", floatValue);

    double doubleValue = 12345.6789;
    printf("Double Value: %.4lf\n", doubleValue);

    // Character data type
    char grade = 'A';
    printf("Grade: %c\n", grade);

    // Boolean data type
    _Bool isTrue = 1;
    _Bool isFalse = 0;
    printf("Is True: %d\n", isTrue);
    printf("Is False: %d\n", isFalse);

    // Hexadecimal and Scientific Notation
    int hexValue = 0xFF;
    float scientificValue = 1.5e3;
    printf("Hexadecimal Value: %X\n", hexValue);
    printf("Scientific Value: %.2f\n", scientificValue);

    // Additional Data Types
    short int shortNumber = 100;
    long int longNumber = 1000000000;
    printf("Short Number: %d\n", shortNumber);
    printf("Long Number: %ld\n", longNumber);

    unsigned int positiveNumber = 100;
    printf("Unsigned Positive Number: %u\n", positiveNumber);

    signed int temperature = -10;
    printf("Temperature: %d\n", temperature);

    return 0;
}

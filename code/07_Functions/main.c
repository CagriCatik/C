#include <stdio.h>
#include "functions.h"

int main() {
    int num1 = 5;
    int num2 = 7;
    int sum_result = sum(num1, num2);
    printf("The sum of %d and %d is %d\n", num1, num2, sum_result);

    int product_result = product(num1, num2);
    printf("The product of %d and %d is %d\n", num1, num2, product_result);

    return 0;
}

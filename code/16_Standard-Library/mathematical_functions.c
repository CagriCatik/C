#include <stdio.h>
#include <math.h>

int main() {
    double num = 2.5;
    double result;

    result = sqrt(num);
    printf("Square root of %.2f: %.2f\n", num, result);

    result = pow(num, 3);
    printf("%.2f raised to the power of 3: %.2f\n", num, result);

    result = log(num);
    printf("Natural logarithm of %.2f: %.2f\n", num, result);

    return 0;
}

#include <stdio.h>
#include "calculator.h"

int main() {
    int num1, num2;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    printf("Addition result: %d\n", add(num1, num2));
    printf("Subtraction result: %d\n", subtract(num1, num2));
    
    return 0;
}

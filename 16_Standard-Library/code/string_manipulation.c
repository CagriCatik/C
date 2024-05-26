#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, ";
    char str2[] = "world!";
    char result[50];

    strcat(str1, str2);
    printf("%s\n", str1);

    strcpy(result, str1);
    printf("%s\n", result);

    printf("Length of result string: %lu\n", strlen(result));

    return 0;
}

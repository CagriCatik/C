#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[255];

    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    fscanf(fp, "%s", buffer);
    printf("Data from file: %s\n", buffer);
    fclose(fp);

    return 0;
}

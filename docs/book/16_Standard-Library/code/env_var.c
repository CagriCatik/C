#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get the value of the PATH environment variable
    char *path = getenv("PATH");

    if (path != NULL) {
        printf("Value of the PATH environment variable: %s\n", path);
    } else {
        printf("PATH environment variable is not set.\n");
    }

    return 0;
}

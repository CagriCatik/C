#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file;
    int errnum;

    file = fopen("nonexistentfile.txt", "r");
    if (file == NULL) {
        errnum = errno;
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
        return 1;
    }

    // File processing code here

    fclose(file);
    return 0;
}

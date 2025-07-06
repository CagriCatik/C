#include <stdio.h>
#include "display.h"

void displaySpeed(int speed) {
    printf("Current Speed: %d km/h\n", speed);
    
    // Log the speed to a file
    FILE *logFile = fopen("speed_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%d,NORMAL\n", speed);
        fclose(logFile);
    }
}

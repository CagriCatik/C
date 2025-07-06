#include <stdio.h>
#include "alert_system.h"

int checkSpeedLimit(int speed, int limit) {
    return speed > limit;
}

void triggerAlert(int speed) {
    printf("ALERT: Overspeeding! Current speed is %d km/h.\n", speed);
    
    // Log the alert to a file
    FILE *logFile = fopen("speed_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%d,ALERT\n", speed);
        fclose(logFile);
    }
}

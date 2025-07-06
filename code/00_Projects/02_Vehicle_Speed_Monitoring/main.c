#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include "speed_sensor.h"
#include "alert_system.h"
#include "display.h"

#define SPEED_LIMIT 80 // Speed limit in km/h

int main(void) {
    int currentSpeed;

    printf("Vehicle Speed Monitoring System Initialized.\n");
    printf("Speed Limit: %d km/h\n", SPEED_LIMIT);

    while (1) {
        currentSpeed = getSpeed();
        displaySpeed(currentSpeed);

        if (checkSpeedLimit(currentSpeed, SPEED_LIMIT)) {
            triggerAlert(currentSpeed);
        }

        sleep(2); // Simulate real-time system with a delay
    }

    return 0;
}

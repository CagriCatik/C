#include <stdlib.h>
#include "speed_sensor.h"

// Simulates vehicle speed in the range of 0 to 120 km/h
int getSpeed(void) {
    return rand() % 121; // Random speed between 0 and 120
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> // Include time.h for time()

// Function to read sensor data
int readSensorData(int analogPin) {
    // In a real scenario, this function would read analog data from the specified pin
    // For the sake of example, let's generate random data
    return rand() % 100; // Simulating temperature data (0 to 99)
}

int main() {
    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Analog pin connected to the sensor
    int analogPin = 0; // Assuming sensor connected to analog pin 0

    while (1) {
        // Read sensor data
        int sensorData = readSensorData(analogPin);

        // Print sensor data
        printf("Sensor Data: %d\n", sensorData);

        // Wait for some time before reading again (e.g., 1 second)
        sleep(0.1);
    }

    return 0;
}

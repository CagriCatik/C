#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep function

// Kalman Filter Parameters
#define Q 0.01 // Process noise covariance
#define R 0.1  // Measurement noise covariance
#define P 1    // Estimate error covariance

// Initial State
float x_hat = 0;      // Initial estimate
float P_estimate = P; // Initial estimate covariance

// Function to generate synthetic measurement data
float generate_measurement() {
    // Simulate sensor data by returning a random value (you can replace this with actual sensor readings)
    return (float)rand() / RAND_MAX * 10; // Generates a random float between 0 and 10
}

// Kalman filter update step
void kalman_update(float z) {
    // Prediction update
    float x_pred = x_hat;
    float P_pred = P_estimate + Q;

    // Measurement update
    float K = P_pred / (P_pred + R);
    x_hat = x_pred + K * (z - x_pred);
    P_estimate = (1 - K) * P_pred;

    // Output the updated state estimate
    printf("Measurement: %f, Updated State Estimate: %f\n", z, x_hat);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Simulate streaming sensor data and perform Kalman filtering
    while (1) { // Continuously stream data
        float measurement = generate_measurement();
        kalman_update(measurement);

        // Sleep for 1 second to simulate real-time streaming
        sleep(1);
    }

    return 0;
}

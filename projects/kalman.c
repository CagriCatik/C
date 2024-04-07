#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Kalman Filter Parameters
#define Q 0.01 // Process noise covariance
#define R 0.1  // Measurement noise covariance
#define P 1    // Estimate error covariance

// Initial State
float x_hat = 0;      // Initial estimate
float P_estimate = P; // Initial estimate covariance

// Generate Synthetic Data
float generate_measurement() {
    // Generate a random measurement (you can replace this with actual sensor readings)
    return (float)rand() / RAND_MAX * 10; // Generates a random float between 0 and 10
}

// Update Step
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

    // Generate synthetic data and perform Kalman filtering
    for (int i = 0; i < 10; i++) { // Generate 10 data points
        float measurement = generate_measurement();
        kalman_update(measurement);
    }

    return 0;
}

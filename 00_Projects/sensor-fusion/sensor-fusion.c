#include <stdio.h>
#include <stdlib.h>

// Define Kalman filter parameters
#define STATE_DIM 2   // Dimension of state vector [theta, theta_dot]
#define MEAS_DIM 2    // Dimension of measurement vector [omega, v]

// Define system matrices
float A[STATE_DIM][STATE_DIM] = {{1, 1}, {0, 1}};  // State transition matrix
float B[STATE_DIM] = {0, 1};                        // Control input matrix
float H[MEAS_DIM][STATE_DIM] = {{1, 0}, {0, 1}};    // Measurement matrix
float Q[STATE_DIM][STATE_DIM] = {{0.1, 0}, {0, 0.1}}; // Process noise covariance
float R[MEAS_DIM][MEAS_DIM] = {{0.1, 0}, {0, 0.1}};   // Measurement noise covariance
float P[STATE_DIM][STATE_DIM] = {{1, 0}, {0, 1}};      // Initial estimate covariance

// Kalman filter variables
float x_hat[STATE_DIM] = {0};      // State estimate
float P_hat[STATE_DIM][STATE_DIM]; // Covariance estimate

// Function prototypes
void predict(float u);
void update(float z1, float z2);

int main() {
    // Simulated inputs (angular velocity and linear velocity)
    float omega = 0.1; // Angular velocity from IMU
    float v = 0.2;     // Linear velocity from wheel encoders

    // Simulate control input from angular velocity
    float u = omega;

    // Predict and update using wheel encoder measurement
    predict(u);
    update(omega, v);

    // Print estimated state
    printf("Estimated theta: %.2f\n", x_hat[0]);
    printf("Estimated theta_dot: %.2f\n", x_hat[1]);

    return 0;
}

// Kalman filter prediction step
void predict(float u) {
    // Predicted state estimate: x_hat = A * x_hat + B * u
    float x_pred[STATE_DIM] = {0};
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            x_pred[i] += A[i][j] * x_hat[j];
        }
        x_pred[i] += B[i] * u;
    }

    // Predicted estimate covariance: P_hat = A * P * A^T + Q
    float P_pred[STATE_DIM][STATE_DIM] = {0};
    float temp[STATE_DIM][STATE_DIM] = {0};
    // Calculate A * P
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            for (int k = 0; k < STATE_DIM; k++) {
                temp[i][j] += A[i][k] * P[k][j];
            }
        }
    }
    // Calculate (A * P) * A^T
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            for (int k = 0; k < STATE_DIM; k++) {
                P_pred[i][j] += temp[i][k] * A[j][k];
            }
        }
    }
    // Add process noise covariance
    for (int i = 0; i < STATE_DIM; i++) {
        P_pred[i][i] += Q[i][i];
    }

    // Update state estimate and covariance
    for (int i = 0; i < STATE_DIM; i++) {
        x_hat[i] = x_pred[i];
        for (int j = 0; j < STATE_DIM; j++) {
            P_hat[i][j] = P_pred[i][j];
        }
    }
}

// Kalman filter update step
void update(float z1, float z2) {
    // Calculate innovation: y = z - H * x_hat
    float y[MEAS_DIM] = {0};
    for (int i = 0; i < MEAS_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            y[i] += H[i][j] * x_hat[j];
        }
        y[i] = z1 - y[i];
    }

    // Calculate innovation covariance: S = H * P * H^T + R
    float S[MEAS_DIM][MEAS_DIM] = {0};
    float temp[MEAS_DIM][STATE_DIM] = {0};
    // Calculate H * P
    for (int i = 0; i < MEAS_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            for (int k = 0; k < STATE_DIM; k++) {
                temp[i][j] += H[i][k] * P_hat[k][j];
            }
        }
    }
    // Calculate (H * P) * H^T
    for (int i = 0; i < MEAS_DIM; i++) {
        for (int j = 0; j < MEAS_DIM; j++) {
            for (int k = 0; k < STATE_DIM; k++) {
                S[i][j] += temp[i][k] * H[j][k];
            }
        }
    }
    // Add measurement noise covariance
    for (int i = 0; i < MEAS_DIM; i++) {
        S[i][i] += R[i][i];
    }

    // Calculate Kalman gain: K = P * H^T * S^-1
    float K[STATE_DIM][MEAS_DIM] = {0};
    // Calculate P * H^T
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < MEAS_DIM; j++) {
            for (int k = 0; k < MEAS_DIM; k++) {
                K[i][j] += P_hat[i][k] * H[k][j];
            }
        }
    }
    // Calculate K * S^-1
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < MEAS_DIM; j++) {
            K[i][j] /= S[j][j];
        }
    }

    // Update state estimate: x_hat = x_hat + K * y
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < MEAS_DIM; j++) {
            x_hat[i] += K[i][j] * y[j];
        }
    }

    // Update covariance estimate: P = (I - K * H) * P
    float I[STATE_DIM][STATE_DIM] = {{1, 0}, {0, 1}}; // Identity matrix
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            for (int k = 0; k < MEAS_DIM; k++) {
                I[i][j] -= K[i][k] * H[k][j];
            }
        }
    }
    float P_temp[STATE_DIM][STATE_DIM] = {0};
    // Calculate (I - K * H) * P
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            for (int k = 0; k < STATE_DIM; k++) {
                P_temp[i][j] += I[i][k] * P_hat[k][j];
            }
        }
    }
    // Update covariance estimate
    for (int i = 0; i < STATE_DIM; i++) {
        for (int j = 0; j < STATE_DIM; j++) {
            P_hat[i][j] = P_temp[i][j];
        }
    }
}

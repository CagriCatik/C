#include <stdio.h>
#include "gearbox.h"

// Current state of the gearbox
static GearState current_gear;

// Initialize the gearbox to the Park state
void gearbox_init() {
    current_gear = GEAR_PARK;
    printf("Gearbox initialized to: PARK\n");
}

// Transition to a new state with validation
void gearbox_transition(GearState next_state) {
    switch (current_gear) {
        case GEAR_PARK:
            if (next_state == GEAR_REVERSE || next_state == GEAR_NEUTRAL) {
                current_gear = next_state;
            } else {
                printf("Invalid transition from PARK to %d\n", next_state);
            }
            break;

        case GEAR_REVERSE:
            if (next_state == GEAR_PARK || next_state == GEAR_NEUTRAL) {
                current_gear = next_state;
            } else {
                printf("Invalid transition from REVERSE to %d\n", next_state);
            }
            break;

        case GEAR_NEUTRAL:
            if (next_state == GEAR_DRIVE || next_state == GEAR_REVERSE || next_state == GEAR_PARK) {
                current_gear = next_state;
            } else {
                printf("Invalid transition from NEUTRAL to %d\n", next_state);
            }
            break;

        case GEAR_DRIVE:
            if (next_state == GEAR_NEUTRAL || next_state == GEAR_MANUAL) {
                current_gear = next_state;
            } else {
                printf("Invalid transition from DRIVE to %d\n", next_state);
            }
            break;

        case GEAR_MANUAL:
            if (next_state == GEAR_DRIVE) {
                current_gear = next_state;
            } else {
                printf("Invalid transition from MANUAL to %d\n", next_state);
            }
            break;

        default:
            printf("Unknown state transition\n");
    }

    // Print the new state
    switch (current_gear) {
        case GEAR_PARK:
            printf("Gear shifted to: PARK\n");
            break;
        case GEAR_REVERSE:
            printf("Gear shifted to: REVERSE\n");
            break;
        case GEAR_NEUTRAL:
            printf("Gear shifted to: NEUTRAL\n");
            break;
        case GEAR_DRIVE:
            printf("Gear shifted to: DRIVE\n");
            break;
        case GEAR_MANUAL:
            printf("Gear shifted to: MANUAL\n");
            break;
    }
}

// Simulate gearbox operation
void gearbox_run() {
    gearbox_transition(GEAR_REVERSE);  // Example transition to REVERSE
    gearbox_transition(GEAR_NEUTRAL); // Transition to NEUTRAL
    gearbox_transition(GEAR_DRIVE);   // Transition to DRIVE
    gearbox_transition(GEAR_MANUAL);  // Switch to MANUAL mode
    gearbox_transition(GEAR_DRIVE);   // Back to DRIVE
    gearbox_transition(GEAR_NEUTRAL); // Transition to NEUTRAL
    gearbox_transition(GEAR_PARK);    // Transition to PARK
}

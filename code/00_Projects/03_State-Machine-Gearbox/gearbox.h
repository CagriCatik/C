#ifndef GEARBOX_H
#define GEARBOX_H

// Enum to define gearbox states
typedef enum {
    GEAR_PARK,
    GEAR_REVERSE,
    GEAR_NEUTRAL,
    GEAR_DRIVE,
    GEAR_MANUAL
} GearState;

// Function prototypes
void gearbox_init();
void gearbox_transition(GearState next_state);
void gearbox_run();

#endif // GEARBOX_H

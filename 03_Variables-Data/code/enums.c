#include <stdio.h>

// Define an enum for primary colors
enum PrimaryColor { RED, YELLOW, BLUE };

// Define an enum for directions
enum Direction { UP, DOWN, LEFT = 10, RIGHT };

int main() {
    // Declare enum variables
    enum PrimaryColor myColor, yourColor;

    // Assign values to the enum variables
    myColor = RED;
    yourColor = BLUE;

    printf("myColor value: %d\n", myColor); // Prints "myColor value: 0"
    printf("yourColor value: %d\n", yourColor); // Prints "yourColor value: 2"

    // Compare enum values
    if (myColor == RED) {
        printf("myColor is red\n");
    } else if (myColor > YELLOW) {
        printf("myColor is blue\n");
    }

    // Use enum in a switch statement
    switch (myColor) {
        case RED:
            printf("Red is a primary color\n");
            break;
        case YELLOW:
            printf("Yellow is a primary color\n");
            break;
        case BLUE:
            printf("Blue is a primary color\n");
            break;
        default:
            printf("Unknown color\n");
            break;
    }

    // Declare and assign character variables
    char myChar = 'A';
    char newline = '\n';

    printf("%c\n", myChar); // Prints "A"
    printf("This will be on a new line.\n");

    // Assign character using ASCII value
    char asciiChar = 65;
    printf("%c\n", asciiChar); // Prints "A"

    return 0;
}
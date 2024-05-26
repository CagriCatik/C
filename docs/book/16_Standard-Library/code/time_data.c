#include <stdio.h>
#include <time.h>

int main() {
    time_t currentTime;
    struct tm *localTime;
    char dateTimeString[100];

    // Get the current time
    currentTime = time(NULL);

    // Convert current time to local time
    localTime = localtime(&currentTime);

    // Format the date and time
    strftime(dateTimeString, sizeof(dateTimeString), "%Y-%m-%d %H:%M:%S", localTime);

    // Print the formatted date and time
    printf("Current date and time: %s\n", dateTimeString);

    return 0;
}

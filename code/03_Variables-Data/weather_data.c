#include <stdio.h>

// Define a structure to hold weather data
struct WeatherData {
    float temperature;
    float humidity;
    float windSpeed;
    char weatherCondition;
    _Bool isRaining;
};

int main() {
    // Declare a variable of type struct WeatherData
    struct WeatherData currentWeather;

    // Simulate data collection
    currentWeather.temperature = 24.5;
    currentWeather.humidity = 65.2;
    currentWeather.windSpeed = 10.3;
    currentWeather.weatherCondition = 'C'; // 'C' for Clear
    currentWeather.isRaining = 0; // Not raining

    // Display collected data
    printf("Current Weather Conditions:\n");
    printf("Temperature: %.1f°C\n", currentWeather.temperature);
    printf("Humidity: %.1f%%\n", currentWeather.humidity);
    printf("Wind Speed: %.1f km/h\n", currentWeather.windSpeed);

    // Interpret weather condition
    switch(currentWeather.weatherCondition) {
        case 'C':
            printf("Weather Condition: Clear sky\n");
            break;
        case 'R':
            printf("Weather Condition: Rainy\n");
            break;
        case 'S':
            printf("Weather Condition: Snowy\n");
            break;
        default:
            printf("Weather Condition: Unknown\n");
    }

    // Check if it's raining
    if (currentWeather.isRaining) {
        printf("It's currently raining.\n");
    } else {
        printf("It's not raining at the moment.\n");
    }

    return 0;
}

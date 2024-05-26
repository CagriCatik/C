#include <stdio.h>
#include <string.h>

// Define a structure to represent a person
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    // Declare a variable of type struct Person
    struct Person person1;

    // Initialize the fields of person1
    strcpy(person1.name, "John");
    person1.age = 30;
    person1.height = 5.9;

    // Print out the information of person1
    printf("Person 1\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f\n", person1.height);

    // Declare and initialize another person using a compound literal
    struct Person person2 = {"Alice", 25, 5.6};

    // Print out the information of person2
    printf("\nPerson 2\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    printf("Height: %.2f\n", person2.height);

    return 0;
}

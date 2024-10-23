#include <stdio.h>

// Define the structure for a student
struct Student {
    char name[50];
    int id;
    int age;
};

int main() {
    // Create a variable of type Student
    struct Student student1;

    // Assign values to the student's members
    strcpy(student1.name, "John Doe");
    student1.id = 12345;
    student1.age = 18;

    // Print the student's information
    printf("Student Name: %s\n", student1.name);
    printf("Student ID: %d\n", student1.id);
    printf("Student Age: %d\n", student1.age);

    return 0;
}
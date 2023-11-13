#include <stdio.h>
#include <stdlib.h>

// Структура, що представляє студента
struct Student {
    char name[50];
    char surname[50];
    int age;
};

// Функція для виведення інформації про студентів
void displayStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Surname: %s\n", students[i].surname);
        printf("Age: %d\n", students[i].age);
    }
}

int main() {
    int numStudents;
    int choice;
    int I = 0;

    // Виділення пам'яті для зберігання інформації про студентів
    struct Student *students;

    printf("How many students are in your group -> ");
    scanf("%d", &numStudents);

    // Перевірка на валідну кількість студентів
    if (numStudents <= 0) {
        printf("Invalid number of students. Exiting program.\n");
        return 1;
    }

    students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    do {
        // Меню вибору
        printf("\nMenu:\n");
        printf("1. Enter student information\n");
        printf("2. Display all students\n");
        printf("3. Exit\n");
        printf("Enter your choice -> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Введення інформації про студентів
                if(I < numStudents) {
                    printf("\nEnter name -> ");
                    scanf("%s", students[I].name);

                    printf("Enter surname -> ");
                    scanf("%s", students[I].surname);

                    printf("Enter age -> ");
                    scanf("%d", &students[I].age);
                    I++;
                }
                else
                    printf("The list is full.\n");
                break;

            case 2:
                // Виведення інформації про студентів
                if (numStudents > 0) {
                    displayStudents(students, I);
                } else {
                    printf("No student information available. Enter information first.\n");
                }
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    // Звільнення виділеної пам'яті
    free(students);

    return 0;
}
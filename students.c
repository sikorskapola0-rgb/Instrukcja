#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

// List all students
void list_students(struct student_t *students, int count)
{
    if (count == 0)
    {
        printf("No students available.\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Album no.: %d | Name: %s | Grade: %d\n",
               students[i].album, students[i].name, students[i].grade);
    }
}

// Add a new student
/* We are using double pointer to modify the students array*/
void add_student(struct student_t **students, int *count)
{
    *students = realloc(*students, (*count + 1) * sizeof(struct student_t));
    if (*students == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    struct student_t *new_student = &(*students)[*count];

    printf("Enter student album no.: ");
    scanf("%d", &new_student->album);

    printf("Enter student name: ");
    scanf(" %s", new_student->name);

    printf("Enter student grade: ");
    scanf("%d", &new_student->grade);

    (*count)++;
    printf("Student added successfully.\n");
}

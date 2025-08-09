#include "teacher.h"
#include "sms.h"
#include "handle-csv.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void add_teacher() {
    teachers=csv_read_teacher("teacher.csv", &teacher_count);

    if (teacher_count >= 100) {
        printf("Cannot add more teachers.\n");
        return;
    }

    Teacher new_teacher;

    printf("Please enter the teacher's name: ");
    fgets(input, sizeof(input), stdin);
    Empty_entry(input);
    strcpy(new_teacher.name, input);
    new_teacher.name[strcspn(new_teacher.name, "\n")] = '\0';

    printf("Please enter the teacher's ID (or press Enter to auto-generate): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (is_blank(input)) {
        new_teacher.id = (teacher_count > 0) ? teachers[teacher_count - 1].id + 1 : 1;
    } else {
        new_teacher.id = atoi(input);
    }

    if (is_duplicate_teacher_id(new_teacher.id)) {
        printf("This ID is already taken.\n");
        return;
    }

    int count = 0;
    printf("Enter number of courses: ");
    fgets(input, sizeof(input), stdin);
    count = atoi(input);
    while (count <= 0) {
        printf("Teacher must have at least one course registered. Enter number of courses: ");
        fgets(input, sizeof(input), stdin);
        count = atoi(input);
    }
    new_teacher.course_count = count;

    for (int i = 0; i < new_teacher.course_count; i++) {
        printf("Course %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        Empty_entry(input);
        strcpy(new_teacher.courses[i], input);
        new_teacher.courses[i][strcspn(new_teacher.courses[i], "\n")] = '\0';
    }

    printf("Teacher added successfully.\n");
    csv_write_teacher("teacher.csv", new_teacher);
}

void read_teacher() 
{
    teachers=csv_read_teacher("teacher.csv",&teacher_count);
    if (teacher_count == 0)
    {
        printf("No teachers added yet\n");
    }
    for (int i = 0; i < teacher_count; i++) {
        printf("\nTeacher %d:\n", i + 1);
        printf("Name    : %s\n", teachers[i].name);
        printf("ID      : %d\n", teachers[i].id);
        printf("Courses : ");
        for (int j = 0; j < teachers[i].course_count; j++)
         {
            if (strlen(teachers[i].courses[j]) > 0)
            {
            printf("%s ", teachers[i].courses[j]);
        }
        }
        printf("\n-------------------------------------------\n");
    }
}

void update_teacher() {
    teachers=csv_read_teacher("teacher.csv", &teacher_count);

    int target_id;
    printf("Enter the ID of the teacher to update: ");
    fgets(input, sizeof(input), stdin);
    Empty_entry(input);
    target_id = atoi(input);

    int found = -1;
    for (int i = 0; i < teacher_count; i++) {
        if (teachers[i].id == target_id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("No teacher found with ID %d.\n", target_id);
        return;
    }

    printf("\nWhat would you like to update?\n1. Name\n2. ID\n3. Courses\nChoice: ");
    int choice;
    fgets(input, sizeof(input), stdin);
    Empty_entry(input);
    choice = atoi(input);

    switch (choice) {
        case 1: {
            printf("Enter new name: ");
            fgets(teachers[found].name, sizeof(teachers[found].name), stdin);
            teachers[found].name[strcspn(teachers[found].name, "\n")] = '\0';
            break;
        }
        case 2: {
            printf("Enter new ID: ");
            int new_id;
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            if (is_blank(input)) {
                new_id = (teacher_count > 0) ? teachers[teacher_count - 1].id + 1 : 1;
            } else {
                new_id = atoi(input);
            }
            if (is_duplicate_teacher_id(new_id)) {
                printf("This ID is already taken.\n");
                return;
            }
            teachers[found].id = new_id;
            break;
        }
        case 3: {
            printf("Enter new number of courses: ");
            int new_count = 0;
            fgets(input, sizeof(input), stdin);
            new_count = atoi(input);
            while (new_count <= 0) {
                printf("Teacher must have at least one course. Enter number of courses: ");
                fgets(input, sizeof(input), stdin);
                new_count = atoi(input);
            }
            teachers[found].course_count = new_count;

            for (int i = 0; i < new_count; i++) {
                printf("Course %d: ", i + 1);
                fgets(input, sizeof(input), stdin);
                Empty_entry(input);
                strcpy(teachers[found].courses[i], input);
                teachers[found].courses[i][strcspn(teachers[found].courses[i], "\n")] = '\0';
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            return;
    }

    FILE *file = fopen("teacher.csv", "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fclose(file);

    for (int i = 0; i < teacher_count; i++) {
        csv_write_teacher("teacher.csv", teachers[i]);
    }

    printf("Teacher information updated successfully.\n");
}

void delete_teacher() {
    teachers=csv_read_teacher("teacher.csv", &teacher_count);

    int delete_id;
    printf("Enter the ID of the teacher to delete: ");
    fgets(input, sizeof(input), stdin);
    Empty_entry(input);
    delete_id = atoi(input);

    int found = -1;
    for (int i = 0; i < teacher_count; i++) {
        if (teachers[i].id == delete_id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("No teacher found with ID %d.\n", delete_id);
        return;
    }

    for (int i = found; i < teacher_count - 1; i++) {
        teachers[i] = teachers[i + 1];
    }
    teacher_count--;

    FILE *file = fopen("teacher.csv", "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fclose(file);

    for (int i = 0; i < teacher_count; i++) {
        csv_write_teacher("teacher.csv", teachers[i]);
    }

    printf("Teacher with ID %d deleted successfully.\n", delete_id);
}

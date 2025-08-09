#include "student.h"
#include "handle-csv.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include"sms.h"



void add_student() {
    students=csv_read_student("students.csv", &student_count);

    if (student_count >= 100) {
        printf("Cannot add more students.\n");
        return;
    }

    Student new_student;
    int ch;

    // Clear stdin buffer before reading
    while ((ch = getchar()) != '\n' && ch != EOF);

    // --- Get student name ---
    printf("Enter student name: ");
    fgets(input, sizeof(input), stdin);
    Empty_entry(input);  // Ensure name is not blank
    input[strcspn(input, "\n")] = 0;
    strcpy(new_student.name, input);

    // --- Get student ID or auto-generate ---
    printf("Enter student ID (or leave blank for auto-increment): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (is_blank(input)) {
        new_student.id = (student_count > 0) ? students[student_count - 1].id + 1 : 1;
    } else {
        new_student.id = atoi(input);
    }

    // --- Check for duplicate ID ---
    if (is_duplicate_student_id(new_student.id)) {
        printf("Error: Duplicate ID not allowed.\n");
        return;
    }

    // --- Get grade (1 to 12 only) ---
    int grade = 0;
    printf("Enter student grade (1-12): ");
    fgets(input, sizeof(input), stdin);
    grade = atoi(input);
    while (grade < 1 || grade > 12) {
        printf("Wrong entry. Please enter a grade between 1 and 12: ");
        fgets(input, sizeof(input), stdin);
        grade = atoi(input);
    }
    new_student.grade = grade;

    // --- Get number of courses (must be at least 1) ---
    int count = 0;
    printf("Enter number of courses: ");
    fgets(input, sizeof(input), stdin);
    count = atoi(input);
    while (count <= 0) {
        printf("Student must have at least one course. Enter number of courses: ");
        fgets(input, sizeof(input), stdin);
        count = atoi(input);
    }
    new_student.course_count = count;

    // --- Get course names ---
    printf("Enter student courses:\n");
    for (int i = 0; i < new_student.course_count; i++) {
        printf("Course %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        Empty_entry(input);  // Ensure course name is not blank
        input[strcspn(input, "\n")] = 0;
        strcpy(new_student.courses[i], input);
    }

    // --- Store student and save to file ---
    students[student_count++] = new_student;
    csv_write_student("students.csv", new_student);
    printf("Student added successfully!\n");
}


void read_student() {
    students=csv_read_student("students.csv", &student_count);
    if(student_count==0)
    {
        printf("No students added yet\n");
    }

    for (int i = 0; i < student_count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name     : %s\n", students[i].name);
        printf("ID       : %d\n", students[i].id);
        printf("Grade    : %d\n", students[i].grade);
        printf("Courses  : ");
        for (int j = 0; j < students[i].course_count; j++) {
            if (strlen(students[i].courses[j]) > 0) {
                printf("%s ", students[i].courses[j]);
            }
        }
        printf("\n--------------------------------------------------\n");
    }
}
void update_student() {
    students=csv_read_student("students.csv", &student_count);

    // --- Get ID of the student to update ---
    int edited_id;
    printf("Enter the ID of the student to update: ");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    fgets(input, sizeof(input), stdin);
    edited_id = atoi(input);

    int i, found = 0;
    for (i = 0; i < student_count; i++) {
        if (students[i].id == edited_id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with ID %d.\n", edited_id);
        return;
    }

    // --- Choose what to update ---
    printf("What would you like to update?\n1. Name\n2. ID\n3. Grade\n4. Courses\nChoice: ");
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);

    switch (choice) {
        case 1:
            // --- Update name ---
            printf("Enter new name: ");
            fgets(input, sizeof(input), stdin);
            Empty_entry(input);
            input[strcspn(input, "\n")] = 0;
            strcpy(students[i].name, input);
            break;

        case 2:
            // --- Update ID ---
            printf("Enter new ID: ");
            fgets(input, sizeof(input), stdin);
            int new_id = atoi(input);

            // Prevent assigning a duplicate ID (except same student)
            for (int j = 0; j < student_count; j++) {
                if (j != i && students[j].id == new_id) {
                    printf("Error: Duplicate ID not allowed.\n");
                    return;
                }
            }
            students[i].id = new_id;
            break;

        case 3:
            // --- Update grade ---
            printf("Enter new grade (1-12): ");
            int grade;
            fgets(input, sizeof(input), stdin);
            grade = atoi(input);
            while (grade < 1 || grade > 12) {
                printf("Invalid grade. Enter a value between 1 and 12: ");
                fgets(input, sizeof(input), stdin);
                grade = atoi(input);
            }
            students[i].grade = grade;
            break;

        case 4:
            // --- Update courses ---
            int course_count;
            printf("Enter number of new courses: ");
            fgets(input, sizeof(input), stdin);
            course_count = atoi(input);
            while (course_count <= 0) {
                printf("All students must be registered in at least one course.\n");
                printf("Enter number of new courses: ");
                fgets(input, sizeof(input), stdin);
                course_count = atoi(input);
            }
            students[i].course_count = course_count;

            for (int j = 0; j < course_count; j++) {
                printf("Course %d: ", j + 1);
                fgets(input, sizeof(input), stdin);
                Empty_entry(input);
                input[strcspn(input, "\n")] = 0;
                strcpy(students[i].courses[j], input);
            }
            break;

        default:
            printf("Invalid choice.\n");
            return;
    }

    // --- Save all changes back to file ---
    FILE *file = fopen("students.csv", "w");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    fclose(file);

    for (int k = 0; k < student_count; k++) {
        csv_write_student("students.csv", students[k]);
    }

    printf("Student updated successfully.\n");
}

void delete_student() {
    students=csv_read_student("students.csv", &student_count);

    int delete_id;
    printf("Enter the ID of the student to delete: ");
    fgets(input,sizeof(input),stdin);
    delete_id=atoi(input);
    int i, found = 0;
    for (i = 0; i < student_count; i++) {
        if (students[i].id == delete_id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with ID %d.\n", delete_id);
        return;
    }

    for (int j = i; j < student_count - 1; j++) {
        students[j] = students[j + 1];
    }

    student_count--;

    FILE *file = fopen("students.csv", "w");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    fclose(file);

    for (int k = 0; k < student_count; k++) {
        csv_write_student("students.csv", students[k]);
    }

    printf("Student with ID %d deleted successfully.\n", delete_id);
}

#include "courses.h"
#include <stdlib.h>
#include "sms.h"

char data[100];
void add_courses() {
    courses = csv_read_courses("courses.csv", &course_count);
    
    Course new_course;
    
    printf("Please enter the name of the course: ");
    fgets(data, sizeof(data), stdin);
    Empty_entry(data);
    data[strcspn(data, "\n")] = '\0';
    strcpy(new_course.name, data);
    printf("Please enter the ID: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';  // Remove newline early
    
    if (is_blank(data)) {
        new_course.id = (course_count > 0) ? courses[course_count - 1].id + 1 : 1;
    } else {
        new_course.id = atoi(data);
    }
    
    if (is_duplicate_student_id(new_course.id)) {
        printf("Error: Duplicate ID not allowed.\n");
        return;
    }    

    int count = 0;
    printf("Enter number of allowed grades for this course: ");
    fgets(data, sizeof(data), stdin);
    Empty_entry(data);
    count=atoi(data);
    while (count <= 0) {
        printf("courses must have at least one grade allowed to register it . Enter number of Grades: ");
        fgets(data, sizeof(data), stdin);
        count=atoi(data);
    }

    new_course.grade_count = count;
    printf("Enter each allowed grade:\n");
    for (int i = 0; i < new_course.grade_count; i++) {
        printf("%d - ", i + 1);
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = '\0';
        new_course.allowed_grades_to_take_the_course[i] = atoi(data);
    }

    csv_write_courses("courses.csv", new_course);
    printf("Course added successfully!\n");
}

void read_courses() {
   courses= csv_read_courses("courses.csv", &course_count);
    if(course_count==0)
    {
        printf("No courses added yet \n");
    }
    for (int i = 0; i < course_count; i++) {
        printf("Course %d:\n", i + 1);
        printf("Name         : %s\n", courses[i].name);
        printf("ID           : %d\n", courses[i].id);
        printf("Allowed Grades: ");
        for (int j = 0; j < courses[i].grade_count; j++) {
            printf("%d ", courses[i].allowed_grades_to_take_the_course[j]);
        }
        printf("\n------------------------------------------------------\n");
    }
}
void update_courses() {
    int edited_course;
    courses=csv_read_courses("courses.csv", &course_count);

    printf("\nEnter the ID of the course to update: ");
    fgets(data, sizeof(data), stdin);
    Empty_entry(data);
    edited_course=atoi(data);

    int i, found = 0;
    for (i = 0; i < course_count; i++) {
        if (courses[i].id == edited_course) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No course found with ID %d.\n", edited_course);
        return;
    }

    printf("\nWhat would you like to update?\n1. Name\n2. ID\n3. Allowed Grades\nChoice: ");
    int choice;
    fgets(data, sizeof(data), stdin);
    Empty_entry(data);
    choice=atoi(data);
    switch (choice) {
        case 1:
            printf("Enter the new name: ");
            fgets(data, sizeof(data), stdin);
            Empty_entry(data);
            data[strcspn(data, "\n")] = '\0';
            strcpy(courses[i].name, data);
            break;
        case 2:
            printf("Enter the new ID: ");
            fgets(data, sizeof(data), stdin);
            if (is_blank(data)) {
                courses= csv_read_courses("courses.csv", &course_count);
                courses[i].id = (course_count > 0) ? courses[course_count - 1].id + 1 : 1;
            } else {
                courses[i].id = atoi(data);
            }
            if (is_duplicate_student_id(courses[i].id)) {
                printf("Error: Duplicate ID not allowed.\n");
                return;
            }
            data[strcspn(data, "\n")] = '\0';
            break;
        case 3:
            printf("Enter the number of allowed grades: ");
            fgets(data, sizeof(data), stdin);
            Empty_entry(data);
            data[strcspn(data, "\n")] = '\0';
            courses[i].grade_count = atoi(data);
            for (int j = 0; j < courses[i].grade_count; j++) {
                printf("Grade %d: ", j + 1);
                fgets(data, sizeof(data), stdin);
                Empty_entry(data);
                data[strcspn(data, "\n")] = '\0';
                courses[i].allowed_grades_to_take_the_course[j] = atoi(data);
            }
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    FILE *file = fopen("courses.csv", "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fclose(file);

    for (int k = 0; k < course_count; k++) {
        csv_write_courses("courses.csv", courses[k]);
    }

    printf("Course updated successfully!\n");
}

void delete_courses() {
    courses=csv_read_courses("courses.csv", &course_count);

    printf("Enter the ID of the course to delete: ");
    int delete_course_id;
    fgets(data, sizeof(data), stdin);
    Empty_entry(data);
    delete_course_id=atoi(data);
    int i, found = 0;
    for (i = 0; i < course_count; i++) {
        if (courses[i].id == delete_course_id) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No course found with ID %d.\n", delete_course_id);
        return;
    }

    // Shift elements
    for (int j = i; j < course_count - 1; j++) {
        courses[j] = courses[j + 1];
    }
    course_count--;

    FILE *file = fopen("courses.csv", "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fclose(file);

    for (int k = 0; k < course_count; k++) {
        csv_write_courses("courses.csv", courses[k]);
    }

    printf("Course with ID %d deleted successfully.\n", delete_course_id);
}


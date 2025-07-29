#include <stdio.h>
#include <string.h>
#include "sms.h"
#include "handle-csv.h"
#include <stdlib.h>

Student students[100];
Teacher teachers[100];
Course courses[100];
int student_count = 0;
int teacher_count = 0;
int course_count = 0;

void hash_password(const char *password, char *dest)
{
    unsigned char hash[32];
    SHA256((const unsigned char *)password, strlen(password), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(dest + (i * 2), "%02x", hash[i]);
    }
    dest[64] = '\0';
}

void get_data()
{
    char password[50];
    Data user;
    printf("Hello, to sign in please enter your name: ");
    scanf("%s", user.name);

    printf("Please enter your password: ");
    scanf("%s", password);
    hash_password(password, user.hashed_password);

    printf("Please enter your email: ");
    scanf("%s", user.email);

    int option;
    printf("Are you a/an: 1-ADMIN 2-MODERATOR 3-USER: ");
    scanf("%d", &option);
    user.role = option - 1;

    const char *role_str[] = {"ADMIN", "MODERATOR", "USER"};

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        perror("Sorry, failed to save your data");
        return;
    }

    fprintf(file, "-------------------------------------------------------------------------------------------------------------------\n");
    fprintf(file, "Name: %s\nEmail: %s\nPassword: %s\nRole: %s\n", user.name, user.email, user.hashed_password, role_str[user.role]);
    fclose(file);
}


int is_duplicate_student_id(int id)
{
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            return 1;
        }
    }
    return 0;
}


void add_student()
{
    csv_read_student("students.csv");
        if (student_count >= 100) {
            printf("Cannot add more students.\n");
            return;
        }
    
        Student new_student;
        printf("Enter student ID: ");
        scanf("%d", &new_student.id);
    
        if (is_duplicate_student_id(new_student.id)) {
            printf("Error: Duplicate ID not allowed.\n");
            return;
        }
    
        printf("Enter student name: ");
        scanf("%s", new_student.name);
    
        printf("Enter student grade: ");
        scanf("%f", &new_student.grade);
    
        new_student.course_count = 0; // No courses yet
    
        students[student_count++] = new_student;
        printf("Student added successfully!\n");
        csv_write_student("students.csv" ,new_student);
}

    

int main()
{
    int choice;
    do {
        printf("\n1. Add Student\n2. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_student();
            break;
        case 2:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 2);


    return 0;
}

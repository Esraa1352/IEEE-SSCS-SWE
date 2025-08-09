#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "sms.h"
#include "handle-csv.h"
#include "student.h"
#include "teacher.h"
#include "courses.h"
#include"load_users.h"

Student *students = NULL;
Teacher *teachers = NULL;
Course *courses =   NULL;
Data *users =NULL;

int student_count = 0;
int teacher_count = 0;
int course_count = 0;
int users_count=0;
int option ;
char input [256];


void hash_password(const char *password, char *dest) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)password, strlen(password), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(dest + (i * 2), "%02x", hash[i]);
    }
    dest[64] = '\0';
}

int get_data() 
{
    char option_str[10];
    Data user;

    // --- Name ---
    printf("Hello, to sign in please enter your name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    strcpy(user.name, input);

    // --- Password ---
    printf("Please enter your password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    hash_password(input, user.hashed_password);

    // --- Email ---
    printf("Please enter your email: ");
    fgets(user.email, sizeof(user.email), stdin);
    user.email[strcspn(user.email, "\n")] = '\0';

    // --- Role ---
    printf("Are you a/an: 1-ADMIN 2-MODERATOR 3-USER: ");
    fgets(option_str, sizeof(option_str), stdin);
    int option = atoi(option_str);
    if (option < 1 || option > 3) option = 3; // default USER
    user.role = option - 1;
    const char *role_str[] = {"ADMIN", "MODERATOR", "USER"};
    printf("---------------------------------------------------------\n");
    // --- Append to txt file ---
    FILE *file = fopen("users.txt", "a");
    if (!file) {
        perror("Sorry, failed to save your data");
        return -1;
    }

    // CSV format: name,email,hashed_password,role
    fprintf(file, "\"%s\",\"%s\",\"%s\",\"%s\"\n", 
            user.name, user.email, user.hashed_password, role_str[user.role]);
    fclose(file);

    // --- Store in memory ---
    Data *tmp = realloc(users, sizeof(Data) * (users_count + 1));
    if (!tmp) {
        perror("Failed to save data in memory");
        return -1;
    }
    users = tmp;
    users[users_count] = user;
    users_count++;

    return option;
}

int is_duplicate_student_id(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) return 1;
    }
    return 0;
}

int is_duplicate_teacher_id(int id) {
    for (int i = 0; i < teacher_count; i++) {
        if (teachers[i].id == id) return 1;
    }
    return 0;
}


int is_blank(char *input) {
    input[strcspn(input, "\n")] = 0;
    return strlen(input) == 0;
}
void Empty_entry(char *input)
{
    while(is_blank(input))
    {
        printf("Invalid input.This field can't be Empty.\n");
        fgets(input, sizeof(input), stdin);
    }
}


int main() 
{

    load_users();
    int section_choice;

    do {
        int directions ;
        printf("Welcome\n1.Sign up\n2.Log in\n");
        scanf("%d",&directions);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        switch (directions)
        {
        case 1:
            option = get_data(users_count);
            break;        
        case 2:
        {
        printf("Please Enter your User Name :");
        fgets(input,sizeof(input),stdin);
        int i ; 
        input[strcspn(input, "\n")] = '\0';  // Remove trailing newline
        int found = 0;
        for (i = 0; i < users_count; i++) {
            if (strcmp(users[i].name, input) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nName hasn't been registered yet. Please Sign up first\n");
            return 0;
        }

        char hashed_input[65];
        while (1) {
            printf("\nPlease Enter your Password: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        
            hash_password(input, hashed_input);
        
            if (strcmp(hashed_input, users[i].hashed_password) == 0) {
                printf("\nLogin Success\nWelcome %s\n", users[i].name);
                option = (users[i].role) + 1;
                break;  
            } else {
                printf("Incorrect password. Please try again.\n");
            }
        }
        

        printf("---------------------------------------------------------------------------\n");
        printf("1. Students Section\n2. Teacher Section\n3. Courses Section\n4. Exit\n");
        printf("---------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &section_choice);

        switch (section_choice) {
            case 1: {
                int student_choice;
                if (option == 1 || option == 2) { // ADMIN or MODERATOR
                    printf("1. Add Student\n2. Read Student\n3. Update Student\n4. Delete Student\n");
                    scanf("%d", &student_choice);
                    switch (student_choice) {
                        case 1: add_student(); break;
                        case 2: read_student(); break;
                        case 3: update_student(); break;
                        case 4: delete_student(); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                } else { // USER
                    printf("1. Add Student\n2. Read Student\n");
                    scanf("%d", &student_choice);
                    switch (student_choice) {
                        case 1: add_student(); break;
                        case 2: read_student(); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                }
                break;
            }

            case 2: {
                int teacher_choice;
                if (option == 1 || option == 2) {
                    printf("1. Add Teacher\n2. Read Teacher\n3. Update Teacher\n4. Delete Teacher\n");
                    scanf("%d", &teacher_choice);
                    getchar();
                    switch (teacher_choice) {
                        case 1: add_teacher(); break;
                        case 2: read_teacher(); break;
                        case 3: update_teacher(); break;
                        case 4: delete_teacher(); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                } else {
                    printf("1. Add Teacher\n2. Read Teacher\n");
                    scanf("%d", &teacher_choice);
                    switch (teacher_choice) {
                        case 1: add_teacher(); break;
                        case 2: read_teacher(); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                }
                break;
            }

            case 3: {
                int course_choice;
                if (option == 1 || option == 2) {
                    printf("1. Add Course\n2. Read Course\n3. Update Course\n4. Delete Course\n");
                    scanf("%d", &course_choice);
                    getchar();
                    switch (course_choice) {
                        case 1: add_courses(); break;
                        case 2: read_courses(); break;
                        case 3: update_courses(); break;
                        case 4: delete_courses(); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                } else {
                    printf("1. Add Course\n2. Read Course\n");
                    scanf("%d", &course_choice);
                    getchar();
                    switch (course_choice) {
                        case 1: add_courses(); break;
                        case 2: read_courses(); break;
                        default: printf("Invalid choice!\n"); break;
                    }
                }
                break;
            }

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid section choice!\n");
                break;
        }
    break;
    }
    default :
    printf("Invalid section choice!\n");
}} 
    while (section_choice != 4);
    return 0;
    
}
        

#ifndef SMS_H
#define SMS_H
#include <openssl/sha.h>
#include <string.h>
#include <stdio.h>


// task1
typedef enum 
{
    ADMIN ,  MODERATOR ,   USER
}Role;

typedef struct
{
  char name[50] ;
  char email[50];
  char hashed_password[65]; //the sha256 that we used for encryption always it's o/p is 32 byte better to be hex so 32*2 +1 null terminator
  Role role ;
}Data;

void hash_password(const char *password,char *dest);
int get_data();

// task2

typedef struct {
    int id;
    char name[50];
    int grade;
    char courses[10][10];
    int course_count;
} Student;

typedef struct {
    int id;
    char name[50];
    char courses[10][10];
    int course_count;
} Teacher;

typedef struct {
    int id;
    char name[50];
    int allowed_grades_to_take_the_course[10];
    int grade_count;
} Course;


int is_duplicate_student_id(int id);
int is_duplicate_teacher_id(int id);
int is_blank(char *input);
void Empty_entry(char *input);
extern Teacher *teachers;
extern Student *students;
extern Course *courses;
extern Data *users;
extern char input [256];
extern int users_count;
extern int teacher_count;
extern int student_count;
extern int course_count;
#endif
#ifndef SMS_H
#define SMS_H
#include <openssl/sha.h>
#include <string.h>
#include <stdio.h>

//enum is a variable of not many options possible to it limited to it
//where i don't want it to be a wide options i want it limited to the options it can have
//refrence for studying https://www.youtube.com/watch?v=EiDNaAOWkd8

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
void get_data();

// task2

typedef struct {
    int id;
    char name[50];
    float grade;
    int courses[10];
    int course_count;
} Student;

typedef struct {
    int id;
    char name[50];
    int courses[10];
    int course_count;
} Teacher;

typedef struct {
    int id;
    char name[50];
    int allowed_grades_to_take_the_course[10];
    int grade_count;
} Course;


int is_duplicate_student_id(int id);
void add_student();
void add_teacher();
void add_course();
#endif
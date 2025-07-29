#ifndef HANDLE_CSV_H
#define HANDLE_CSV_H
#include"sms.h"
void csv_write_student(const char *filename, Student student);
void csv_write_teacher(const char *filename, Teacher teacher);
void csv_write_courses(const char *filename, Course course);
Student *csv_read_student(const char *filename);
Teacher* csv_read_teacher(const char *filename);
Course * csv_read_courses(const char *filename) ;
#endif
#include "handle-csv.h"
#include "sms.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//------------------------------------------------------------
// WRITE STUDENT TO CSV
//------------------------------------------------------------
void csv_write_student(const char *filename, Student student) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Couldn't open student file for writing");
        return;
    }

    fprintf(file, "%d,", student.id);
    fprintf(file, "\"%s\",", student.name);
    fprintf(file, "%d,", student.grade);

    for (int i = 0; i < student.course_count; i++) {
        fprintf(file, "\"%s\"", student.courses[i]);
        if (i < student.course_count - 1)
            fprintf(file, ",");
    }
    fprintf(file, "\n");
    fclose(file);
}

//------------------------------------------------------------
// READ STUDENTS FROM CSV
//------------------------------------------------------------
Student* csv_read_student(const char *filename, int *out_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Couldn't open student file for reading");
        return NULL;
    }

    Student *students = NULL;
    char line[512];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        Student *tmp = realloc(students, sizeof(Student) * (count + 1));//making an array that fits for count
        if (!tmp) {
            perror("Memory allocation failed");
            free(students);
            fclose(file);
            return NULL;
        }
        students = tmp; //saving this allocated array to an array of structs 
        Student *s = &students[count]; 
        memset(s, 0, sizeof(Student)); // fill this student struct with 0

        char *token = strtok(line, ",");
        if (!token) continue;
        s->id = atoi(token);

        token = strtok(NULL, ",");
        if (token && token[0] == '"') token++;
        if (token) token[strcspn(token, "\"")] = '\0';
        strncpy(s->name, token,sizeof(s->name)-1);

        token = strtok(NULL, ",");
        s->grade =atoi(token) ;

        s->course_count = 0;
        while ((token = strtok(NULL, ",")) && s->course_count < 10) {
            if (strlen(token) == 0) {
                continue;
            }
            if (token[0] == '"') token++;
            token[strcspn(token, "\"")] = '\0';
            strncpy(s->courses[s->course_count], token, sizeof(s->courses[0]) - 1);
            s->courses[s->course_count][sizeof(s->courses[0]) - 1] = '\0';
            s->course_count++;
        }

        count++;
    }

    fclose(file);
    *out_count = count;
    return students;
}

//------------------------------------------------------------
// WRITE TEACHER TO CSV
//------------------------------------------------------------
void csv_write_teacher(const char *filename, Teacher teacher) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Couldn't open teacher file for writing");
        return;
    }

    fprintf(file, "%d,", teacher.id);
    fprintf(file, "\"%s\",", teacher.name);

    for (int i = 0; i < teacher.course_count; i++) {
        fprintf(file, "\"%s\"", teacher.courses[i]);
        if (i < teacher.course_count - 1)
            fprintf(file, ",");
    }

    fprintf(file, "\n");
    fclose(file);
}

//------------------------------------------------------------
// READ TEACHERS FROM CSV
//------------------------------------------------------------
Teacher* csv_read_teacher(const char *filename, int *out_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Couldn't open teacher file for reading");
        return NULL;
    }

    Teacher *teachers = NULL;
    char line[512];
    int count = 0;

    while (fgets(line, sizeof(line), file))
    {
        Teacher *tmp = realloc(teachers, sizeof(Teacher) * (count + 1));
        if (!tmp) {
            perror("Memory allocation failed");
            free(teachers);
            fclose(file);
            return NULL;
        }
        teachers = tmp;
        Teacher *t = &teachers[count];
        memset(t, 0, sizeof(Teacher));

        char *token = strtok(line, ",");
        if (!token) continue;
        t->id = atoi(token);

        token = strtok(NULL, ",");
        if (token && token[0] == '"') token++;
        if (token) token[strcspn(token, "\"")] = '\0';
        strncpy(t->name, token ,sizeof(t->name) - 1);

        t->course_count = 0;
        while ((token = strtok(NULL, ",")) && t->course_count < 10) {
            if (token[0] == '"') token++;
            token[strcspn(token, "\"")] = '\0';
            strncpy(t->courses[t->course_count], token, sizeof(t->courses[0]) - 1);
            t->courses[t->course_count][sizeof(t->courses[0]) - 1] = '\0';
            t->course_count++;
        }

        count++;
    }

    fclose(file);
    *out_count = count;
    return teachers;
}

//------------------------------------------------------------
// WRITE COURSE TO CSV
//------------------------------------------------------------
void csv_write_courses(const char *filename, Course course) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Couldn't open course file for writing");
        return;
    }

    fprintf(file, "%d,", course.id);
    fprintf(file, "\"%s\",", course.name);
    for (int i = 0; i < course.grade_count; i++) {
        fprintf(file, "%d", course.allowed_grades_to_take_the_course[i]);
        if (i < course.grade_count - 1)
            fprintf(file, ",");
    }

    fprintf(file, "\n");
    fclose(file);
}

//------------------------------------------------------------
// READ COURSES FROM CSV
//------------------------------------------------------------
Course* csv_read_courses(const char *filename, int *out_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Couldn't open course file for reading");
        return NULL;
    }

    Course *courses = NULL;
    char line[512];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        Course *tmp = realloc(courses, sizeof(Course) * (count + 1));
        if (!tmp) {
            perror("Memory allocation failed");
            free(courses);
            fclose(file);
            return NULL;
        }
        courses = tmp;
        Course *c = &courses[count];
        memset(c, 0, sizeof(Course));

        char *token = strtok(line, ",");
        if (!token) continue;
        c->id = atoi(token);

        token = strtok(NULL, ",");
        if (token && token[0] == '"') token++;
        token[strcspn(token, "\"")] = '\0';
        strncpy(c->name, token , sizeof(c->name) - 1);

        c->grade_count = 0;
        while ((token = strtok(NULL, ",")) && c->grade_count < 10) {
            c->allowed_grades_to_take_the_course[c->grade_count++] = atoi(token);
        }

        count++;
    }

    fclose(file);
    *out_count = count;
    return courses;
}

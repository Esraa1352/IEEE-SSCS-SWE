#include"handle-csv.h"
#include"sms.h"
#include <stdlib.h>

//---------------------------------------Student read and write CVS files-------------------------------------------------
void csv_write_student(const char *filename, Student student) {
    FILE *file = fopen(filename, "a");  
    if (!file) {
        printf("couldn't save data\n");
        return;
    }

    fprintf(file, "%d,\"%s\",%.2f,\"", student.id, student.name, student.grade);
    for (int i = 0; i < student.course_count ; i++) {
        fprintf(file, "%d", student.courses[i]);
        if (i < student.course_count - 1)
            fprintf(file, ",");
    }
    fprintf(file, "\"\n");// o/p:22010618,Esraa,80\

    fclose(file);
}

Student *csv_read_student(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Couldn't open file\n");
        return NULL;
    }

    int count = 0;
    char line[256];
    Student *students = NULL;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        Student *tmp = realloc(students, sizeof(Student) * (count + 1));
        if (!tmp) {
            printf("Memory allocation failed\n");
            free(students);
            fclose(file);
            return NULL;
        }
        students = tmp;
        Student *s = &students[count];

        // ID
        char *token = strtok(line, ",");
        if (token) s->id = atoi(token);

        // Name
        token = strtok(NULL, ",");
        if (token) {
            if (token[0] == '"') token++;
            token[strcspn(token, "\"")] = '\0';
            strncpy(s->name, token, sizeof(s->name));
        }

        // Grade
        token = strtok(NULL, ",");
        if (token) s->grade = atof(token);

        // Courses
        token = strtok(NULL, "\"");
        s->course_count = 0;
        if (token) {
            char *course_token = strtok(token, ",");
            while (course_token && s->course_count < 10) {
                s->courses[s->course_count++] = atoi(course_token);
                course_token = strtok(NULL, ",");
            }
        }

        count++;
    }

    fclose(file);
    return students;
}

//---------------------------------------------------------------------------------------------------------------------
void csv_write_teacher(const char *filename, Teacher teacher) {
    FILE *file = fopen(filename, "a");  
    if (!file) {
        printf("couldn't save data\n");
        return ;
    }

    fprintf(file, "%d,\"%s\"", teacher.id, teacher.name);
    for (int i = 0; i < teacher.course_count ; i++) {
        fprintf(file, "%d", teacher.courses[i]);
        if (i < teacher.course_count - 1)
            fprintf(file, ",");
    }
    fprintf(file, "\"\n");
    fclose(file);
}

Teacher* csv_read_teacher(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("couldn't read previous data");
        return NULL;
    }

    Teacher *teachers = NULL;
    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        Teacher *tmp = realloc(teachers, sizeof(Teacher) * (count + 1));
        if (!tmp) {
            perror("couldn't allocate memory");
            free(teachers);
            fclose(file);
            return NULL;
        }
        teachers = tmp;
        Teacher *t = &teachers[count];

        char *token = strtok(line, ",");
        if (token) t->id = atoi(token);

        token = strtok(NULL, ",");
        if (token) {
            if (token[0] == '"') token++;
            token[strcspn(token, "\"")] = '\0';
            strncpy(t->name, token, sizeof(t->name));
        }

        token = strtok(NULL, "\"");
        t->course_count = 0;
        if (token) {
            char *course_token = strtok(token, ",");
            while (course_token && t->course_count < 10) {
                t->courses[t->course_count++] = atoi(course_token);
                course_token = strtok(NULL, ",");
            }
        }

        count++;
    }

    fclose(file);
    return teachers;
}

//---------------------------------------------------------------------------------------------------------------------------
void csv_write_courses(const char *filename, Course course) {
    FILE *file = fopen(filename, "a");  
    if (!file) {
        printf("couldn't save data\n");
        return;
    }
    fprintf(file, "%d,\"%s\"\"", course.id, course.name);
    for (int i = 0; i < course.grade_count; i++) {
        fprintf(file, ",%d", course.allowed_grades_to_take_the_course[i]);
        if (i < course.grade_count - 1)
            fprintf(file, ",");
    }
    fprintf(file, "\"\n");
    fclose(file);
}
Course* csv_read_courses(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Couldn't open file\n");
        return NULL;
    }

    int count = 0;
    char line[256];
    Course *courses = NULL;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        Course *tmp = realloc(courses, sizeof(Course) * (count + 1));
        if (!tmp) {
            printf("Memory allocation failed\n");
            free(courses);
            fclose(file);
            return NULL;
        }
        courses = tmp;
        Course *c = &courses[count];

        char *token = strtok(line, ",");
        if (token) c->id = atoi(token);

        token = strtok(NULL, ",");
        if (token) {
            if (token[0] == '"') token++;
            token[strcspn(token, "\"")] = '\0';
            strncpy(c->name, token, sizeof(c->name));
        }

        token = strtok(NULL, "\"");
        c->grade_count = 0;
        if (token) {
            char *grade_token = strtok(token, ",");
            while (grade_token && c->grade_count < 10) {
                c->allowed_grades_to_take_the_course[c->grade_count++] = atoi(grade_token);
                grade_token = strtok(NULL, ",");
            }
        }

        count++;
    }

    fclose(file);
    return courses;
}

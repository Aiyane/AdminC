#ifndef __MODEL_H__
#define __MODEL_H__
#define MAXID 100

typedef struct student {
    int id;
    int zlass;
    char* name;
    char* pwd;
} Student;

typedef struct teacher {
    int id;
    char* name;
    char* pwd;
} Teacher;

typedef struct subject {
    int id;
    char* name;
} Subject;

typedef struct grade {
    int subjectId;
    int studentId;
    float grade;
} Grade;

typedef struct transcript {
    // int id;
    char *name;
    float totalScore;
} Transcript;

// 全局变量
Student** STUDENTS;
Subject** SUBJECTS;
Grade** GRADES;
int STUDENTS_LEN, SUBJECTS_LEN, GRADES_LEN, TRANSCRIPT_LEN;

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // getch函数
#include "include/func.h"

void getNum(char *num) {
    /**
     * 输入:
     *      char* num  输入的字符串指针
    */
    int i = 0;
    char ch = 0;
    while (i <= 100 && ch != '\r' && ch != '\n') {

        ch = getch();

        // 不是回退或删除就回显
        if (ch != '\b' && ch != 127) {
            *(num + i) = ch;
            i ++;
            putchar(ch);
        }
        else {

            // 否则回退
            if (i > 0) {
                i--;
                *(num + i) = 0;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        }
    }

    if (ch != '\r' || ch != '\n'){
        i--;
        *(num + i) = '\0';
    } else {
        *(num + i) = '\0';
    }

    putchar('\n');
}

void getPwd(char *pwd) {
    /**
     * 输入：
     *      pwd:密码
    */
    int i = 0;
    char ch = 0;
    while (i <= 100 && ch != '\r' && ch != '\n') {

        ch = getch();

        // 不是回退或删除就回显*
        if (ch != '\b' && ch != 127) {
            *(pwd + i) = ch;
            i ++;
            putchar('*');
        }
        else {

            // 否则回退
            if (i > 0) {
                i--;
                *(pwd + i) = 0;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        }
    }

    if (ch != '\r' || ch != '\n'){
        i--;
        *(pwd + i) = '\0';
    } else {
        *(pwd + i) = '\0';
    }

    putchar('\n');
}

void initStudents() {
    FILE *in = NULL;
    char chr='_', *str = NULL;
    int j, i = 0;
    in = fopen(".student.txt", "r");

    while (chr != EOF) {
        *(STUDENTS + STUDENTS_LEN) = (Student *)malloc(sizeof(Student));
        if (*(STUDENTS + STUDENTS_LEN) == NULL){
            printf("内存分配失败!\n");
            return ;
        }
        while((chr = fgetc(in)) != EOF){
            // 获取下一个单词str
            str = (char *)malloc(100 * sizeof(char));
            if (str == NULL){
                printf("内存分配失败!\n");
                return ;
            }
            for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
                *(str+ j) = chr;
                chr = fgetc(in);
            }
            *(str+ j) = '\0';

            // 如果是学号
            if (i == 0){
                (*(STUDENTS + STUDENTS_LEN))->id = atoi(str);
                free(str);
                i ++;
            }
            // 如果是班级
            else if (i == 1){
                (*(STUDENTS + STUDENTS_LEN))->zlass = atoi(str);
                free(str);
                i ++;
            }
            // 如果是姓名
            else if (i == 2){
                (*(STUDENTS + STUDENTS_LEN))->name = (char *) malloc(100*sizeof(char));
                strcpy((*(STUDENTS + STUDENTS_LEN))->name, str);
                free(str);
                i ++;
            }
            // 如果是密码
            else{
                (*(STUDENTS + STUDENTS_LEN))->pwd = (char *) malloc(100*sizeof(char));
                strcpy((*(STUDENTS + STUDENTS_LEN))->pwd, str);
                free(str);
                STUDENTS_LEN ++;
                i = 0;
                break;
            }
        }
    }
    fclose(in);
    str = NULL;
    in = NULL;
}

void initSubjects() {
    FILE *in = NULL;
    char chr='_', *str = NULL;
    int j, i = 0;
    in = fopen(".subject.txt", "r");

    while (chr != EOF) {
        *(SUBJECTS + SUBJECTS_LEN) = (Subject *)malloc(sizeof(Subject));
        if (*(SUBJECTS + SUBJECTS_LEN) == NULL){
            printf("内存分配失败!\n");
            return ;
        }
        while((chr = fgetc(in)) != EOF){
            // 获取下一个单词str
            str = (char *)malloc(100 * sizeof(char));
            if (str == NULL){
                printf("内存分配失败!\n");
                return ;
            }
            for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
                *(str + j) = chr;
                chr = fgetc(in);
            }
            *(str + j) = '\0';

            // 如果是id
            if (i == 0){
                (*(SUBJECTS + SUBJECTS_LEN))->id = atoi(str);
                free(str);
                i ++;
            }
            // 如果是名字
            else{
                (*(SUBJECTS + SUBJECTS_LEN))->name = (char *)malloc(100 * sizeof(char));
                strcpy((*(SUBJECTS + SUBJECTS_LEN))->name, str);
                free(str);
                SUBJECTS_LEN ++;
                i = 0;
                break;
            }
        }
    }
    fclose(in);
    in = NULL;
    str = NULL;
}

void initGrades() {
    FILE *in = NULL;
    char chr='_', *str = NULL;
    int j, i = 0;
    in = fopen(".grade.txt", "r");

    while (chr != EOF) {
        *(GRADES + GRADES_LEN) = (Grade *)malloc(sizeof(Grade));
        if (*(GRADES + GRADES_LEN) == NULL){
            printf("内存分配失败!\n");
            return ;
        }
        while((chr = fgetc(in)) != EOF){
            // 获取下一个单词str
            str = (char *)malloc(100 * sizeof(char));
            if (str == NULL){
                printf("内存分配失败!\n");
                return ;
            }
            for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
                *(str + j) = chr;
                chr = fgetc(in);
            }
            *(str + j) = '\0';

            // 如果是学科
            if (i == 0){
                (*(GRADES + GRADES_LEN))->subjectId = atoi(str);
                free(str);
                i ++;
            }
            // 如果是学生
            else if (i == 1){
                (*(GRADES + GRADES_LEN))->studentId = atoi(str);
                free(str);
                i ++;
            }
            // 如果是成绩
            else{
                (*(GRADES + GRADES_LEN))->grade = atof(str);
                free(str);
                GRADES_LEN ++;
                i = 0;
                break;
            }
        }
    }
    fclose(in);
    in = NULL;
    str = NULL;
}

float getGrades(int id) {
    // 获取学生全部成绩
    float totalScore=0;
    for (int i=0; i < GRADES_LEN; i++){
        if ((*(GRADES + i))->studentId == id){
            totalScore += (*(GRADES + i))->grade;
        }
    }
    return totalScore;
}

int getClassRank(Grade *grade, int zlass){
    int rank=1, flag;
    for (int i=0; i < GRADES_LEN; i++){
        // 同一个班级，同一个学科，不同人
        flag = 0;
        for (int j=0; j<STUDENTS_LEN; j++){
            if (STUDENTS[j]->id == grade->studentId){
                if (STUDENTS[j]->zlass == zlass){
                    flag = 1;
                }
                break;
            }
        }
        if (flag == 1 &&
            (*(GRADES + i))->subjectId == grade->subjectId &&
            (*(GRADES + i))->studentId != grade->studentId &&
            (*(GRADES + i))->grade >= grade->grade){
            rank ++;
        }
    }
    return rank;
}

int getGradeRank(Grade *grade) {
    int rank=1;
    for (int i=0; i < GRADES_LEN; i++){
        // 同一个学科，不同人
        if ((*(GRADES + i))->subjectId == grade->subjectId &&
            (*(GRADES + i))->studentId != grade->studentId &&
            (*(GRADES + i))->grade >= grade->grade){
                rank ++;
        }
    }
    return rank;
}

void getClassTotalScore(int classId, float *totalScores){
    if (totalScores == NULL){
        printf("内存分配失败!\n");
        return NULL;
    }
    int flag;
    for (int i=0; i < GRADES_LEN; i++){
        flag = 0;
        for (int j=0; j<STUDENTS_LEN; j++){
            if (STUDENTS[j]->id == (*(GRADES + i))->studentId){
                if (STUDENTS[j]->zlass == classId){
                    flag = 1;
                }
                break;
            }
        }
        if (flag == 1){
            (*(totalScores + (*(GRADES + i))->studentId - 1)) += (*(GRADES + i))->grade;
        }
    }
}

void getTotalScore(float * totalScores){
    if (totalScores == NULL){
        printf("内存分配失败!\n");
        return NULL;
    }
    for (int i=0; i < GRADES_LEN; i++){
        (*(totalScores + (*(GRADES + i))->studentId - 1)) += (*(GRADES + i))->grade;
    }
}

int getTotalClassRank(float totalScore, int classID){
    int rank = 0;
    float* scores = (float *)malloc(MAXID*sizeof(float));
    getClassTotalScore(classID, scores);
    for (int i=0; i < MAXID; i++){
        if (*(scores + i) >= totalScore){
            rank++;
        }
    }
    // free(scores);
    scores = NULL;
    return rank;
}

int getTotalGradeRank(float totalScore) {
    int rank = 0;
    float* scores = (float *)malloc(MAXID*sizeof(float));
    getTotalScore(scores);
    for (int i=0; i < MAXID; i++){
        if (*(scores + i) >= totalScore){
            rank++;
        }
    }
    // free(scores);
    scores = NULL;
    return rank;
}

int __partition(Transcript **transcripts, int l, int r){
    int randNum = rand()%(r - l + 1)  + l;
    Transcript * t = NULL;
    t = *(transcripts + l);
    *(transcripts + l) = *(transcripts + randNum);
    *(transcripts + randNum) = t;

    Transcript *v = *(transcripts + l);

    int lt = l;     // arr[l+1, lt] < v
    int gt = r +1;  // arr[gt, r] > v
    int i = l + 1;  // arr[lt+1, i] == v
    while( i < gt ){
        if( (*(transcripts + i))->totalScore > v->totalScore ){
            t = *(transcripts + i);
            *(transcripts + i) = *(transcripts + lt+1);
            *(transcripts + lt+1) = t;
            i ++;
            lt ++;
        }
        else if( (*(transcripts + i))->totalScore < v->totalScore ){
            t = *(transcripts + i);
            *(transcripts + i) = *(transcripts + gt - 1);
            *(transcripts + gt - 1) = t;
            gt--;
        }
        else{
            i ++;
        }
    }

    t = *(transcripts + l);
    *(transcripts + l) = *(transcripts + lt);
    *(transcripts + lt) = t;
    t = NULL;
    v = NULL;
    return lt;
}

void __quickSort(Transcript **transcripts, int l, int r){
    if (l >= r )
        return ;

    int p = __partition(transcripts, l, r);
    __quickSort(transcripts, l, p-1);
    __quickSort(transcripts, p+1, r);
}

void quickSort(Transcript **transcripts) {
    __quickSort(transcripts, 0, TRANSCRIPT_LEN - 1);
}

void printGradeByTranscripts(Transcript **transcripts){
    int j;
    for (int i=0; i<TRANSCRIPT_LEN; i++){
        // printf("学号: %d, ", (*(transcripts + i))->id);
        printf("姓名: %s, ", (*(transcripts + i))->name);
        printf("总分: %f, ", (*(transcripts + i))->totalScore);
        printf("排名: %d\n", i+1);
    }
}

void showSubject(){
    printf("课程名: 课程号\n");
    for(int i=0; i < SUBJECTS_LEN; i++){
        printf("%s: %d\n", (*(SUBJECTS + i))->name, (*(SUBJECTS + i))->id);
    }
}
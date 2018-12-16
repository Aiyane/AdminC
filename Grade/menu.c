#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // F_OK
#include "include/menu.h"

int inputNum(){
    /**
     * ���أ�
     *      -1: ǿ���˳�
     *      -2: ��������ַ�
     *      -3: û������
     *      ���ڵ��� 0 ������
    */

    // ���ؽ��
    int num = 0;
    // �����ַ�������
    char *p = NULL, *numChars = (char *)malloc(100 * sizeof(char));
    if (numChars == NULL){
        printf("�ڴ����ʧ�ܣ�\n");
        return -1;
    }
    // ��ӡ������ʾ��
    printf("=>> ");

    // ��ȡ�����ַ� 
    getNum(numChars);

    // ���û������
    if (strlen(numChars) == 0) {
        free(numChars);
        numChars = NULL;
        return -3;
    }

    p = numChars;

    // ǿ���˳�
    if (strcmp(p, "-1") == 0) {
        printf(" ----------\n");
        printf("| ǿ���˳� |\n");
        printf(" ----------\n\n");
        free(numChars);
        numChars = NULL;
        p = NULL;
        return -1;
    }

    // ��ȡ�����ַ� ת���� int
    while (*p != '\0') {
        // �����˴����ַ�
        if (*p < '0' || *p > '9') {
            printf("��������ַ�!����������\n");
            free(numChars);
            numChars = NULL;
            p = NULL;
            return -2;
        }

        num = num * 10 + (*p - '0');
        p++;
    }

    free(numChars);
    numChars = NULL;
    p = NULL;
    return num;
}

void inputPwd(char* pwdChars){
    // ��ӡ������ʾ��
    printf("=>> ");

    // ��ȡ�����ַ� 
    getPwd(pwdChars);

    // ǿ���˳�
    if (strcmp(pwdChars, "-1") == 0) {
        printf(" ----------\n");
        printf("| ǿ���˳� |\n");
        printf(" ----------\n\n");
        free(pwdChars);
        pwdChars = NULL;
    }
}

void showMenu() {
    printf("\n--�˵�-------------------------------\n");
    printf("|||||||   -1.      ǿ���˳�   |||||||\n");
    printf("|||||||    0.          �˳�   |||||||\n");
    printf("|||||||    1.      ѧ����¼   |||||||\n");
    printf("|||||||    2.      ��ʦ��¼   |||||||\n");
    printf("|||||||    3.          ����   |||||||\n");
    printf("|||||||    4.      ��ʾ�˵�   |||||||\n");
    printf("-------------------------------�˵�--\n");
    printf("\n");
}

void showTeacherMenu() {
    printf("\n--�˵�-------------------------------\n");
    printf("|||||||   -1.      ǿ���˳�   |||||||\n");
    printf("|||||||    0.          �˳�   |||||||\n");
    printf("|||||||    1.      �γ̱��   |||||||\n");
    printf("|||||||    2.      ���ѧ��   |||||||\n");
    printf("|||||||    3.      ��ӳɼ�   |||||||\n");
    printf("|||||||    4.      ��ӿ�Ŀ   |||||||\n");
    printf("|||||||    5.      �޸�ѧ��   |||||||\n");
    printf("|||||||    6.      �޸ĳɼ�   |||||||\n");
    printf("|||||||    7.      �޸Ŀ�Ŀ   |||||||\n");
    printf("|||||||    8.      ��ѯ�ɼ�   |||||||\n");
    printf("|||||||    9.      ͳ����Ŀ   |||||||\n");
    printf("|||||||    10.     �ɼ�����   |||||||\n");
    printf("|||||||    11.         ����   |||||||\n");
    printf("|||||||    12.     ��ʾ�˵�   |||||||\n");
    printf("-------------------------------�˵�--\n");
    printf("\n");
}

void showStudentMenu() {
    printf("\n--�˵�-------------------------------\n");
    printf("|||||||   -1.      ǿ���˳�   |||||||\n");
    printf("|||||||    0.          �˳�   |||||||\n");
    printf("|||||||    1.      ��ѯ�ɼ�   |||||||\n");
    printf("|||||||    2.      ��ѯ����   |||||||\n");
    printf("|||||||    3.      �γ̱��   |||||||\n");
    printf("|||||||    4.          ����   |||||||\n");
    printf("|||||||    5.      ��ʾ�˵�   |||||||\n");
    printf("-------------------------------�˵�--\n");
    printf("\n");
}

void showRankMenu() {
    printf("\n--�˵�-------------------------------\n");
    printf("|||||||   -1.      ǿ���˳�   |||||||\n");
    printf("|||||||    0.          �˳�   |||||||\n");
    printf("|||||||    1.      �༶����   |||||||\n");
    printf("|||||||    2.      �꼶����   |||||||\n");
    printf("|||||||    3.          ����   |||||||\n");
    printf("|||||||    4.      ��ʾ�˵�   |||||||\n");
    printf("-------------------------------�˵�--\n");
    printf("\n");
}

 
// #include <stdio.h>
 
// char* Int2String(int num,char *str);//�������� 
// int main()
// {
// 	int number1 = 123456;
// 	int number2 = -123456;
// 	char string[16] = {0};
// 	Int2String(number1,string);
// 	printf("���֣�%d ת������ַ���Ϊ��%s\n",number1,string);
// 	Int2String(number2,string);
// 	printf("���֣�%d ת������ַ���Ϊ��%s\n",number2,string);
// 	return 0;
// }
 
// void Int2String(int num,char *str){
//     int i = 0;//ָʾ���str 
//     if(num<0) {
//         num = -num;
//         str[i++] = '-';
//     } 
//     //ת�� 
//     do {
//         str[i++] = num%10+48;//ȡnum���λ �ַ�0~9��ASCII����48~57������˵����0+48=48��ASCII���Ӧ�ַ�'0' 
//         num /= 10;//ȥ�����λ	
//     }while(num);//num��Ϊ0����ѭ��

//     str[i] = '\0';

//     //ȷ����ʼ������λ�� 
//     int j = 0;
//     if(str[0]=='-'){
//         j = 1;//�ӵڶ�λ��ʼ���� 
//         ++i;//�����и��ţ����Խ����ĶԳ���ҲҪ����1λ 
//     }
//     //�Գƽ��� 
//     for(;j<i/2;j++) {
//     //�Գƽ������˵�ֵ ��ʵ����ʡ���м��������a+b��ֵ��a=a+b;b=a-b;a=a-b; 
//         str[j] = str[j] + str[i-1-j];
//         str[i-1-j] = str[j] - str[i-1-j];
//         str[j] = str[j] - str[i-1-j];
//     } 
// }


void saveInfoExit() {
    //TODO: ���浱ǰ���ݵ����ݿ�
    FILE *file;
    char str[100];
    char *student = ".student.txt", *grade = ".grade.txt", *subject = ".subject.txt";
    if ((file = fopen(student, "w")) == NULL) {
        printf("д��ѧ������ʧ��, ������ȷ�ر�!");
        fclose(file);
        return ;
    }
    for (int i=0; i < STUDENTS_LEN; i++){
        sprintf(str, "%d", (*(STUDENTS+i))->id);
        fputs(str, file);
        fputs(" ", file);
        sprintf(str, "%d", (*(STUDENTS+i))->zlass);
        fputs(str, file);
        fputs(" ", file);
        fputs((*(STUDENTS+i))->name, file);
        fputs(" ", file);
        fputs((*(STUDENTS+i))->pwd, file);
        fputs("\n", file);
    }
    fclose(file);

    if ((file = fopen(subject, "w")) == NULL) {
        printf("д��ѧ������ʧ��, ������ȷ�ر�!");
        fclose(file);
        return ;
    }
    for (int i=0; i < SUBJECTS_LEN; i++){
        sprintf(str, "%d", (*(SUBJECTS+i))->id);
        fputs(str, file);
        fputs(" ", file);
        fputs((*(SUBJECTS+i))->name, file);
        fputs("\n", file);
    }
    fclose(file);

    if ((file = fopen(grade, "w")) == NULL) {
        printf("д��ѧ������ʧ��, ������ȷ�ر�!");
        fclose(file);
        return ;
    }
    for (int i=0; i < GRADES_LEN; i++){
        sprintf(str, "%d", (*(GRADES+i))->subjectId);
        fputs(str, file);
        fputs(" ", file);
        sprintf(str, "%d", (*(GRADES+i))->studentId);
        fputs(str, file);
        fputs(" ", file);
        sprintf(str, "%f", (*(GRADES+i))->grade);
        fputs(str, file);
        fputs("\n", file);
    }
    fclose(file);

    printf("\n�˳�!\n");
    printf("=====\n\n");
}

void init() {
    char *student = ".student.txt", *grade = ".grade.txt", *subject = ".subject.txt";

    if ((access(student, F_OK)) != -1) {
        initStudents();
    }

    if ((access(subject, F_OK)) != -1){
        initSubjects();
    }

    if ((access(grade, F_OK)) != -1){
        initGrades();
    }
}

int addStudent() {
    /**
     * ����ѧ��
    */
    int id, zlass;
    char *name = NULL, *pwd = NULL;

    if (STUDENTS_LEN == 100) {
        return -1;
    }

    printf("������ѧ��:\n");
    id = inputNum();
    if (id < 0){
        printf("ѧ���������\n");
        return -1;
    }
    for (int i=0; i<STUDENTS_LEN; i++){
        if ((*(STUDENTS + i))->id == id){
            printf("ѧ���Ѵ��ڣ�\n");
            return -1;
        }
    }
    if (id > MAXID){
        printf("ѧ�ų�����Χ��\n");
        return -1;
    }

    printf("������༶:\n");
    zlass = inputNum();
    if (zlass < 0){
        printf("�༶�������\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("�ڴ����ʧ��\n");
        return -1;
    }
    printf("������ѧ������:\n");
    printf("=>> ");
    gets(name);
    if (strcmp(name, "-1") == 0){
        free(name);
        name = NULL;
        return -1;
    }

    printf("������ѧ������:\n");
    // �����ַ�������
    pwd = (char *)malloc(100 * sizeof(char));
    if (pwd == NULL){
        printf("�ڴ����ʧ��\n");
        return -1;
    }
    inputPwd(pwd);
    if (pwd == NULL){
        free(name);
        free(pwd);
        name = NULL;
        pwd = NULL;
        return -1;
    }

    *(STUDENTS + STUDENTS_LEN) = (Student *)malloc(sizeof(Student));
    (*(STUDENTS + STUDENTS_LEN))->id = id;
    (*(STUDENTS + STUDENTS_LEN))->zlass = zlass;
    (*(STUDENTS + STUDENTS_LEN))->name = (char *) malloc(100*sizeof(char));
    strcpy((*(STUDENTS + STUDENTS_LEN))->name, name);
    (*(STUDENTS + STUDENTS_LEN))->pwd = (char *) malloc(100*sizeof(char));
    strcpy((*(STUDENTS + STUDENTS_LEN))->pwd, pwd);
    free(name);
    free(pwd);
    STUDENTS_LEN ++;
    name = NULL;
    pwd = NULL;
    return 0;
}

int addGrade(){
    int subjectId, studentId;

    if (GRADES_LEN == 100){
        return -1;
    }

    printf("������ѧ��:\n");
    studentId = inputNum();
    if (studentId < 0){
        printf("ѧ���������\n");
        return -1;
    }

    printf("������γ̺�:\n");
    subjectId = inputNum();
    if (subjectId < 0){
        printf("�γ̺��������\n");
        return -1;
    }

    printf("���������:\n");
    char res[50];
    printf("=>> ");
    gets(res);
    if (strcmp(res, "-1") == 0){
        return -1;
    }
    float socre = atof(res);

    *(GRADES + GRADES_LEN) = (Grade *)malloc(sizeof(Grade));
    (*(GRADES + GRADES_LEN))->subjectId = subjectId;
    (*(GRADES + GRADES_LEN))->studentId = studentId;
    (*(GRADES + GRADES_LEN))->grade = socre;
    GRADES_LEN ++;
    return 0;
}

int addSubject(){
    int id;
    char *name = NULL;

    if (SUBJECTS_LEN == 100){
        return -1;
    }

    printf("������γ̱��:\n");
    id = inputNum();
    if (id < 0){
        printf("�γ̱���������\n");
        return -1;
    }
    for (int i=0; i<SUBJECTS_LEN; i++){
        if ((*(SUBJECTS + i))->id == id){
            printf("�γ̱���Ѵ��ڣ�\n");
            return -1;
        }
    }
    if (id > MAXID){
        printf("��ų�����Χ��\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("�ڴ����ʧ��\n");
        return -1;
    }
    printf("������ѧ����:\n");
    printf("=>> ");
    gets(name);
    if (strcmp(name, "-1") == 0){
        free(name);
        name = NULL;
        return -1;
    }

    Subject subject = {id, name};
    *(SUBJECTS + SUBJECTS_LEN) = (Subject *)malloc(sizeof(Subject));
    (*(SUBJECTS + SUBJECTS_LEN))->id = id;
    (*(SUBJECTS + SUBJECTS_LEN))->name = (char *)malloc(100 * sizeof(char));
    strcpy((*(SUBJECTS + SUBJECTS_LEN))->name, name);
    SUBJECTS_LEN ++;
    return 0;
}

int modifyName(){
    int id;
    char* name = NULL;
    Student *student=NULL;

    printf("������ѧ��:\n");
    id = inputNum();
    if (id < 0){
        printf("ѧ���������\n");
        return -1;
    }
    for (int i=0; i<STUDENTS_LEN; i++){
        if ((*(STUDENTS+i))->id == id){
            student = *(STUDENTS+i);
            break;
        }
    }
    if (!student){
        printf("û�и�ѧ����Ϣ��\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("�ڴ����ʧ��\n");
        return -1;
    }
    printf("������������:\n");
    printf("=>> ");
    gets(name);
    if (strcmp(name, "-1") == 0){
        free(name);
        name = NULL;
        return -1;
    }

    student->name = name;
    name = NULL;
    student = NULL;
    return 0;
}

int modifyGrade(){
    int id1, id2;
    Grade * grade=NULL;

    printf("�������޸�ѧ��ѧ��:\n");
    id1 = inputNum();
    if (id1 < 0){
        printf("ѧ���������\n");
        return -1;
    }

    printf("�������޸�ѧ�Ʊ��:\n");
    id2 = inputNum();
    if (id2 < 0){
        printf("����������\n");
        return -1;
    }

    for (int i=0; i<GRADES_LEN; i++){
        if ((*(GRADES+i))->studentId == id1 && (*(GRADES+i))->subjectId == id2){
            grade = *(GRADES+i);
            break;
        }
    }

    if (!grade){
        printf("û�и�ѧ���ɼ���Ϣ��\n");
        return -1;
    }

    printf("�������޸ĺ����:\n");
    char res[50];
    printf("=>> ");
    gets(res);
    if (strcmp(res, "-1") == 0){
        return -1;
    }
    grade->grade = atof(res);
    grade = NULL;
    return 0;
}

int modifySubject(){
    int id;
    char* name = NULL;
    Subject *subject=NULL;

    printf("������γ̱��:\n");
    id = inputNum();
    if (id < 0){
        printf("�γ̱���������\n");
        return -1;
    }
    for (int i=0; i<SUBJECTS_LEN; i++){
        if ((*(SUBJECTS+i))->id == id){
            subject = *(SUBJECTS+i);
            break;
        }
    }
    if (!subject){
        printf("û�и�ѧ�ƣ�\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("�ڴ����ʧ��\n");
        return -1;
    }
    printf("�������¿γ���:\n");
    printf("=>> ");
    gets(name);
    if (strcmp(name, "-1") == 0){
        free(name);
        name = NULL;
        return -1;
    }
    subject->name = name;
    name = NULL;
    subject = NULL;
    return 0;
}

void selectGrade(Student *student) {
    printf("%s�ĳɼ�Ϊ:\n", student->name);
    for (int i=0; i < GRADES_LEN; i++){
        if ((*(GRADES+i))->studentId == student->id){
            printf("%d: %f\n", (*(GRADES+i))->subjectId, (*(GRADES+i))->grade);
        }
    }
}

void rankGrade(Student *student) {
    /**
     * ѧ���ɼ�����
    */
    float totalScore = 0;
    printf("%s�ĳɼ�Ϊ:\n", student->name);
    for (int i=0; i < GRADES_LEN; i++){
        if ((*(GRADES+i))->studentId == student->id){
            printf("%d: �༶����: %d\n", (*(GRADES+i))->subjectId, getClassRank(*(GRADES+i), student->zlass));
            printf("%d: �꼶����: %d\n", (*(GRADES+i))->subjectId, getGradeRank(*(GRADES+i)));
            totalScore += (*(GRADES+i))->grade;
        }
    }
    printf("�ܷ�����:\n");
    printf("�༶����: %d\n", getTotalClassRank(totalScore, student->zlass));
    printf("�꼶����: %d\n", getTotalGradeRank(totalScore));
}

int selectGradeByTeacher() {
    int id;
    printf("������ѧ��ѧ��:\n");
    id = inputNum();
    if (id < 0){
        printf("ѧ���������\n");
        return -1;
    }
    for (int i=0; i < STUDENTS_LEN; i++){
        if ((*(STUDENTS+i))->id == id){
            selectGrade(*(STUDENTS+i));
            return 0;
        }
    }
}

void printStudentNum() {
    printf("ȫ�꼶ѧ������: %d\n", STUDENTS_LEN);
    int zlass[50] = {0}, i;
    for (i = 0; i < STUDENTS_LEN; i++){
        zlass[(*(STUDENTS + i))->zlass] += 1;
    }
    i = 1;
    while (zlass[i]){
        printf("%d��������: %d\n", i, zlass[i]);
        i++;
    }
}

int printClassGrade() {
    printf("��������:\n");
    int zlass, tspIndex=0, j;
    float totalScore;
    zlass = inputNum();
    if (zlass < 0){
        printf("�������\n");
        return -1;
    }

    Transcript **transcripts = (Transcript **) malloc(GRADES_LEN*sizeof(Transcript *));
    TRANSCRIPT_LEN = 0;

    for (int i=0; i < STUDENTS_LEN; i++){
        if ((*(STUDENTS+i))->zlass == zlass){
            *(transcripts + tspIndex) = (Transcript *)malloc(sizeof(Transcript *));
            (*(transcripts + tspIndex))->name = (char *)malloc(100*sizeof(char));
            strcpy((*(transcripts + tspIndex))->name, (*(STUDENTS+i))->name);
            // (*(transcripts + tspIndex))->id = (*(STUDENTS+i))->id;
            (*(transcripts + tspIndex))->totalScore = getGrades((*(STUDENTS+i))->id);
            tspIndex ++;
            TRANSCRIPT_LEN ++;
        }
    }

    printf("%d��ĳɼ�������:\n", zlass);
    quickSort(transcripts);
    printGradeByTranscripts(transcripts);
    free(transcripts);
    transcripts = NULL;
    return 0;
}

int printGrade() {
    Transcript **transcripts = (Transcript **) malloc(100*sizeof(Transcript *));
    TRANSCRIPT_LEN = STUDENTS_LEN;

    for (int i=0; i < STUDENTS_LEN; i++){
        *(transcripts + i) = (Transcript *)malloc(sizeof(Transcript *));
        (*(transcripts + i))->name = (char *)malloc(100*sizeof(char));
        strcpy((*(transcripts + i))->name, (*(STUDENTS+i))->name);
        // (*(transcripts + i))->id = (*(STUDENTS+i))->id;
        (*(transcripts + i))->totalScore = getGrades((*(STUDENTS+i))->id);
    }

    printf("�꼶�ɼ�������:\n");
    quickSort(transcripts);
    printGradeByTranscripts(transcripts);
    free(transcripts);
    transcripts = NULL;
    return 0;
}

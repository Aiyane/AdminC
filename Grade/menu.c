#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // F_OK
#include "include/menu.h"

int inputNum(){
    /**
     * 返回：
     *      -1: 强制退出
     *      -2: 输入错误字符
     *      -3: 没有输入
     *      大于等于 0 的整数
    */

    // 返回结果
    int num = 0;
    // 输入字符串数组
    char *p = NULL, *numChars = (char *)malloc(100 * sizeof(char));
    if (numChars == NULL){
        printf("内存分配失败！\n");
        return -1;
    }
    // 打印输入提示符
    printf("=>> ");

    // 获取输入字符 
    getNum(numChars);

    // 如果没有输入
    if (strlen(numChars) == 0) {
        free(numChars);
        numChars = NULL;
        return -3;
    }

    p = numChars;

    // 强制退出
    if (strcmp(p, "-1") == 0) {
        printf(" ----------\n");
        printf("| 强制退出 |\n");
        printf(" ----------\n\n");
        free(numChars);
        numChars = NULL;
        p = NULL;
        return -1;
    }

    // 获取输入字符 转换成 int
    while (*p != '\0') {
        // 输入了错误字符
        if (*p < '0' || *p > '9') {
            printf("输入错误字符!请输入数字\n");
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
    // 打印输入提示符
    printf("=>> ");

    // 获取输入字符 
    getPwd(pwdChars);

    // 强制退出
    if (strcmp(pwdChars, "-1") == 0) {
        printf(" ----------\n");
        printf("| 强制退出 |\n");
        printf(" ----------\n\n");
        free(pwdChars);
        pwdChars = NULL;
    }
}

void showMenu() {
    printf("\n--菜单-------------------------------\n");
    printf("|||||||   -1.      强制退出   |||||||\n");
    printf("|||||||    0.          退出   |||||||\n");
    printf("|||||||    1.      学生登录   |||||||\n");
    printf("|||||||    2.      老师登录   |||||||\n");
    printf("|||||||    3.          清屏   |||||||\n");
    printf("|||||||    4.      显示菜单   |||||||\n");
    printf("-------------------------------菜单--\n");
    printf("\n");
}

void showTeacherMenu() {
    printf("\n--菜单-------------------------------\n");
    printf("|||||||   -1.      强制退出   |||||||\n");
    printf("|||||||    0.          退出   |||||||\n");
    printf("|||||||    1.      课程编号   |||||||\n");
    printf("|||||||    2.      添加学生   |||||||\n");
    printf("|||||||    3.      添加成绩   |||||||\n");
    printf("|||||||    4.      添加科目   |||||||\n");
    printf("|||||||    5.      修改学生   |||||||\n");
    printf("|||||||    6.      修改成绩   |||||||\n");
    printf("|||||||    7.      修改科目   |||||||\n");
    printf("|||||||    8.      查询成绩   |||||||\n");
    printf("|||||||    9.      统计数目   |||||||\n");
    printf("|||||||    10.     成绩排序   |||||||\n");
    printf("|||||||    11.         清屏   |||||||\n");
    printf("|||||||    12.     显示菜单   |||||||\n");
    printf("-------------------------------菜单--\n");
    printf("\n");
}

void showStudentMenu() {
    printf("\n--菜单-------------------------------\n");
    printf("|||||||   -1.      强制退出   |||||||\n");
    printf("|||||||    0.          退出   |||||||\n");
    printf("|||||||    1.      查询成绩   |||||||\n");
    printf("|||||||    2.      查询排名   |||||||\n");
    printf("|||||||    3.      课程编号   |||||||\n");
    printf("|||||||    4.          清屏   |||||||\n");
    printf("|||||||    5.      显示菜单   |||||||\n");
    printf("-------------------------------菜单--\n");
    printf("\n");
}

void showRankMenu() {
    printf("\n--菜单-------------------------------\n");
    printf("|||||||   -1.      强制退出   |||||||\n");
    printf("|||||||    0.          退出   |||||||\n");
    printf("|||||||    1.      班级排序   |||||||\n");
    printf("|||||||    2.      年级排序   |||||||\n");
    printf("|||||||    3.          清屏   |||||||\n");
    printf("|||||||    4.      显示菜单   |||||||\n");
    printf("-------------------------------菜单--\n");
    printf("\n");
}

 
// #include <stdio.h>
 
// char* Int2String(int num,char *str);//函数声明 
// int main()
// {
// 	int number1 = 123456;
// 	int number2 = -123456;
// 	char string[16] = {0};
// 	Int2String(number1,string);
// 	printf("数字：%d 转换后的字符串为：%s\n",number1,string);
// 	Int2String(number2,string);
// 	printf("数字：%d 转换后的字符串为：%s\n",number2,string);
// 	return 0;
// }
 
// void Int2String(int num,char *str){
//     int i = 0;//指示填充str 
//     if(num<0) {
//         num = -num;
//         str[i++] = '-';
//     } 
//     //转换 
//     do {
//         str[i++] = num%10+48;//取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0' 
//         num /= 10;//去掉最低位	
//     }while(num);//num不为0继续循环

//     str[i] = '\0';

//     //确定开始调整的位置 
//     int j = 0;
//     if(str[0]=='-'){
//         j = 1;//从第二位开始调整 
//         ++i;//由于有负号，所以交换的对称轴也要后移1位 
//     }
//     //对称交换 
//     for(;j<i/2;j++) {
//     //对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b; 
//         str[j] = str[j] + str[i-1-j];
//         str[i-1-j] = str[j] - str[i-1-j];
//         str[j] = str[j] - str[i-1-j];
//     } 
// }


void saveInfoExit() {
    //TODO: 保存当前数据到数据库
    FILE *file;
    char str[100];
    char *student = ".student.txt", *grade = ".grade.txt", *subject = ".subject.txt";
    if ((file = fopen(student, "w")) == NULL) {
        printf("写入学生数据失败, 不能正确关闭!");
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
        printf("写入学科数据失败, 不能正确关闭!");
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
        printf("写入学科数据失败, 不能正确关闭!");
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

    printf("\n退出!\n");
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
     * 增加学生
    */
    int id, zlass;
    char *name = NULL, *pwd = NULL;

    if (STUDENTS_LEN == 100) {
        return -1;
    }

    printf("请输入学号:\n");
    id = inputNum();
    if (id < 0){
        printf("学号输入错误！\n");
        return -1;
    }
    for (int i=0; i<STUDENTS_LEN; i++){
        if ((*(STUDENTS + i))->id == id){
            printf("学号已存在！\n");
            return -1;
        }
    }
    if (id > MAXID){
        printf("学号超过范围！\n");
        return -1;
    }

    printf("请输入班级:\n");
    zlass = inputNum();
    if (zlass < 0){
        printf("班级输入出错！\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("内存分配失败\n");
        return -1;
    }
    printf("请输入学生姓名:\n");
    printf("=>> ");
    gets(name);
    if (strcmp(name, "-1") == 0){
        free(name);
        name = NULL;
        return -1;
    }

    printf("请输入学生密码:\n");
    // 输入字符串数组
    pwd = (char *)malloc(100 * sizeof(char));
    if (pwd == NULL){
        printf("内存分配失败\n");
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

    printf("请输入学号:\n");
    studentId = inputNum();
    if (studentId < 0){
        printf("学号输入错误！\n");
        return -1;
    }

    printf("请输入课程号:\n");
    subjectId = inputNum();
    if (subjectId < 0){
        printf("课程号输入错误！\n");
        return -1;
    }

    printf("请输入分数:\n");
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

    printf("请输入课程编号:\n");
    id = inputNum();
    if (id < 0){
        printf("课程编号输入错误！\n");
        return -1;
    }
    for (int i=0; i<SUBJECTS_LEN; i++){
        if ((*(SUBJECTS + i))->id == id){
            printf("课程编号已存在！\n");
            return -1;
        }
    }
    if (id > MAXID){
        printf("编号超过范围！\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("内存分配失败\n");
        return -1;
    }
    printf("请输入学科名:\n");
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

    printf("请输入学号:\n");
    id = inputNum();
    if (id < 0){
        printf("学号输入错误！\n");
        return -1;
    }
    for (int i=0; i<STUDENTS_LEN; i++){
        if ((*(STUDENTS+i))->id == id){
            student = *(STUDENTS+i);
            break;
        }
    }
    if (!student){
        printf("没有该学生信息！\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("内存分配失败\n");
        return -1;
    }
    printf("请输入新姓名:\n");
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

    printf("请输入修改学生学号:\n");
    id1 = inputNum();
    if (id1 < 0){
        printf("学号输入错误！\n");
        return -1;
    }

    printf("请输入修改学科编号:\n");
    id2 = inputNum();
    if (id2 < 0){
        printf("编号输入错误！\n");
        return -1;
    }

    for (int i=0; i<GRADES_LEN; i++){
        if ((*(GRADES+i))->studentId == id1 && (*(GRADES+i))->subjectId == id2){
            grade = *(GRADES+i);
            break;
        }
    }

    if (!grade){
        printf("没有该学生成绩信息！\n");
        return -1;
    }

    printf("请输入修改后分数:\n");
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

    printf("请输入课程编号:\n");
    id = inputNum();
    if (id < 0){
        printf("课程编号输入错误！\n");
        return -1;
    }
    for (int i=0; i<SUBJECTS_LEN; i++){
        if ((*(SUBJECTS+i))->id == id){
            subject = *(SUBJECTS+i);
            break;
        }
    }
    if (!subject){
        printf("没有该学科！\n");
        return -1;
    }

    name = (char *)malloc(50*sizeof(char));
    if (name == NULL){
        printf("内存分配失败\n");
        return -1;
    }
    printf("请输入新课程名:\n");
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
    printf("%s的成绩为:\n", student->name);
    for (int i=0; i < GRADES_LEN; i++){
        if ((*(GRADES+i))->studentId == student->id){
            printf("%d: %f\n", (*(GRADES+i))->subjectId, (*(GRADES+i))->grade);
        }
    }
}

void rankGrade(Student *student) {
    /**
     * 学生成绩排名
    */
    float totalScore = 0;
    printf("%s的成绩为:\n", student->name);
    for (int i=0; i < GRADES_LEN; i++){
        if ((*(GRADES+i))->studentId == student->id){
            printf("%d: 班级排名: %d\n", (*(GRADES+i))->subjectId, getClassRank(*(GRADES+i), student->zlass));
            printf("%d: 年级排名: %d\n", (*(GRADES+i))->subjectId, getGradeRank(*(GRADES+i)));
            totalScore += (*(GRADES+i))->grade;
        }
    }
    printf("总分排名:\n");
    printf("班级排名: %d\n", getTotalClassRank(totalScore, student->zlass));
    printf("年级排名: %d\n", getTotalGradeRank(totalScore));
}

int selectGradeByTeacher() {
    int id;
    printf("请输入学生学号:\n");
    id = inputNum();
    if (id < 0){
        printf("学号输入错误！\n");
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
    printf("全年级学生总数: %d\n", STUDENTS_LEN);
    int zlass[50] = {0}, i;
    for (i = 0; i < STUDENTS_LEN; i++){
        zlass[(*(STUDENTS + i))->zlass] += 1;
    }
    i = 1;
    while (zlass[i]){
        printf("%d班总人数: %d\n", i, zlass[i]);
        i++;
    }
}

int printClassGrade() {
    printf("请输入班号:\n");
    int zlass, tspIndex=0, j;
    float totalScore;
    zlass = inputNum();
    if (zlass < 0){
        printf("输入错误！\n");
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

    printf("%d班的成绩单如下:\n", zlass);
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

    printf("年级成绩表如下:\n");
    quickSort(transcripts);
    printGradeByTranscripts(transcripts);
    free(transcripts);
    transcripts = NULL;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // F_OK
#include "include/user.h"

Teacher* tLogin(){
    /**
     * 教师登录，需要从文件中查找，因为内存没有提前加载这张表
    */
    int id;
    char *name = ".teacher.txt", *pwd = NULL;

    printf("请输入教师id\n");
    id = inputNum();
    // 输入出现错误
    if (id < 0){
        return NULL;
    }

    printf("请输入密码\n");
    pwd = (char *)malloc(100 * sizeof(char));
    if (pwd == NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    inputPwd(pwd);
    // 强制退出
    if (pwd == NULL){
        free(pwd);
        return NULL;
    }

    FILE *in = NULL;

    // 如果文件不存在，创建该文件。
    if ((access(name, F_OK)) == -1) {
        in = fopen(name, "w");
    } else {
        Teacher* teacher = (Teacher *)malloc(sizeof(Teacher));
        if (teacher == NULL){
            printf("内存分配失败\n");
            return NULL;
        }
        in = fopen(name, "r");
        char chr, *str = NULL;
        int i = 0, j;

        while ((chr = fgetc(in)) != EOF) {
            // 获取下一个单词
            str = (char *)malloc(100 * sizeof(char));
            if (str == NULL){
                printf("内存分配失败\n");
                return NULL;
            }
            for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
                *(str+j) = chr;
                chr = fgetc(in);
            }
            *(str+j) = '\0';

            // 如果是 id
            if (i == 0){
                teacher->id = atoi(str);
                free(str);
                i ++;
            }
            // 如果是 name
            else if (i == 1) {
                teacher->name = (char *)malloc(100 * sizeof(char));
                strcpy(teacher->name, str);
                free(str);
                i ++;
            }
            // 如果是 pwd
            else {
                teacher->pwd = (char *)malloc(100 * sizeof(char));
                strcpy(teacher->pwd, str);
                free(str);
                i = 0;
                // 验证用户名密码
                if (id==teacher->id && strcmp(teacher->pwd, pwd) == 0){
                    printf("教师登录成功!\n");
                    fclose(in);
                    free(pwd);
                    pwd = NULL;
                    str = NULL;
                    name = NULL;
                    in = NULL;
                    return teacher;
                }
            }
        }
    }
    fclose(in);
    pwd = NULL;
    name = NULL;
    in = NULL;
}

Student *sLogin() {
    int id;
    char* pwd = NULL;

    printf("请输入学号\n");
    id = inputNum();
    // 输入出现错误
    if (id < 0){
        return NULL;
    }

    printf("请输入密码\n");
    pwd = (char *)malloc(100 * sizeof(char));
    if (pwd == NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    inputPwd(pwd);
    // 强制退出
    if (pwd == NULL){
        free(pwd);
        pwd = NULL;
        return NULL;
    }

    for (int i=0; i < STUDENTS_LEN; i++){
        if ((*(STUDENTS+i))->id == id){
            if (strcmp((*(STUDENTS+i))->pwd, pwd) == 0){
                free(pwd);
                pwd = NULL;
                return *(STUDENTS+i);
            }
            free(pwd);
            pwd = NULL;
            return NULL;
        }
    }
    pwd = NULL;
    return NULL;
}

void rankAdmin(){
    int Selection = -1;
    showRankMenu();

    while (1){
        Selection = inputNum();

        switch (Selection){
            case -1:
            case 0:
                printf("退出排序管理\n");
                return ;
            // 班级排序
            case 1:
                if (printClassGrade() == -1){
                    printf("排序失败\n");
                }
                break;
            // 年级排序
            case 2:
                if (printGrade() == -1){
                    printf("排序失败\n");
                }
                break;
            // 清屏
            case 3:
                system("cls");
                break;
            // 显示菜单
            case 4:
                showRankMenu();
                break;
            default:
                break;
        }
    }
}

void teacherAdmin(Teacher * teacher){
    /**
     * 教师管理
     *      teacher: 登录的教师
    */
    printf("\n欢迎%s访问学生管理系统\n", teacher->name);
    printf("=====================\n");

    int Selection = -1;
    showTeacherMenu();

    while (1){
        Selection = inputNum();

        switch (Selection){
            // 强制退出与退出
            case -1:
            case 0:
                printf("退出教师登录\n");
                return ;
            case 1:
                showSubject();
                break;
            // 添加学生
            case 2:
                if (addStudent() == -1){
                    printf("添加学生失败！\n");
                }else{
                    printf("添加学生成功！\n");
                }
                break;
            // 添加成绩
            case 3:
                if (addGrade() == -1){
                    printf("添加成绩失败！\n");
                }else{
                    printf("添加成绩成功！\n");
                }
                break;
            // 添加科目
            case 4:
                if (addSubject() == -1){
                    printf("添加学科失败！\n");
                }else{
                    printf("添加学科成功！\n");
                }
                break;
            // 修改学生
            case 5:
                if (modifyName() == -1){
                    printf("修改信息失败！\n");
                }else{
                    printf("修改信息成功！\n");
                }
                break;
            // 修改成绩
            case 6:
                if (modifyGrade() == -1){
                    printf("修改成绩失败！\n");
                }else{
                    printf("修改成绩成功！\n");
                }
                break;
            // 修改科目
            case 7:
                if (modifySubject() == -1){
                    printf("修改课程失败！\n");
                }else{
                    printf("修改课程成功！\n");
                }
                break;
            // 查询成绩
            case 8:
                if (selectGradeByTeacher() == -1){
                    printf("查询失败！\n");
                }
                break;
            // 统计数目
            case 9:
                printStudentNum();
                break;
            // 成绩排序
            case 10:
                rankAdmin();
                showTeacherMenu();
                break;
            // 清屏
            case 11:
                system("cls");
                break;
            // 显示菜单
            case 12:
                showTeacherMenu();
                break;
            // 输入错误或者没有输入
            default:
                break;
        }
    }
}

void studentAdmin(Student * student){
    /**
     * 学生管理
    */
    printf("\n欢迎%s访问学生管理系统\n", student->name);
    printf("=====================\n");

    int Selection = -1;
    showStudentMenu();

    while (1){
        Selection = inputNum();
        switch (Selection){
            // 强制退出与退出
            case -1:
            case 0:
                printf("退出学生登录\n");
                return ;
            // 查询成绩
            case 1:
                selectGrade(student);
                break;
            // 查询排名
            case 2:
                rankGrade(student);
                break;
            // 显示课程号
            case 3:
                showSubject();
                break;
            // 清屏
            case 4:
                system("cls");
                break;
            // 显示菜单
            case 5:
                showStudentMenu();
                break;
            default:
                break;
        }
    }

}

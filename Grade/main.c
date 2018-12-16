#include <stdio.h>
#include <stdlib.h>
#include "include/user.h"

int main(){
    STUDENTS_LEN=0; SUBJECTS_LEN=0; GRADES_LEN=0;
    STUDENTS = (Student **)malloc(100*sizeof(Student *));
    SUBJECTS = (Subject **)malloc(100*sizeof(Subject *));
    GRADES = (Grade **)malloc(100*sizeof(Grade *));
    init();
    printf("\n欢迎访问学生管理系统\n");
    printf("=====================\n");

    int Selection = -1;
    Teacher* teacher = NULL;
    Student* student = NULL;
    showMenu();

    while (1){
        Selection = inputNum();

        switch (Selection){
            // 强制退出与退出
            case -1:
            case 0:
                saveInfoExit();
                return 0;
            // 学生登录
            case 1:
                student = sLogin();
                if (student == NULL){
                    printf("用户名或密码错误！\n");
                }else{
                    studentAdmin(student);
                }
                showMenu();
                break;
            // 老师登录
            case 2:
                teacher = tLogin();
                if (teacher == NULL){
                    printf("用户名或密码错误！\n");
                } else {
                    // 教师管理
                    teacherAdmin(teacher);
                }
                showMenu();
                break;
            // 清屏
            case 3:
                system("cls");
                break;
            // 显示菜单
            case 4:
                showMenu();
                break;
            // 输入错误或者没有输入
            default:
                break;
        }
    }
}

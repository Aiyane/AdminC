#ifndef __MENU_H__
#define __MENU_H__
#include "./func.h"

int inputNum();                     // 获取输入数字
void inputPwd(char *pwd);           // 获取输入密码
void showMenu();                    // 显示菜单栏
void saveInfoExit();                // 保存数据退出
void showTeacherMenu();             // 教师管理界面
void showStudentMenu();             // 学生管理界面
void showRankMenu();                // 排序管理界面
void init();                        // 初始化
int addStudent();                   // 增加学生
int addGrade();                     // 增加成绩
int addSubject();                   // 增加学科
int modifyName();                   // 修改学生名字
int modifyGrade();                  // 修改成绩
int modifySubject();                // 修改课程
void selectGrade(Student *student); // 查询学生成绩
void rankGrade(Student *student);   // 查询学生排名
int selectGradeByTeacher();         // 查询成绩
void printStudentNum();             // 统计学生数目
int printClassGrade();              // 排序班级成绩
int printGrade();                   // 排序年级成绩

#endif
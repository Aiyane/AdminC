#ifndef __USER_H__
#define __USER_H__
#include "./menu.h"

Teacher *tLogin();                   // 教师登录
Student *sLogin();                   // 学生登录
void teacherAdmin(Teacher *teacher); // 教师管理系统
void studentAdmin(Student * student);

#endif
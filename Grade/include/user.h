#ifndef __USER_H__
#define __USER_H__
#include "./menu.h"

Teacher *tLogin();                   // ��ʦ��¼
Student *sLogin();                   // ѧ����¼
void teacherAdmin(Teacher *teacher); // ��ʦ����ϵͳ
void studentAdmin(Student * student);

#endif
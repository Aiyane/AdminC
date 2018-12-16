#ifndef __MENU_H__
#define __MENU_H__
#include "./func.h"

int inputNum();                     // ��ȡ��������
void inputPwd(char *pwd);           // ��ȡ��������
void showMenu();                    // ��ʾ�˵���
void saveInfoExit();                // ���������˳�
void showTeacherMenu();             // ��ʦ�������
void showStudentMenu();             // ѧ���������
void showRankMenu();                // ����������
void init();                        // ��ʼ��
int addStudent();                   // ����ѧ��
int addGrade();                     // ���ӳɼ�
int addSubject();                   // ����ѧ��
int modifyName();                   // �޸�ѧ������
int modifyGrade();                  // �޸ĳɼ�
int modifySubject();                // �޸Ŀγ�
void selectGrade(Student *student); // ��ѯѧ���ɼ�
void rankGrade(Student *student);   // ��ѯѧ������
int selectGradeByTeacher();         // ��ѯ�ɼ�
void printStudentNum();             // ͳ��ѧ����Ŀ
int printClassGrade();              // ����༶�ɼ�
int printGrade();                   // �����꼶�ɼ�

#endif
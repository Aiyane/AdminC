#include <stdio.h>
#include <stdlib.h>
#include "include/user.h"

int main(){
    STUDENTS_LEN=0; SUBJECTS_LEN=0; GRADES_LEN=0;
    STUDENTS = (Student **)malloc(100*sizeof(Student *));
    SUBJECTS = (Subject **)malloc(100*sizeof(Subject *));
    GRADES = (Grade **)malloc(100*sizeof(Grade *));
    init();
    printf("\n��ӭ����ѧ������ϵͳ\n");
    printf("=====================\n");

    int Selection = -1;
    Teacher* teacher = NULL;
    Student* student = NULL;
    showMenu();

    while (1){
        Selection = inputNum();

        switch (Selection){
            // ǿ���˳����˳�
            case -1:
            case 0:
                saveInfoExit();
                return 0;
            // ѧ����¼
            case 1:
                student = sLogin();
                if (student == NULL){
                    printf("�û������������\n");
                }else{
                    studentAdmin(student);
                }
                showMenu();
                break;
            // ��ʦ��¼
            case 2:
                teacher = tLogin();
                if (teacher == NULL){
                    printf("�û������������\n");
                } else {
                    // ��ʦ����
                    teacherAdmin(teacher);
                }
                showMenu();
                break;
            // ����
            case 3:
                system("cls");
                break;
            // ��ʾ�˵�
            case 4:
                showMenu();
                break;
            // ����������û������
            default:
                break;
        }
    }
}

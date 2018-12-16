#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // F_OK
#include "include/user.h"

Teacher* tLogin(){
    /**
     * ��ʦ��¼����Ҫ���ļ��в��ң���Ϊ�ڴ�û����ǰ�������ű�
    */
    int id;
    char *name = ".teacher.txt", *pwd = NULL;

    printf("�������ʦid\n");
    id = inputNum();
    // ������ִ���
    if (id < 0){
        return NULL;
    }

    printf("����������\n");
    pwd = (char *)malloc(100 * sizeof(char));
    if (pwd == NULL){
        printf("�ڴ����ʧ��\n");
        return NULL;
    }
    inputPwd(pwd);
    // ǿ���˳�
    if (pwd == NULL){
        free(pwd);
        return NULL;
    }

    FILE *in = NULL;

    // ����ļ������ڣ��������ļ���
    if ((access(name, F_OK)) == -1) {
        in = fopen(name, "w");
    } else {
        Teacher* teacher = (Teacher *)malloc(sizeof(Teacher));
        if (teacher == NULL){
            printf("�ڴ����ʧ��\n");
            return NULL;
        }
        in = fopen(name, "r");
        char chr, *str = NULL;
        int i = 0, j;

        while ((chr = fgetc(in)) != EOF) {
            // ��ȡ��һ������
            str = (char *)malloc(100 * sizeof(char));
            if (str == NULL){
                printf("�ڴ����ʧ��\n");
                return NULL;
            }
            for (j = 0; chr != 10 && chr != 32 && chr != EOF; j++) {
                *(str+j) = chr;
                chr = fgetc(in);
            }
            *(str+j) = '\0';

            // ����� id
            if (i == 0){
                teacher->id = atoi(str);
                free(str);
                i ++;
            }
            // ����� name
            else if (i == 1) {
                teacher->name = (char *)malloc(100 * sizeof(char));
                strcpy(teacher->name, str);
                free(str);
                i ++;
            }
            // ����� pwd
            else {
                teacher->pwd = (char *)malloc(100 * sizeof(char));
                strcpy(teacher->pwd, str);
                free(str);
                i = 0;
                // ��֤�û�������
                if (id==teacher->id && strcmp(teacher->pwd, pwd) == 0){
                    printf("��ʦ��¼�ɹ�!\n");
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

    printf("������ѧ��\n");
    id = inputNum();
    // ������ִ���
    if (id < 0){
        return NULL;
    }

    printf("����������\n");
    pwd = (char *)malloc(100 * sizeof(char));
    if (pwd == NULL){
        printf("�ڴ����ʧ��\n");
        return NULL;
    }
    inputPwd(pwd);
    // ǿ���˳�
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
                printf("�˳��������\n");
                return ;
            // �༶����
            case 1:
                if (printClassGrade() == -1){
                    printf("����ʧ��\n");
                }
                break;
            // �꼶����
            case 2:
                if (printGrade() == -1){
                    printf("����ʧ��\n");
                }
                break;
            // ����
            case 3:
                system("cls");
                break;
            // ��ʾ�˵�
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
     * ��ʦ����
     *      teacher: ��¼�Ľ�ʦ
    */
    printf("\n��ӭ%s����ѧ������ϵͳ\n", teacher->name);
    printf("=====================\n");

    int Selection = -1;
    showTeacherMenu();

    while (1){
        Selection = inputNum();

        switch (Selection){
            // ǿ���˳����˳�
            case -1:
            case 0:
                printf("�˳���ʦ��¼\n");
                return ;
            case 1:
                showSubject();
                break;
            // ���ѧ��
            case 2:
                if (addStudent() == -1){
                    printf("���ѧ��ʧ�ܣ�\n");
                }else{
                    printf("���ѧ���ɹ���\n");
                }
                break;
            // ��ӳɼ�
            case 3:
                if (addGrade() == -1){
                    printf("��ӳɼ�ʧ�ܣ�\n");
                }else{
                    printf("��ӳɼ��ɹ���\n");
                }
                break;
            // ��ӿ�Ŀ
            case 4:
                if (addSubject() == -1){
                    printf("���ѧ��ʧ�ܣ�\n");
                }else{
                    printf("���ѧ�Ƴɹ���\n");
                }
                break;
            // �޸�ѧ��
            case 5:
                if (modifyName() == -1){
                    printf("�޸���Ϣʧ�ܣ�\n");
                }else{
                    printf("�޸���Ϣ�ɹ���\n");
                }
                break;
            // �޸ĳɼ�
            case 6:
                if (modifyGrade() == -1){
                    printf("�޸ĳɼ�ʧ�ܣ�\n");
                }else{
                    printf("�޸ĳɼ��ɹ���\n");
                }
                break;
            // �޸Ŀ�Ŀ
            case 7:
                if (modifySubject() == -1){
                    printf("�޸Ŀγ�ʧ�ܣ�\n");
                }else{
                    printf("�޸Ŀγ̳ɹ���\n");
                }
                break;
            // ��ѯ�ɼ�
            case 8:
                if (selectGradeByTeacher() == -1){
                    printf("��ѯʧ�ܣ�\n");
                }
                break;
            // ͳ����Ŀ
            case 9:
                printStudentNum();
                break;
            // �ɼ�����
            case 10:
                rankAdmin();
                showTeacherMenu();
                break;
            // ����
            case 11:
                system("cls");
                break;
            // ��ʾ�˵�
            case 12:
                showTeacherMenu();
                break;
            // ����������û������
            default:
                break;
        }
    }
}

void studentAdmin(Student * student){
    /**
     * ѧ������
    */
    printf("\n��ӭ%s����ѧ������ϵͳ\n", student->name);
    printf("=====================\n");

    int Selection = -1;
    showStudentMenu();

    while (1){
        Selection = inputNum();
        switch (Selection){
            // ǿ���˳����˳�
            case -1:
            case 0:
                printf("�˳�ѧ����¼\n");
                return ;
            // ��ѯ�ɼ�
            case 1:
                selectGrade(student);
                break;
            // ��ѯ����
            case 2:
                rankGrade(student);
                break;
            // ��ʾ�γ̺�
            case 3:
                showSubject();
                break;
            // ����
            case 4:
                system("cls");
                break;
            // ��ʾ�˵�
            case 5:
                showStudentMenu();
                break;
            default:
                break;
        }
    }

}

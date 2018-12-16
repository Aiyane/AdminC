#ifndef __FUNC_H__
#define __FUNC_H__
#include "./model.h"

void getNum(char *num);                                 // 获取数字
void getPwd(char *pwd);                                 // 获取密码
void initStudents();                                    // 初始化学生
void initSubjects();                                    // 初始化学科
void initGrades();                                      // 初始化成绩
float getGrades(int id);                                // 获取学生成绩
int getClassRank(Grade *grade, int zlass);              // 获取班级排名
int getGradeRank(Grade *grade);                         // 获取年级排名
int getTotalClassRank(float totalScore, int classID);   // 总分班级排名
int getTotalGradeRank(float totalScore);                // 总分年级排名
void quickSort(Transcript **transcripts);               // 快速排序成绩
void printGradeByTranscripts(Transcript **transcripts); // 打印成绩
void showSubject();                                     // 显示课程号

#endif
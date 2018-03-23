#ifndef __MENU_H__
#define __MENU_H__
#include "func.h"

void showMenu();          // 声明输出菜单函数
int add();                // 声明添加卡函数
void query();             // 声明查询卡函数
int login();              // 声明上机函数
int settle();             // 声明下机函数
int annul();              // 声明注销卡函数
int addMoney();           // 声明充值函数
int refundMoney();        // 声明退费函数
void init();              // 声明初始化函数
int standAdd();           // 声明增加标准函数
int standChange();        // 声明改变标准函数
void checkMoney();        // 声明查看营业额函数
int checkUserMoney();     // 声明查看用户消费记录函数
int delStand();           // 声明删除标准函数
void showStand();         // 声明显示标准函数
int inputNum(char *num1); // 声明输入数字函数
int shutdown();          // 声明退出系统

#endif
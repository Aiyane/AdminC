#ifndef __FUNC_H__
#define __FUNC_H__
#include "model.h"

int store(User *a);                 // 储存用户
void check();                       // 查看全部用户信息
int checkUser(int num, char *pwd);  // 检查用户是否存在
User *getUser(int num);             // 获得用户
int startLogin(User *a);            // 上机
int endLogin(User *a);              // 下机
int delUser(int num);               // 删除用户
int moneyAdd(int num, int money);   // 充值
int moneyRefund(int num, int money);// 退费
void standShow();                   // 显示标准
void initStand();                   // 初始化标准
void addStand(int num);             // 增加标准
void changeStand(int num);          // 改变标准
void moneyCheck();                  // 检查总营业额
void userMoney(int num);            // 检查用户消费金额
int standDel(int num);              // 删除标准
int shuttle();                     // 退出系统

#endif
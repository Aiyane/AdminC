#ifndef __FUNC_H__
#define __FUNC_H__
#include "model.h"

int store(User *a);
void check();
int checkUser(int num, char *pwd);
User *getUser(int num);
int startLogin(User *a);
int endLogin(User *a);
int delUser(int num);
int moneyAdd(int num, int money);
int moneyRefund(int num, int money);
void standShow();
void initStand();
void addStand(int num);
void changeStand(int num);
void moneyCheck();
void userMoney(int num);
int standDel(int num);

#endif
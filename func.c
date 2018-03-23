#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/model.h"
#include "include/func.h"

User userList[100];
Stand standList[100];
Stand stand;
int MONEY = 0;

/*
返回当前时间
*/
int now()
{
    time_t t;
    struct tm *lt;
    time(&t);
    lt = localtime(&t);
    // printf("当前时间: %d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    return (lt->tm_min + (lt->tm_hour * 60));
}

/*
初始化标准
*/
void initStand()
{
    FILE *in;
    char name[10] = ".temp.txt";
    standList[0].num = 10;
    standList[0].select = 1;
    stand = standList[0];
    if ((access(name, F_OK)) == -1)
    {  // 如果文件不存在
        in = fopen(name, "w");
        fclose(in);
    }
    in = fopen(name, "r");
    int i = 0, j = 0;
    int num;
    int money;
    char *password = (char *)malloc(100 * sizeof(char));
    char chr;
    User a;
    while ((chr = fgetc(in)) != EOF)
    {
        num = (int)chr;
        fgetc(in);
        money = (int)fgetc(in);
        fgetc(in);
        chr = fgetc(in);
        while (chr != 10)
        {
            password[i] = chr;
            i++;
            chr = fgetc(in);
        }
        i = 0;
        a.num = num;
        a.money = money;
        a.password = password;
        a.time = 0;
        a.ifStart = 0;
        a.charge = 0;
        a.endTime = 0;
        userList[j] = a;
        j++;
    }
    fclose(in);
}

/*
开办新卡
*/
int store(User *a)
{
    for (int i = 0; i < 99; i++)
    {
        if (userList[i].num == a->num)
        {
            printf("\n卡号已被注册\n");
            printf("============\n\n");
            return 0;
        }
        if (!userList[i].num)
        {
            userList[i] = *a;
            printf("\n开卡成功!\n");
            printf("=========\n\n");
            return 1;
        }
    }
    printf("\n用户已满!\n");
    printf("=========\n\n");
    return -1;
}

void check()
{
    int i = 0;
    printf("\n");
    while (1)
    {
        if (userList[i].num)
        {
            if (userList[i].ifStart == 1)
            {
                int spendTime = now() - userList[i].time;
                printf("卡号: %d 余额: %d", userList[i].num, userList[i].money - (int)((spendTime / 60.0) * stand.num));
                printf(" 登录中...\n");
            }
            else
            {
                printf("卡号: %d 余额: %d", userList[i].num, userList[i].money);
                printf(" 未登录\n");
            }
        }
        else
            break;
        i++;
    }
    printf("=========================\n\n");
}

int checkUser(int num, char *pwd)
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].num == num)
        {
            if (strcmp(userList[i].password, pwd) == 0)
            {
                return 1;
            }
            return 0;
        }
        i++;
    }
    return 0;
}

User *getUser(int num)
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].num == num)
            return &userList[i];
        i++;
    }
}

int startLogin(User *a)
{
    if (a->money > 0 && a->ifStart == 0)
    {
        a->time = now();
        printf("\n用户 %d 上机成功!\n", a->num);
        a->ifStart = 1;
        return 1;
    }
    else if (a->ifStart == 1)
        return -1;
    else
        return 0;
}

int endLogin(User *a)
{
    if (a->money > 0 && a->ifStart == 1)
    {
        a->endTime = now() - a->time;
        printf("\n用户 %d 下机成功!\n", a->num);
        int spendTime = now() - a->time;
        int spendMoney = (int)((spendTime / 60.0) * stand.num);
        a->charge = spendMoney;
        MONEY += spendMoney;
        a->money = a->money - spendMoney;
        printf("卡号: %d 余额: %d\n", a->num, a->money);
        a->ifStart = 0;
        return 1;
    }
    else if (a->ifStart == 0)
        return -1;
    else
        return 0;
}

int delUser(int num)
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].num == num)
        {
            for (i; i < 99; i++)
                userList[i] = userList[i + 1];
            return 1;
        }
        i++;
    }
    return 0;
}

int moneyAdd(int num, int money)
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].num == num)
        {
            userList[i].money += money;
            return 1;
        }
        i++;
    }
    return 0;
}

int moneyRefund(int num, int money)
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].num == num)
        {
            if (userList[i].money < money)
                return userList[i].money;
            userList[i].money -= money;
            return -1;
        }
        i++;
    }
}

void standShow()
{
    printf("\n");
    int i = 0;
    while (standList[i].num)
    {
        if (standList[i].select)
        {
            printf("标准%d: 每小时收费 %d 元(当前标准)\n", i, standList[i].num);
        }
        else
            printf("标准%d: 每小时收费 %d 元\n", i, standList[i].num);
        i++;
    }
    printf("=================================\n");
    printf("\n");
}

void addStand(int num)
{
    int i = 0;
    while (standList[i].num)
        i++;
    standList[i].num = num;
    standList[i].select = 0;
    printf("新增标准%d: 每小时 %d 元\n", i, num);
    printf("==========================\n\n");
}

void changeStand(int num)
{
    if (standList[num].num)
    {
        int i = 0;
        printf("结算已上机用户, 再按新标准重新上机!\n");
        while (userList[i].num)
        {
            if (userList[i].ifStart)
            {
                endLogin(&userList[i]);
                startLogin(&userList[i]);
            }
            i++;
        }
        standList[num].select = 1;
        stand = standList[num];
        i = 0;
        while (standList[i].num)
        {
            if (i == num)
            {
                i++;
                continue;
            }
            standList[i].select = 0;
            i++;
        }
        printf("成功切换到 标准%d\n", num);
    }
    else
        printf("没有该标准!\n");
    printf("====================\n\n");
}

void moneyCheck()
{
    int i = 0;
    int tem = 0;
    while (userList[i].num)
    {
        if (userList[i].ifStart)
        {
            int spendTime = now() - userList[i].time;
            int spendMoney = (int)((spendTime / 60.0) * stand.num);
            tem += spendMoney;
        }
        i++;
    }
    printf("总营业额: %d\n", MONEY + tem);
    printf("==================\n\n");
}

void userMoney(int num)
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].num == num)
        {
            if (userList[i].ifStart)
            {
                int spendTime = now() - userList[i].time;
                int spendMoney = (int)((spendTime / 60.0) * stand.num);
                printf("\n该用户一共消费 %d 元\n", userList[i].charge + spendMoney);
            }
            else
                printf("\n该用户一共消费 %d 元\n", userList[i].charge);
            break;
        }
        i++;
    }
    printf("====================\n\n");
}

int standDel(int num)
{
    if (standList[num].num)
    {
        if (standList[num].select == 1)
        {
            printf("\n该标准被选择, 不能删除!\n");
            printf("=================\n\n");
            return 0;
        }
        int i = num;
        while (standList[i].num)
        {
            standList[i] = standList[i + 1];
            i++;
        }
        printf("\n成功删除标准%d\n", num);
        printf("=================\n\n");
        return 1;
    }
    else
    {
        printf("\n没有该标准\n");
        printf("=================\n\n");
    }
    return 0;
}

int shuttle()
{
    int i = 0;
    while (userList[i].num)
    {
        if (userList[i].ifStart)
        {
            endLogin(&userList[i]);
        }
        i++;
    }
    FILE *file;
    char a[10] = ".temp.txt";
    if ((file = fopen(a, "w")) == NULL)
    {
        printf("写入用户数据失败, 不能正确关闭!");
        return -1;
        fclose(file);
    }
    for (int i = 0; i < 99; i++)
    {
        if (userList[i].num)
        {
            fputc(userList[i].num, file);
            fputs(":", file);
            fputc(userList[i].money, file);
            fputs(":", file);
            fputs(userList[i].password, file);
            fputs("\n", file);
        }
        else
        {
            break;
        }
    }
    fclose(file);
    return 0;
}

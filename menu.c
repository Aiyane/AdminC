#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termio.h>
#include "include/model.h"
#include "include/menu.h"

/*
不回显的接受字符
*/
int getch(void)
{
    struct termios tm, tm_old;
    int fd = 0, ch;

    if (tcgetattr(fd, &tm) < 0)
    { //保存现在的终端设置
        return -1;
    }

    tm_old = tm;
    cfmakeraw(&tm); //更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
    if (tcsetattr(fd, TCSANOW, &tm) < 0)
    { //设置上更改之后的设置
        return -1;
    }

    ch = getchar();
    if (tcsetattr(fd, TCSANOW, &tm_old) < 0)
    { //更改设置为最初的样子
        return -1;
    }

    return ch;
}

//获取密码，密码字符串pwd和pwd长度pwd_len
int getpwd(char *pwd, int pwd_len)
{
    int i = 0;
    char let = 0, ch = '*';
    while (i <= pwd_len && let != '\r' && let != '\n')
    {
        let = getch();
        if (let != '\b' && let != 127)
        {
            pwd[i++] = let;
            putchar(ch);
        }
        else
        {
            if (i > 0)
            {
                pwd[--i] = 0;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        }
    }
    if (let != '\n')
        --i;
    pwd[i] = 0;
    putchar('\b');
    putchar(' ');
    putchar('\b');
    if (strcmp(pwd, "-1") == 0)
    {
        printf("\n ----------\n");
        printf("| 强制退出 |\n");
        printf(" ----------\n\n");
        return -2;
    }
}

/*
获取数字
*/
void getNum(char *num)
{
    int i = 0;
    char let = 0;
    while (i <= 100 && let != '\r' && let != '\n')
    {
        let = getch();
        if (let != '\b' && let != 127)
        {
            num[i++] = let;
            putchar(let);
        }
        else
        {
            if (i > 0)
            {
                num[--i] = 0;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        }
    }
    if (let != '\n')
        --i;
    num[i] = 0;
    putchar('\n');
}

int inputNum(char *num1)
{
    int num = 0;
    while (1)
    {
        getNum(num1);
        if (strlen(num1) == 0)
            return -3;
        break;
    }
    while (*num1)
    {
        if (strcmp(num1, "-1") == 0)
        {
            printf(" ----------\n");
            printf("| 强制退出 |\n");
            printf(" ----------\n\n");
            return -2;
        }
        if (*num1 < '0' || *num1 > '9')
        {
            printf("必须输入整数!\n");
            return -1;
        }
        num = num * 10 + (*num1 - '0');
        num1++;
    }
    return num;
}

/*
初始化
*/
void init()
{
    initStand();
}

/*
输出菜单函数
*/
void showMenu()
{
    printf("\n--菜单-------------------------------\n");
    printf("|||||||   -1.      强制退出   |||||||\n");
    printf("|||||||    0.          退出   |||||||\n");
    printf("|||||||    1.          添加   |||||||\n");
    printf("|||||||    2.          查询   |||||||\n");
    printf("|||||||    3.          上机   |||||||\n");
    printf("|||||||    4.          下机   |||||||\n");
    printf("|||||||    5.          充值   |||||||\n");
    printf("|||||||    6.          退费   |||||||\n");
    printf("|||||||    7.          注销   |||||||\n");
    printf("|||||||    8.          清屏   |||||||\n");
    printf("|||||||    9.      显示标准   |||||||\n");
    printf("|||||||   10.      新增标准   |||||||\n");
    printf("|||||||   11.      更改标准   |||||||\n");
    printf("|||||||   12.      删除标准   |||||||\n");
    printf("|||||||   13.      显示帮助   |||||||\n");
    printf("|||||||   14.    查看营业额   |||||||\n");
    printf("|||||||   15.  查看消费记录   |||||||\n");
    printf("-------------------------------菜单--\n");
    printf("\n");
}

/*
添加卡函数
*/
int add()
{
    int money;
    char *password = (char *)malloc(100 * sizeof(char));
    char *num1 = (char *)malloc(100 * sizeof(char));
    int num = 0;
    while (1)
    {
        printf("\n请输入添加的卡号: ");
        num = inputNum(num1);
        if (num == -2)
            return 0;
        if (num == -1 || num == -3)
            continue;
        break;
    }
    while (1)
    {
        printf("请输入密码(2~12): ");
        if (getpwd(password, 100) == -2)
        {
            return 0;
        }

        char *password1 = (char *)malloc(100 * sizeof(char));
        printf("\n请再次输入密码: ");
        if (getpwd(password1, 100) == -2)
        {
            return 0;
        }
        if (strcmp(password, password1) != 0)
        {
            printf("\n两次输入不一致!\n");
            continue;
        }

        int pwdLong = strlen(password);
        if (pwdLong > 12 || pwdLong < 3)
        {
            printf("\n密码长度错误\n");
            continue;
        }
        break;
    }
    while (1)
    {
        printf("\n请输入开卡金额: ");
        money = inputNum(num1);
        if (money == -2)
            return 0;
        if (money == -1 || money == -3)
            continue;
        break;
    }
    User a = {num, password, money, 0, 0, 0, 0};
    store(&a);
}

/*
查询卡函数
*/
void query()
{
    check();
}

/*上机函数*/
int login()
{
    while (1)
    {
        int num;
        char *num1 = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\n请输入卡号: ");
            num = inputNum(num1);
            if (num == -2)
                return 0;
            if (num == -1 || num == -3)
                continue;
            break;
        }
        printf("请输入密码: ");
        char *pwd = (char *)malloc(100 * sizeof(char));
        if (getpwd(pwd, 100) == -2)
            return 0;
        User *a;
        if (checkUser(num, pwd))
        {
            a = getUser(num);
            if (startLogin(a) == 1)
            {
                printf("============================\n\n");
                break;
            }
            else if (startLogin(a) == -1)
            {
                printf("\n已经是上机状态\n");
                printf("===============\n\n");
                break;
            }
            else
            {
                printf("\n余额不足!\n");
                printf("============\n\n");
            }
        }
        else
        {
            printf("\n卡号或密码错误!\n");
            printf("==================\n\n");
        }
    }
}

/*
下机函数
*/
int settle()
{
    while (1)
    {
        int num;
        char *num1 = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\n请输入卡号: ");
            num = inputNum(num1);
            if (num == -2)
                return 0;
            if (num == -1 || num == -3)
                continue;
            break;
        }
        printf("请输入密码: ");
        char *pwd = (char *)malloc(100 * sizeof(char));
        if (getpwd(pwd, 100) == -2)
            return 0;
        User *a;
        if (checkUser(num, pwd))
        {
            a = getUser(num);
            if (endLogin(a) == 1)
            {
                printf("============================\n\n");
                break;
            }
            else if (endLogin(a) == -1)
            {
                printf("\n已经是下机状态\n");
                printf("===============\n\n");
                break;
            }
            else
            {
                printf("\n余额不足请缴费!\n");
                printf("======================\n\n");
            }
        }
        else
        {
            printf("\n卡号或密码错误!\n");
            printf("==================\n\n");
        }
    }
}

/*注销卡函数*/
int annul()
{
    while (1)
    {
        int num;
        char *num1 = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\n请输入卡号: ");
            num = inputNum(num1);
            if (num == -2)
                return 0;
            if (num == -1 || num == -3)
                continue;
            break;
        }
        printf("请输入密码: ");
        char *pwd = (char *)malloc(100 * sizeof(char));
        if (getpwd(pwd, 100) == -2)
            return 0;
        User *a;
        if (checkUser(num, pwd))
        {
            if (delUser(num))
            {
                printf("\n成功删除卡号为: %d 的用户\n", num);
                printf("============================\n\n");
                break;
            }
        }
        else
        {
            printf("\n用户名或密码错误!\n");
        }
    }
}

/*
充值函数
*/
int addMoney()
{
    while (1)
    {
        int num;
        char *num1 = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\n请输入卡号: ");
            num = inputNum(num1);
            if (num == -2)
                return 0;
            if (num == -1 || num == -3)
                continue;
            break;
        }
        printf("请输入密码: ");
        char *pwd = (char *)malloc(100 * sizeof(char));
        if (getpwd(pwd, 100) == -2)
            return 0;
        User *a;
        if (checkUser(num, pwd))
        {
            int money;
            while (1)
            {
                printf("\n请输入充值金额: ");
                money = inputNum(num1);
                if (money == -2)
                    return 0;
                if (money == -1 || money == -3)
                    continue;
                break;
            }
            if (moneyAdd(num, money))
            {
                printf("\n卡号为: %d 的用户, 成功充值 %d 元\n", num, money);
                printf("===================================\n\n");
                break;
            }
        }
        else
        {
            printf("\n用户名或密码错误!");
        }
    }
}

/*
退费函数
*/
int refundMoney()
{
    while (1)
    {
        int num;
        char *num1 = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\n请输入卡号: ");
            num = inputNum(num1);
            if (num == -2)
                return 0;
            if (num == -1 || num == -3)
                continue;
            break;
        }
        printf("请输入密码: ");
        char *pwd = (char *)malloc(100 * sizeof(char));
        if (getpwd(pwd, 100) == -2)
            return 0;
        User *a;
        if (checkUser(num, pwd))
        {
            int money;
            while (1)
            {
                printf("\n请输入退款金额: ");
                money = inputNum(num1);
                if (money == -2)
                    return 0;
                if (money == -1 || money == -3)
                    continue;
                break;
            }
            if (moneyRefund(num, money) == -1)
            {
                printf("\n卡号为: %d 的用户, 成功退款 %d 元\n", num, money);
                printf("===================================\n\n");
                break;
            }
            else
                printf("\n金额错误! 目前账户还剩余额: %d\n", moneyRefund(num, money));
        }
        else
        {
            printf("\n用户名或密码错误!");
        }
    }
}

/*
显示收费标准
*/
void showStand()
{
    standShow();
}

/*
增加标准
*/
int standAdd()
{
    char *num1 = (char *)malloc(100 * sizeof(char));
    int num = 0;
    while (1)
    {
        printf("\n请输入新标准金额(元/小时): ");
        num = inputNum(num1);
        if (num == -2)
            return 0;
        if (num == -1 || num == -3)
            continue;
        break;
    }
    addStand(num);
}

/*
更改标准
*/
int standChange()
{
    char *num1 = (char *)malloc(100 * sizeof(char));
    int num = 0;
    while (1)
    {
        printf("\n请输入标准序号: ");
        num = inputNum(num1);
        if (num == -2)
            return 0;
        if (num == -1 || num == -3)
            continue;
        break;
    }
    changeStand(num);
}

/*
查看营业额
*/
void checkMoney()
{
    printf("\n");
    moneyCheck();
}

/*
查看消费记录
*/
int checkUserMoney()
{
    while (1)
    {
        int num;
        char *num1 = (char *)malloc(100 * sizeof(char));
        while (1)
        {
            printf("\n请输入卡号: ");
            num = inputNum(num1);
            if (num == -2)
                return 0;
            if (num == -1 || num == -3)
                continue;
            break;
        }
        printf("请输入密码: ");
        char *pwd = (char *)malloc(100 * sizeof(char));
        if (getpwd(pwd, 100) == -2)
            return 0;
        if (checkUser(num, pwd))
        {
            userMoney(num);
            break;
        }
        else
        {
            printf("\n用户名或密码错误!");
        }
    }
}

/*
删除标准
*/
int delStand()
{
    char *num1 = (char *)malloc(100 * sizeof(char));
    int num = 0;
    while (1)
    {
        printf("请输入待删除标准的序号: ");
        num = inputNum(num1);
        if (num == -2)
            return 0;
        if (num == -1 || num == -3)
            continue;
        if (standDel(num))
            break;
    }
}
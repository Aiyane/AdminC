#include <stdio.h>
#include <stdlib.h>
#include "include/menu.h"
void clear();

int main()
{
    init();
    printf("\n欢迎进入计费管理系统!\n");
    printf("=====================\n");
    int Selection = -1;
    showMenu();

    while (1)
    {
        char *num1 = (char *)malloc(100 * sizeof(char));
        int Selection = -1;
        while (1)
        {
            printf("=>> ");
            Selection = inputNum(num1);
            if (Selection == -2 || Selection == 0)
            {
                if(shutdown() == -1){
                    continue;
                } 
                printf("\n再见!\n");
                printf("=====\n\n");
                return 0;
            }
            if (Selection == -1 || Selection == -3 || Selection > 15 || Selection < 0)
                continue;
            break;
        }
        switch (Selection)
        {
        case 1: // 添加卡
            add();
            break;
        case 2: // 查询卡
            query();
            break;
        case 3: // 上机
            login();
            break;
        case 4: // 下机
            settle();
            break;
        case 5: // 充值
            addMoney();
            break;
        case 6: // 退费
            refundMoney();
            break;
        case 7: // 注销卡
            annul();
            break;
        case 8: // 清屏
            clear();
            break;
        case 9: // 显示标准
            showStand();
            break;
        case 10: // 增加标准
            standAdd();
            break;
        case 11: // 改变标准
            standChange();
            break;
        case 12: // 删除标准
            delStand();
            break;
        case 13: // 显示帮助
            showMenu();
            break;
        case 14: // 查看营业额
            checkMoney();
            break;
        case 15: // 查看消费记录
            checkUserMoney();
            break;
        }
    }
}
/*
清屏
*/
void clear()
{
    #ifdef __GNUC__
    system("clear");
    #elif defined _MSC_VER
    system("cls");
    #endif
}
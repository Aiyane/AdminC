#ifndef __MODEL_H__
#define __MODEL_H__

typedef struct client
{
    int num;
    char *password;
    int money;
    int time;
    int endTime;
    int ifStart;
    int charge;
} User;

typedef struct
{
    int num;
    int select;
} Stand;

#endif
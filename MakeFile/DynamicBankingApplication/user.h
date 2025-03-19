#ifndef USER_H
#define USER_H

#include <stdio.h>

// Ensure packed structure to avoid padding
#pragma pack(push, 1)
typedef struct {
    char name[10];
    int account_no;
    float balance;
} User;
#pragma pack(pop)

#endif

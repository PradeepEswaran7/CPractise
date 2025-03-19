#ifndef USER_H
#define USER_H

#define USER_COUNT 2
#define RECORD_SIZE 32

typedef struct {
    char name[20];
    int account_no;
    float balance;
} User;

void print_user(User user);

#endif

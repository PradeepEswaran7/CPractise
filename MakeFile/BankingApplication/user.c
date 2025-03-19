#include <stdio.h>
#include "user.h"

void print_user(User user) {
    printf("Name: %s\n", user.name);
    printf("Account No: %d\n", user.account_no);
    printf("Balance: %.2f\n\n", user.balance);
}

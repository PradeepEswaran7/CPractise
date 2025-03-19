#include <stdio.h>
#include <string.h>
#include "memory.h"

int store_user_data(User *user, char *memory, int *used_memory) {
    printf("Used memory: %d, Remaining memory: %d\n", *used_memory, MEMORY_SIZE - *used_memory);

    if (*used_memory + sizeof(User) > MEMORY_SIZE) {
        printf("Not enough memory to store user. Required: %zu, Available: %d\n",
               sizeof(User), MEMORY_SIZE - *used_memory);
        return 0;  // Not enough memory
    }

    memcpy(memory + *used_memory, user, sizeof(User));
    *used_memory += sizeof(User);

    printf("Stored user. Updated used memory: %d\n", *used_memory);
    return 1;  // Successfully stored the user
}

void print_user_data(const char *memory, int used_memory) {
    int offset = 0;

    while (offset < used_memory) {
        User user;
        memcpy(&user, memory + offset, sizeof(User));
        offset += sizeof(User);

        printf("Name: %s, Account No: %d, Balance: %.2f\n",
               user.name, user.account_no, user.balance);
    }
}

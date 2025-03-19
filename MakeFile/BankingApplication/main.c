#include <stdio.h>
#include "memory.h"
#include "user.h"

int main() {
    User users[USER_COUNT] = {
        {"Alice", 12345, 1000.50},
        {"Bob", 67890, 2000.75}
    };

    char memory[USER_COUNT * RECORD_SIZE];

    for (int i = 0; i < USER_COUNT; i++) {
        store_user_data(users, memory, i);
    }

    User retrieved_user;
    for (int i = 0; i < USER_COUNT; i++) {
        read_user_data(&retrieved_user, memory, i);
        print_user(retrieved_user);
    }

    return 0;
}

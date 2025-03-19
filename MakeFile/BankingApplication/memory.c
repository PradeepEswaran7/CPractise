#include <string.h>
#include "memory.h"

void store_user_data(User users[], char *memory, int index) {
    memcpy(memory + (index * RECORD_SIZE), &users[index], sizeof(User));
}

void read_user_data(User *user, char *memory, int index) {
    memcpy(user, memory + (index * RECORD_SIZE), sizeof(User));
}

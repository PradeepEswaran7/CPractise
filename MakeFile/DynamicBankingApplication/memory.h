#ifndef MEMORY_H
#define MEMORY_H

#include "user.h"

#define MEMORY_SIZE 64  // Shared memory size definition

// Store user data in memory
int store_user_data(User *user, char *memory, int *used_memory);

// Print all user data from memory
void print_user_data(const char *memory, int used_memory);

#endif

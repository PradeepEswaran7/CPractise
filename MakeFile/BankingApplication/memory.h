#ifndef MEMORY_H
#define MEMORY_H

#include "user.h"

void store_user_data(User users[], char *memory, int index);
void read_user_data(User *user, char *memory, int index);

#endif

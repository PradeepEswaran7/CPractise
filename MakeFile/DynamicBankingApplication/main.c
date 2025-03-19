#include <stdio.h>
#include <string.h>
#include "user.h"
#include "memory.h"

int main() {
    char memory[MEMORY_SIZE] = {0};  // Fixed-size memory block
    int used_memory = 0;            // Tracks how much memory is used

    printf("Size of User: %zu bytes\n", sizeof(User));
    printf("Total memory available: %d bytes\n", MEMORY_SIZE);

    while (1) {
        User user;
        printf("Enter user details (Name AccountNo Balance): ");
        if (scanf("%9s %d %f", user.name, &user.account_no, &user.balance) != 3) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        // Attempt to store user data in memory
        if (!store_user_data(&user, memory, &used_memory)) {
            printf("No memory left to store user data.\n");
            break;
        }

        // Ask the user if they want to continue
        printf("Do you want to add another user? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // Display stored user data
    printf("\nStored user data:\n");
    print_user_data(memory, used_memory);

    return 0;
}

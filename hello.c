#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 100  // Define the size of each chunk to be read

int main() {
    FILE *fptr;
    char *buffer;
    size_t bytesRead;
    size_t totalSize = 0;

    // Open the file in read mode
    fptr = fopen("1gb_file.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Allocate initial memory for the buffer
    buffer = (char *)malloc(CHUNK_SIZE * sizeof(char)); // Fixed memory allocation
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(fptr);
        return 1;
    }

    printf("File content:\n");

    while (1) {
        // Read the next chunk from the file
        bytesRead = fread(buffer, sizeof(char), CHUNK_SIZE, fptr);

        // Null-terminate the chunk for safe printing
        buffer[bytesRead] = '\0'; // Ensure no overflow occurs

        // Print the current chunk
        printf("%s", buffer);

        // Update the total size read
        totalSize += bytesRead;

        // Break the loop if we've reached the end of the file
        if (bytesRead < CHUNK_SIZE) {
            break;
        }
    }

    // Clean up
    fclose(fptr);
    free(buffer);

    printf("\nTotal size read: %zu bytes\n", totalSize);

    return 0;
}

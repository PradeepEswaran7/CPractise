#include <stdio.h>
#include <stdlib.h>
#define CHUNK_SIZE 100  

int main() {
    FILE *fptr;
    char *buffer;
    size_t bytesRead;
    size_t totalSize = 0;

    fptr = fopen("input.txt.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    buffer = (char )malloc(CHUNK_SIZE  sizeof(char)); 
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(fptr);
        return 1;
    }
	
    printf("File content:\n");

    while (1) {
        bytesRead = fread(buffer, sizeof(char), CHUNK_SIZE, fptr);

        buffer[bytesRead] = '\0'; 
		

        printf("%s", buffer);

        totalSize += bytesRead;

        if (bytesRead < CHUNK_SIZE) {
            break;
        }
    }

    fclose(fptr);
    free(buffer);

    printf("\nTotal size read: %zu bytes\n", totalSize);

    return 0;
}

#include <stdio.h>
#include <string.h>

#include "Header/Severe.h"
#include "Header/Syntax.h"
#include "Header/Winter.h"

#define MAX_NAME_LENGTH 256
#define MAX_NAMES 100

void fileOpen(void);

int main(int argc, const char* argv[]) {
    SVR(60, 1.00, true);
    return 0;
}

void fileOpen(void) {
    FILE* file = fopen("Massachusetts/00_Counties.txt", "r"); // Open the file in read mode.
    if (file == NULL) {
        perror("Unable to open the file");
    }
    else {
        char names[MAX_NAMES][MAX_NAME_LENGTH]; // Declare an array of strings to store names.
        int i = 0;
        while (fgets(names[i], MAX_NAME_LENGTH, file) != NULL && i < MAX_NAMES) {
            names[i][strcspn(names[i], "\n")] = '\0'; // Remove the newline character from each name.
            i++;
        }

        fclose(file); // Close the file.

        // Display the names stored in the array.
        for (int j = 0; j < i; j++) {
            printf("Name[%d] = %s\n", j + 1, names[j]);
        }
    }
}



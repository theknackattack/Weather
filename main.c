#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "Header/Date.h"
#include "Header/Severe.h"

#define MAX_NAME_LENGTH 256
#define MAX_NAMES 100

void fileOpen(void);

int main(int argc, const char* argv[]) {
    printCurrentDateAndTime();
    printInputDateAndTime(4, 4, false, 4, 12, 14, 2023);
    // SVR(60, 0, false);
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
            printf("Name[");
            if (j < 9) {
                printf("0");
            }
            printf("%d] = %s\n", j + 1, names[j]);
        }
    }
}



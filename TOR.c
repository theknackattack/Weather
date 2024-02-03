#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Header/Date.h"
#include "Header/TOR.h"

void TOR(void) {
    char* MESSAGE = (char*)malloc(sizeof(char) * 100);
    if (MESSAGE == NULL) {
        exit(1);
    }

    char string[] = "BULLETIN - EAS ACTIVATION REQUESTED\nTornado Warning\nNational Weather Service\n";
    strcpy(MESSAGE, string);
    printf("%s\n", MESSAGE);

    free(MESSAGE);
}
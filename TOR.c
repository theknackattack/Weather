#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Header/Date.h"
#include "Header/TOR.h"
#include "Header/Syntax.h"

void TOR(void) {
    char* MESSAGE = (char*)malloc(sizeof(char) * 100);
    if (MESSAGE == NULL) {
        errorMessage(2);
    }

    char string[] = "BULLETIN - EAS ACTIVATION REQUESTED\nTornado Warning\nNational Weather Service\n";
    strcpy(MESSAGE, string);
    printf("%s\n", MESSAGE);

    free(MESSAGE);
}
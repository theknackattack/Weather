#include <stdio.h>
#include <stdlib.h>

#include "Header/Syntax.h"

void errorMessage(int errorNumber) {
    if (errorNumber == 1) {
        printf("\n\tstd::invalid_argument exception thrown.\n");
        exit(errorNumber);
    }
    else if (errorNumber == 2) {
        printf("\n\tstd::memory_allocation exception thrown.\n");
        exit(errorNumber);
    }
}
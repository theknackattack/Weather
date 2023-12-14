#ifndef DATE_H
#define DATE_H

#include <stdbool.h>

void printCurrentDateAndTime(void);
void printInputDateAndTime(int hour, int minute, bool tzn, int dow, int month, int day, int year);

#endif
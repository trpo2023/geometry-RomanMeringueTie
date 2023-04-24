#pragma once

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct point {
    double x;
    double y;
};
typedef struct point point;

struct circle {
    point center;
    double radius;
    double perimeter;
    double area;
};
typedef struct circle circle;

void strToLower(char* str);

int isArguments(char* str);

int isLastBracket(char* str);

int isObject(char* str);

int printErrors(char* str, int countObj);

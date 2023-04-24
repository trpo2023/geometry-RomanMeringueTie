#include <stdlib.h>

#include <lib/input_checker.h>
#include <lib/lexer.h>
#include <lib/parser.h>

int getCenter(char* str, circle* circle)
{
    char* number = malloc(10);
    int bracket = 0;
    for (int i = 0;; i++) {
        if (str[i] == '(') {
            bracket = i;
            break;
        }
    }
    int index = 0;
    for (int i = bracket + 1; str[i] != ','; i++)
        number[index++] = str[i];
    if (sscanf(number, "%lf %lf", &(circle->center.x), &(circle->center.y))
        == 2)
        return 0;
    else
        return -1;
}

int getRadius(char* str, circle* circle)
{
    char* number = malloc(10);
    int comma = 0;
    for (int i = 0; str[i] != ','; i++)
        comma = i + 2;
    int index = 0;
    for (int i = comma; str[i] != ')'; i++)
        number[index++] = str[i];
    if (sscanf(number, "%lf", &(circle->radius)) == 1)
        return 0;
    else
        return -1;
    return 0;
}

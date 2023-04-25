#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/input_checker.h>
#include <lib/lexer.h>
#include <lib/parser.h>

#define ZERO 48
#define NINE 57

int main()
{
    FILE* file;
    file = fopen("input.txt", "r");
    if (!file) {
        printf("Не найден файл\n");
        return -1;
    }
    char str1[100];
    int countObj = 0;
    circle circle_obj;
    circle* figures = calloc(100, sizeof(circle));
    while (fgets(str1, 99, file)) {
        strToLower(str1);
        if (printErrors(str1, countObj) == 0) {
            countObj++;
            getCenter(str1, &circle_obj);
            getRadius(str1, &circle_obj);
            circle_obj.perimeter = perimeter(&circle_obj);
            circle_obj.area = area(&circle_obj);
            figures[countObj - 1] = circle_obj;
        } else {
            printf("%s\n", str1);
        }
    }
    for (int i = 0; i < countObj; i++) {
        intersects(figures, i, countObj);
    }
    fclose(file);
    free(figures);
    return 0;
}

#include <lib/input_checker.h>
#include <lib/lexer.h>
#include <lib/parser.h>
#include <stdio.h>
#include <string.h>

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
    circle circle;
    while (fgets(str1, 99, file)) {
        countObj++;
        strToLower(str1);
        if (printErrors(str1, countObj) != 0)
            printf("%s\n", str1);
        else {
            printf("%s\n", str1);
            getCenter(str1, &circle);
            getRadius(str1, &circle);
            printf("perimetr = %.3lf\n", perimeter(&circle));
            printf("area = %.3lf\n", area(&circle));
        }
    }
    fclose(file);
    return 0;
}

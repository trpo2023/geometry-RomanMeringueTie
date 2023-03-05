#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct point {
    double x;
    double y;
};
typedef struct point point;

struct triangle {
    point apex1;
    point apex2;
    point apex3;
    point checkApex;
};
typedef struct triangle triangle;

struct circle {
    point center;
    double radius;
};
typedef struct circle circle;

void strtolower(char* str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int isArguments(char* str)
{
    int ret = 0;
    int count = 0;
    for (int i = 7; str[i] != ',' && i < strlen(str); i++) {
        if (str[i] >= 48 && str[i] <= 57 && str[i + 1] == ' ')
            count++;
        if (str[i] == '.' && str[i + 1] == ')')
            count += 2;
    }
    if (count + 1 != 2) {
        printf("Неправильно введены координаты объекта\n");
        ret++;
        return ret;
    }
    int index = 0;
    for (int i = 0; i != strlen(str); i++) {
        if (str[i] == ',') {
            index = i + 1;
            i = strlen(str) - 1;
        }
    }
    for (; str[index] != ')' && index < strlen(str); index++) {
        if ((str[index] != '.' && str[index] != ' ')
            && !(str[index] >= 48 && str[index] <= 57)) {
            printf("Неправильно введён радиус объекта\n");
            return 1;
        }
        if (str[index] >= 48 && str[index] <= 57 && str[index + 1] == ' ')
            count++;
        if (str[index] == '.' && str[index + 1] == ' ')
            count += 2;
    }
    if (count != 1) {
        printf("Неправильно введён радиус объекта\n");
        ret++;
    }
    return ret;
}

int isEnd(char* str)
{
    int ret = 1;
    int firstBracket = 0;
    long int endingSymbol;
    if (str[strlen(str) - 1] == '\n')
        endingSymbol = strlen(str) - 2;
    else
        endingSymbol = strlen(str) - 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            firstBracket = i;
            break;
        }
    }
    if (firstBracket == endingSymbol)
        ret = 0;
    return ret;
}

int isObject(char* str)
{
    int ret = 1;
    char rec[100];
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];
        else
            break;
    }
    char figure[] = "circle";
    if (strcmp(rec, figure) == 0) {
        ret = 0;
    }
    return ret;
}

int printErrors(char* str, int countObj)
{
    printf("Объект %d:\n", countObj);
    if (isObject(str))
        printf("Неправильный ввод названия объекта\n");
    else if (isArguments(str))
        return 0;
    else if (isEnd(str))
        printf("Неправильный завершающий символ\n");
    else
        printf("%s\n", str);
    return 0;
}

int main()
{
    FILE* file;
    file = fopen("input.txt", "r");
    char str1[100];
    int countObj = 0;
    while (fgets(str1, 99, file)) {
        countObj++;
        strtolower(str1);
        printErrors(str1, countObj);
    }
    fclose(file);
    return 0;
}
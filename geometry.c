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
    int ret = 1;
    for (int i = 7; str[i] != ')'; i++) {
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ','
            || str[i] == ' ')
            ret = 0;
        else {
            ret = 1;
            break;
        }
    }
    return ret;
}

int isEnd(char* str)
{
    int ret = 1;
    int firstBracket = 0;
    long int endingSymbol = strlen(str) - 1;
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

void printErrors(char* str)
{
    if (isObject(str))
        printf("Ошибка после элемента 0: Неправильный ввод названия объекта\n");
    else if (isArguments(str))
        printf("Ошибка после элемента 7: Неправильно введены данные объекта\n");
    else if (isEnd(str))
        printf("Ошибка после элемента %ld: Неправильный завершающий символ\n",
               strlen(str) - 1);
    else
        printf("%s\n", str);
}

int main()
{
    FILE* file;
    file = fopen("input.txt", "r");
    char str1[100], str2[100];
    fgets(str1, 99, file);
    strtolower(str1);
    objectToString(str1, str2);
    printErrors(str2);
    fclose(file);
    return 0;
}

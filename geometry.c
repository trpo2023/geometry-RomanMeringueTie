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

        if (str[i] == '.' && str[i + 1] == ' ')
            count += 2;
    }
    if (count + 1 != 2) {
        printf("Неправильно введены координаты объекта\n");
        ret++;
        return ret;
    }
    int index = 0;
    count = 0;
    for (int i = 0; i != strlen(str); i++) {
        if (str[i] == ',')
            index = i + 1;
    }
    for (; index < strlen(str); index++) {
        if ((str[index] > 48 && str[index] <= 57 && str[index + 1] == ' ')
            || str[index] == 48 || (str[index] == '.' && str[index + 1] == ' '))
            count++;
        if (!((str[index] > 48 && str[index] <= 57) || str[index] == '.'
              || str[index] == ' '))
            count++;
    }
    if (count != 0) {
        printf("Неправильно введён радиус объекта\n");
        ret++;
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

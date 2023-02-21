#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    long int endingSymbol = strlen(str) - 2;
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

int main()
{
    FILE* file;
    file = fopen("input.txt", "r");
    char str[100];
    fgets(str, 99, file);
	for (int i = 0; i < strlen(str); i++)
		str[i] = tolower(str[i]);
    if (isObject(str))
        printf("Ошибка на элементе 0: Неправильный ввод названия объекта\n");
    else if (isArguments(str))
        printf("Ошибка на элементе 7: Неправильно введены данные объекта\n");
    else if (isEnd(str))
        printf("Ошибка на элементе %ld: Неправильный завершающий символ\n",
               strlen(str) - 1);
    else
        printf("%s", str);
    fclose(file);
    return 0;
}

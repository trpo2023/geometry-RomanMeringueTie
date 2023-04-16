#include <lib/parser.h>
#include <lib/lexer.h>
#include <math.h>
#define PI 3.14

double perimeter(circle *circle)
{
    double perimetr = 2 * PI * circle->radius;
    return perimetr;
}

double area(circle *circle)
{
    double area = PI * pow(circle->radius, 2);
    return area;
}

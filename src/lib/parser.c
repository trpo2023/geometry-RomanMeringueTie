#include <math.h>

#include <lib/lexer.h>
#include <lib/parser.h>
#define _USE_MATH_DEFINES

double perimeter(circle* circle)
{
    double perimetr = 2 * M_PI * circle->radius;
    return perimetr;
}

double area(circle* circle)
{
    double area = M_PI * pow(circle->radius, 2);
    return area;
}

#include <ctest.h>
#include <math.h>
#include <stdlib.h>

#include <lib/input_checker.h>
#include <lib/parser.h>

#define _USE_MATH_DEFINES

CTEST(perimeter_check, simple_perimeter)
{
    circle* circle = calloc(1, sizeof(circle));
    circle->center.x = 1;
    circle->center.y = 1;
    circle->radius = 1;
    double return1 = perimeter(circle);
    ASSERT_DBL_NEAR_TOL(6.2831853, return1, -7.18e-09);
    free(circle);
}

CTEST(area_check, simple_area)
{
    circle* circle = calloc(1, sizeof(circle));
    circle->center.x = 1;
    circle->center.y = 1;
    circle->radius = 1;
    double return1 = area(circle);
    ASSERT_DBL_NEAR_TOL(M_PI, return1, 0);
    free(circle);
}

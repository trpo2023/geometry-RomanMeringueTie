#include <ctest.h>
#include <lib/input_checker.h>
#include <lib/lexer.h>
#include <lib/parser.h>

CTEST(getCenter_check, simple_center)
{
    char* str = "circle(1 1, 1)";
    circle* circle = calloc(1, sizeof(circle));
    getCenter(str, circle);
    ASSERT_DBL_NEAR_TOL(1, circle->center.x, 0);
    ASSERT_DBL_NEAR_TOL(1, circle->center.y, 0);
    free(circle);
}

CTEST(getRadius_check, simple_radius)
{
    char* str = "circle(1 1, 1)";
    circle* circle = calloc(1, sizeof(circle));
    getRadius(str, circle);
    ASSERT_DBL_NEAR_TOL(1, circle->radius, 0);
    free(circle);
}
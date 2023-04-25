#include <ctest.h>

#include <lib/input_checker.h>

CTEST(isArguments_check, simple_arguments)
{
    char* success = "circle(1 1, 1)";
    char* error1 = "circle(1, 1)";
    char* error2 = "circle(1 1, )";
    int return1 = isArguments(success);
    int return2 = isArguments(error1);
    int return3 = isArguments(error2);
    ASSERT_EQUAL(0, return1);
    ASSERT_EQUAL(-1, return2);
    ASSERT_EQUAL(-1, return3);
}

CTEST(isLastBracket_check, simple_bracket)
{
    char* error = "circle(1 1, 1";
    int return1 = isLastBracket(error);
    ASSERT_EQUAL(1, return1);
}

CTEST(isObject_check, simple_object)
{
    char* success = "circle(1 1, 1)";
    char* error = "cicle(1 1, 1)";
    int return1 = isObject(success);
    int return2 = isObject(error);
    ASSERT_EQUAL(0, return1);
    ASSERT_EQUAL(1, return2);
}

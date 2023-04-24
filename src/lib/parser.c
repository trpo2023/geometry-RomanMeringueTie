#include <math.h>

#include <lib/input_checker.h>
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

int intersects(circle* figures, int index, int length)
{
    printf("Объект %d: circle(%.1lf %.1lf, %.1lf)\nperimeter = %lf\narea = "
           "%lf\nintersects:\n",
           index + 1,
           figures[index].center.x,
           figures[index].center.y,
           figures[index].radius,
           figures[index].perimeter,
           figures[index].area);
    if (length <= 1)
        printf("Недостаточно объектов, чтобы посчиатать пересечения\n");
    double x1 = figures[index].center.x;
    double y1 = figures[index].center.y;
    double r1 = figures[index].radius;
    for (int i = 0; i < length; i++) {
        if (i == index)
            continue;
        else {
            double x2 = figures[i].center.x;
            double y2 = figures[i].center.y;
            double r2 = figures[i].radius;
            double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            if (d > r1 + r2)
                printf("Не пересекается с объектом %d\n", i + 1);
            else
                printf("Пересекается с объектом %d\n", i + 1);
        }
    }
    return 0;
}

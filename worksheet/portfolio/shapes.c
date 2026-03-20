#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint( float x, float y )
{
    Point new;
    new.x = x;
    new.y = y;

    return new;
}

Line makeLine( Point p1, Point p2 )
{
    Line new;
    new.p[0] = p1;
    new.p[1] = p2;

    return new;
}

Triangle makeTriangle( Point p1, Point p2, Point p3 )
{
    Triangle new;
    new.p[0] = p1;
    new.p[1] = p2;
    new.p[2] = p3;

    return new;
}

float lineLength( Line l )
{
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;

    return sqrtf(pow(dx, 2) + pow(dy, 2));
}

float triangleArea( Triangle t )
{
    float a = lineLength(makeLine(t.p[0], t.p[1]));
    float b = lineLength(makeLine(t.p[1], t.p[2]));
    float c = lineLength(makeLine(t.p[2], t.p[0]));

    float s = (a + b + c) / 2.0f;

    return sqrtf(s * (s - a) * (s - b) * (s - c));
}

bool samePoint( Point p1, Point p2 )
{
    return (fabsf(p1.x - p2.x) < 1.0e-6) && (fabsf(p1.y - p2.y) < 1.0e-6);
}

bool pointInLine( Point p, Line l )
{
    return samePoint(p, l.p[0]) || samePoint(p, l.p[1]);
}

bool pointInTriangle( Point p, Triangle t )
{
    return samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2]);
}
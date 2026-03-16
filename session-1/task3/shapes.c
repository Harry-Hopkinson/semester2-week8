#include <stdio.h>

#include "shapes.h"

int main( void )
{

    // complete the structure definition in the header file first
    // code in main to test the structures and functions

    Rectangle r = makeRectangle( (Point){.x = 1, .y = 2}, 3, 4 );
    printf( "Area of rectangle -> %f\n", area(r) );

    shiftRectangle( &r, (Point){.x = 1, .y = 1} );
    printf( "Area of rectangle after shift -> %f\n", area(r) );
    
    scaleRectangle( &r, 2 );
    printf( "Area of rectangle after scale (2) -> %f\n", area(r) );
    
    return 0;
}

Rectangle makeRectangle(Point p, float width, float height)
{
    Rectangle r = {
        .p = p,
        .width = width,
        .height = height
    };

    return r;
}

float area(Rectangle r)
{
    return r.width * r.height;
}

void shiftRectangle(Rectangle *r, Point dp)
{
    r->p.x += dp.x;
    r->p.y += dp.y;

    return;
}

void scaleRectangle(Rectangle *r, float scale)
{
    r->p.x *= scale;
    r->p.y *= scale;

    r->width *= scale;
    r->height *= scale;

    return;
}

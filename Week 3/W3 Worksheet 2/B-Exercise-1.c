#include <stdio.h>
#include <math.h>

float circleArea(float radius)
{
    float area;
    area = M_PI * pow(radius, 2);
    return area;
}

int main()
{
    float radius = 5.5;
    float a = circleArea(radius);

    printf("The area of a circle with radius %g is %.2f\n", radius, a);
}
#include <stdio.h>
#include <math.h>

float sphereVolume(float radius)
{
    float volume;
    volume = M_PI * (4/3) * pow(radius, 3);
    return volume;
}

int main()
{
    float radius = 5.5;
    float a = sphereVolume(radius);

    printf("The volume of a sphere with radius %g is %.2f\n", radius, a);
}
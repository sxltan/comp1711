#include <stdio.h>

float sum (float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

float main () 
{
    float x = 5.25;
    float y = 2.5678;
    float z = sum(x, y); // calling our new function

    printf ("The sum of %g and %g is %.2f\n", x, y, z);
}
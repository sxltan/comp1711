#include <stdio.h>
int main() {
    float a;
    float b;
    float c;

    printf("Input the first side of a rectangle (a):");
    scanf("%f", &a);

    printf("Input the second side of a rectangle (b):");
    scanf("%f", &b);

    c = a * b;

    printf("The area of the rectangle is %.2f (units^2)\n", c);

    return 0;
}
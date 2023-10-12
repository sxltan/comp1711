#include <stdio.h>

int main() {
    int a;
    for (a = 1; a < 11; a++)
    {
        int square = a * a;
        printf ("The square of the number a is %d\n", square);
    }
    return(0);
}
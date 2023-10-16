#include <stdio.h>

int main() {

    int number;

    printf ("Enter a number: \n");
    scanf ("%d", &number);

    if (number % 4 == 0)
    {
        if (number % 5 == 0)
        {
            printf ("The number %d is divisible by both 4 and 5\n", number);
        }
    }
    else
    {
        printf ("The number %d is not divisible by both 4 and 5\n", number);
    }
    return 0;
}
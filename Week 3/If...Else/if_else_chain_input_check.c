#include <stdio.h>

int main() {

    int mark;

    printf ("Enter the mark: ");
    scanf ("%d", &mark);
    printf ("The mark to be checked is: %d \n", mark);
    
    if (mark >= 0 && mark <= 100)
    {

        if (mark == 0)
        {
            printf ("The mark of %d is zero\n", mark);
        }
        else if (mark < 40)
        {
            printf ("The mark of %d is a fail\n", mark);
        }
        else
        {
        printf ("The mark of %d is a pass\n", mark);
        }
    }
    else
    {
        printf ("Marks must be between 0 and 100\n");
    }

    return 0;
}
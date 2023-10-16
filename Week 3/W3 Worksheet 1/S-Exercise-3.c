#include <stdio.h>

int main() {

    int grade;

    printf ("Enter the grade \n");
    scanf ("%d", &grade);

    if (grade > 70)
    {
        printf ("The student has gained distinction with the grade %d\n", grade);
    }
    else if (grade >50)
    {
        printf ("The student has passed with the grade %d\n", grade);
    }
    else
    {
        printf ("The student has failed with the grade %d\n", grade);
    }
    return 0;
}
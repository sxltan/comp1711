#include <stdio.h>

int main() {

    int number;

    printf ("Enter a number: \n");
    scanf ("%d", &number);
    
    if (number == -1) {
    printf ("The program will be terminated since you entered the value -1\n");
   }

    else if (number >=0 && number <=100) {

        while (number != -1)
        {
            if (number >=0 && number <=100) {

            printf ("The number %d is between 0-100, however, it is not the termination value -1\n", number);
            printf ("Enter a new number: \n");
            scanf ("%d", &number);
            }

            else {
                printf ("The number you entered is not between 0-100\n");
                break;
            }
        }
        printf ("The program will be terminated since you entered the value -1\n");
    }
        
    else {
        printf ("The number you entered is not between 0-100\n");
    }
    return 0;
}
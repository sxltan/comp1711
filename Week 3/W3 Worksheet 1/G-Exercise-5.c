#include <stdio.h>

int main() {

    int choice;

    printf ("Pick a choice between 1-5: \n");
    scanf ("%d", &choice);

    switch (choice) {

    case 1: printf("You have selected option 1\n");
    break;

    case 2: printf("You have selected option 2\n");
    break;

    case 3: printf("You have selected option 3\n");
    break;

    case 4: printf("You have selected option 4\n");
    break;

    case 5: printf("You have selected option 5\n");
    break;

    default: printf("You haven't selected any of the available options\n");
    }
    return 0;
}

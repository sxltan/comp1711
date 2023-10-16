#include <stdio.h>

int main() {

    int a;
    a = 2;

    switch (a) {

        case 0: printf ("Option 0 has been selected\n");
        break;

        case 1: printf ("Option 1 has been selected\n");
        break;

        default: printf ("A different option has been selected\n");
    }
    return 0;
}
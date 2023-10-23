#include <stdio.h>
#include <math.h>
#include "utils.h"

int main() {
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "w");

    int n;
    int number;
    printf("Enter the value for n: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        number = pow(i, 2);
        fprintf(file, "%d\n", number);
    }

    fclose(file);
    return 0;
}

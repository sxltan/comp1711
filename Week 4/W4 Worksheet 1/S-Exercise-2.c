#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "r");

    int number;
    int count;
    count = 0;
    float average;

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        number = number + atoi(line_buffer);
        count++;
    }

    average = number / count;

    printf("The average of the %i numbers, is %.2f\n", count, average);

    fclose(file);
    return 0;
}
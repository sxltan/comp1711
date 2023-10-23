#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    char filename [] = "numbers.dat";
    FILE *file = fopen(filename, "r");

    float average;
    float total = 0.0;
    int count = 0;

    int buffer_size = 100;
    char line_buffer[buffer_size];

     // Read existing numbers, calculate total and count
    //fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total += atof(line_buffer);
        count++;
    }

    if (count > 0) {
        average = total / count;
    }
    else {
        average = 0.0;
    }

    fclose(file);

    file = fopen(filename, "a");
    
    fprintf(file, "%g\n", average);

    fclose(file);
    return 0;
    }
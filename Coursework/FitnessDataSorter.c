#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

FitnessData data[10000]; // Array to store fitness data

int main() {
    char filename[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int counter = 0;

    printf("Input filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: invalid file\n");
        return 1;
    }

    while (fgets(line, BUFFER_SIZE, file)) {
        // Used strtok to tokenize the line string, then NULL to get the next token 
        // ... https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
        char *date = strtok(line, ",");
        char *time = strtok(NULL, ",");
        char *stepsStr = strtok(NULL, ",");
        // If the data comes back as NULL, there is an error in the file (missing field), and the code will stop
        if (date == NULL || time == NULL || stepsStr == NULL) {
            printf("Error: invalid file\n");
            fclose(file);
            return 1;
        }
        int steps = atoi(stepsStr);
        strcpy(data[counter].date, date);
        strcpy(data[counter].time, time);
        data[counter].steps = steps;
        counter++;
    }
    fclose(file);

    // Sorting function
    for (int i = 0; i < counter; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (data[i].steps < data[j].steps) {
                FitnessData temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    // Writing sorted data in a new file https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm
    strcat(filename, ".tsv");
    FILE *outputFile = fopen(filename, "w");
    if (!outputFile) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }
    for (int i = 0; i < counter; i++) {
        // Spacing everything out with \t for a tab instead of a comma (for .tsv files)
        fprintf(outputFile, "%s\t%s\t%d\t\n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(outputFile);

    printf("File successfully sorted and saved.\n");
    return 0;
}

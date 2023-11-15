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

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int main() {
    char filename[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int counter = 0;

    printf("Input filename: ");
    scanf("%1023s", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: invalid file\n");
        return 1;
    }

    while (fgets(line, BUFFER_SIZE, file)) {
        tokeniseRecord(line, ',', data[counter].date, data[counter].time, &data[counter].steps);
        
        // Check for incomplete tokenisation
        if (strlen(data[counter].date) == 0 || strlen(data[counter].time) == 0 || data[counter].steps == 0) {
            printf("Error: invalid file format\n");
            fclose(file);
            return 1;
        }
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

    // Writing sorted data in a new file
    strcat(filename, ".tsv");
    FILE *outputFile = fopen(filename, "w");
    if (!outputFile) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }
    for (int i = 0; i < counter; i++) {
        fprintf(outputFile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(outputFile);

    printf("File successfully sorted and saved.\n");
    return 0;
}

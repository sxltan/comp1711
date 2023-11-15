#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Define a struct to hold fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Make an array to store multiple records of the struct
FitnessData data[10000];

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

    // Prompt the user to enter the filename
    printf("Input filename: ");
    scanf("%1023s", filename);
    
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: invalid file\n");
        return 1;
    }

    // Read each line from the file
    while (fgets(line, BUFFER_SIZE, file)) {
        // Use the tokeniseRecord function to split the line up into fields and store them in the array
        tokeniseRecord(line, ',', data[counter].date, data[counter].time, &data[counter].steps);
        
        // Check for incomplete or invalid tokenisation
        if (strlen(data[counter].date) == 0 || strlen(data[counter].time) == 0 || data[counter].steps == 0) {
            printf("Error: invalid file format\n");
            fclose(file);
            return 1;
        }
        counter++; // Increase the counter for each successfully line split
    }
    fclose(file); // Close the file after reading all lines

    // Sort the array in descending order of steps
    for (int i = 0; i < counter; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (data[i].steps < data[j].steps) {
                FitnessData temp = data[i];
                data[i] = data[j];
                data[j] = temp; // Swap the records to sort
            }
        }
    }

    // Append '.tsv' to the filename and open a new file for writing 
    // ... https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm
    strcat(filename, ".tsv");
    FILE *outputFile = fopen(filename, "w");
    if (!outputFile) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }

    // Write the sorted data into the new file in TSV format
    for (int i = 0; i < counter; i++) {
        // Use '\t' to space each field with a tab instead of a comma
        fprintf(outputFile, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    fclose(outputFile); // Close the output file

    printf("File successfully sorted and saved.\n");
    return 0;
}

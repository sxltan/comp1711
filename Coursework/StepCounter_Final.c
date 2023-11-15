#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

#define BUFFER_SIZE 1024

FITNESS_DATA data[10000]; // Array to store fitness data

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

// Complete the main function
int main() {
    char filename[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int counter = 0;

    // Menu loop
    while (1) {
        char choice;
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");

        scanf(" %c", &choice);
        while (getchar() != '\n');  // Clear buffer

        switch (choice) {
            case 'A':
            case 'a':
                printf("Input filename: ");
                scanf("%s", filename);
                FILE *file = fopen(filename, "r");
                if (!file) {
                    printf("Error: Could not find or open the file.\n");
                    return 1; // Exit the program with return code 1
                }
                counter = 0;
                while (fgets(line, BUFFER_SIZE, file)) {
                    char stepsString[20]; // Make temporary array to store steps as a string before converting to integer
                    tokeniseRecord(line, ",", data[counter].date, data[counter].time, stepsString);
                    data[counter].steps = atoi(stepsString);
                    counter++;
                }
                fclose(file);
                printf("File successfully loaded.\n");
                break;

            case 'B':
            case 'b':
                // From now on I'll put a quick check at the start of every case to make sure the counter isn't 0
                // ... (e.g. something went wrong with the file specification)
                if (counter == 0) {
                    printf("No data available\n");
                    break;
                }
                printf("Total records: %d\n", counter);
                break;

            case 'C':
            case 'c':
                if (counter == 0) {
                    printf("No data available\n");
                    break;
                }
                // Setting the minimum value at the start of the loop to the first element at index 0
                int minIndex = 0;
                // A loop goes through checking if anything is smaller than the value at index 0, if so, minIndex becomes
                // ... that value and the loop continues till all the elements have been gone through
                for (int i = 1; i < counter; i++) {
                    if (data[i].steps < data[minIndex].steps) {
                        minIndex = i;
                    }
                }
                printf("Fewest steps: %s %s\n", data[minIndex].date, data[minIndex].time);
                break;

            case 'D':
            case 'd':
                if (counter == 0) {
                    printf("No data available\n");
                    break;
                }
                int maxIndex = 0;
                for (int i = 1; i < counter; i++) {
                    if (data[i].steps > data[maxIndex].steps) {
                        maxIndex = i;
                    }
                }
                printf("Largest steps: %s %s\n", data[maxIndex].date, data[maxIndex].time);
                break;

            case 'E':
            case 'e':
                if (counter == 0) {
                    printf("No data available\n");
                    break;
                }
                int totalSteps = 0;
                for (int i = 0; i < counter; i++) {
                    totalSteps += data[i].steps;
                }
                float mean = (float)totalSteps / counter;
                int roundedMean = (int)round(mean);
                printf("Mean step count: %d\n", roundedMean);
                break;

            case 'F':
            case 'f':
                if (counter == 0) {
                    printf("No data available\n");
                    break;
                }

                int longestStreak = 0, currentStreak = 0;
                int longestStartIndex = 0, currentStartIndex = 0;
                for (int i = 0; i < counter; i++) {
                    if (data[i].steps > 500) {
                        if (currentStreak == 0) {
                            currentStartIndex = i; // Start of a new streak
                        }
                        currentStreak++;
                        if (currentStreak > longestStreak) {
                            longestStreak = currentStreak;
                            longestStartIndex = currentStartIndex;
                        }
                    } else {
                        currentStreak = 0;
                    }
                }

                if (longestStreak > 0) {
                    printf("Longest period start: %s %s\n", data[longestStartIndex].date, data[longestStartIndex].time);
                    // End of the longest period is the start plus the streak length minus 1
                    int longestEndIndex = longestStartIndex + longestStreak - 1;
                    printf("Longest period end: %s %s\n", data[longestEndIndex].date, data[longestEndIndex].time);
                // If no steps over 500 are found in the data, make it print out an error message informing the user
                } else {
                    printf("No period found with steps over 500.\n");
                }
                break;

            case 'Q':
            case 'q':
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}
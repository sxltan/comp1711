#include <stdio.h>
int main() {
    // Define a character string variable called "name" that can contain up to 15 characters
    char name[15];

    printf("Hello, please enter your name:");
    // Lets's us read in data from the keyboard; %s -in string format- and stores in the variable "name"
    scanf("%s", name);
    // Prints the phrase in quotes and substitutes in my name for the %s format specifier
    printf("Your name is %s\n", name);
    
    return 0;
}
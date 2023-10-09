; = Generally used at the end of extension lines
// = A comment
/n = New-line operator
& = The "address of" operator

%c = Single character
%d = Decimal integer (assumes base 10)
%s = String
%f = Float point
%g = Simplifier for float point (Removes excess 0)

int = Integer
char = Character
float = 
double = 

gcc = GNU C Compiler
gcc example.c -o example --> example.c = Source | -o example = output executable is example


#include <stdio.h> = Include the Standard IO Library
int main() { = Defines the main function (entrypoint)
    int a = 10; = Defines an integer variable "a" and initialises it to 10
    printf("%d", a); = Format-prints the value of "a" as an integer (%d is a format specifier)
    return 0; = Returns from function with error code zero ("success")
} = Ends the main function


char example[#] = Defines a character string variable "example" that can contain up to # characters
scanf ("%s", example) = Allows data to be read from keyboard (%s = in string format) and stored in the variable "example"
printf ("Hello %s\n", example) = Prints the phrase in quotes and subsitutes in the string in "example" for the %s format specifier | \n = Blank line after the print function

&example = The address of the variable "example" (scanf needs to know the memory address of the variable)
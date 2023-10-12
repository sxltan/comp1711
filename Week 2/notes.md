# Week 2 Notes

## Basic Commands

; = Generally used at the end of extension lines  
// = A comment  
/n = New-line operator  
& = The "address of" operator  



## Format Types

- %c = Single character  
- %d = Integer  
- %s = String  
- %f = Float point  
- %g = Simplifier for float point (Removes excess 0)  

int = Integer   
char = Character    
float =     
double =    

---

include <stdio.h> = Include the Standard IO Library 

gcc = GNU C Compiler    
gcc example.c -o example --> example.c = Source | -o example = output executable is example 

chmod u+x (filename) = Give user permissions to run the file (.sh, etc) 

---

int main() { = Defines the main function (entrypoint)   
    int a = 10; = Defines an integer variable "a" and initialises it to 10  
    printf("%d", a); = Format-prints the value of "a" as an integer (%d is a format specifier)  
    return 0; = Returns from function with error code zero ("success")  
} = Ends the main function  

---

char example[#] = Defines a character string variable "example" that can contain up to # characters 
scanf ("%s", example) = Allows data to be read from keyboard (%s = in string format) and stored in the variable "example"  
printf ("Hello %s\n", example) = Prints the phrase in quotes and subsitutes in the string in "example" for the %s format   
specifier | \n = Blank line after the print function  

&example = The address of the variable "example" (scanf needs to know the memory address of the variable)   


## For Loop

    for (a = 0; a < 5; a++)     
    {   
        printf ("a is equal to %d\n", a);   
    }   

    printf ("I've finished the loop and a is equal to %d\n", a);    

- Loop control variable = a   
- Terminating condition test = a < 5  
- Incrementor = a++ (adds 1 to the value each time the loop repeats)  



### Incrementing Examples:

- a++ = Add 1 each time      
- a-- = Subtract 1 each time  
- a+=1 = Add 1 each time  
- a+=2 = Add 2 each time  
- a*=3 = Multiply by 3 each time  



## Arrays

#### Populate an array:
   
    for (count = 0; count < 10; count++)
        {   
            a[count] = count * 10 + count;  
        }   

    printf ("The first and second elements are %d and %d\n", a[0], a[1]); = Normal  
    printf ("Or, via pointers, %d and %d\n", *a, *(a+1)); = Pointer 

### Pointers:

- A pointer is the ADDRESS of a block of memory with a variable in it.    
- If you declare a variable AND a pointer to that variable you can access it viathe variable name OR the pointer. 
- They are useful for arrays, functions and string handling.  

### Strings in Arrays:

- In C, a string is an array of single characters.
- BUT the last element is "hidden" and contains a special terminator - a \0.
- So an array of 10 characters can actually hold 9 characters or less.
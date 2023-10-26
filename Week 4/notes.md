# Week 4 Notes

## File Handling

### Creating:

```c++
char filename [] = "data.txt";
FILE *file = fopen(filename, "w"); // or "r" or "a" or ...
if (file == NULL) 
{
    perror ("");
    return 1;
}
```

- Opening a file (`fopen`) produces a `FILE` pointer
- An error produces a `NULL` pointer
- We can print the last error with `perror`
  
In `fopen`, we must specify what we want to do with the file with:
  -  "`r`" = Read (Opens file)
  -  "`w`" = Write (Creates file)
  -  "`a`" = Append (Appends file, creates new file if necessary)

Or we can use (advanced):
  - "`r+`" = Read and write, from beginning
  - "`w+`" = Read and write, overwriting
  - "`a+`" = Read and write, appending

### Closing:

```c++
fclose(file);
return 0;
```

- Don't forget to close file (`fclose`) BEFORE returning

## Writing into a file

Note: This is in between creating and closing a file (from the previous note).

```c++
int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
```

- We can write to the file with `fprintf` (file equivalent of `printf`)

## Reading from a file

Note: This is in between creating and closing a file (from the previous note).

```c++
int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
```

- `fgets` reads the file line by line into a buffer
- If buffer is too small, only the beginning of the line will be read
- Buffer should be larger than longest line + 1 extra character

## Code Reuse - Functions

All three programs use this piece of code:

```c++
#include <stdlib.h> // Defines exit()
FILE *open_file(char filename[], char mode[])
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) 
    {
        perror("");
        exit(1); // Exits program with return status 1
    }
    return file;
}
```

- `return(1)` in `main()` becomes `exit(1)`
- We use the argument `mode` to generalise the function to all cases

BUT: We still need to copy the function in each file

## Code Reuse - Headers

- A header file is a collection of forward function declarations
- `stdio.h` and `stdlib.h` are header files

### The Header File (utils.h)

```c++
#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[], char mode[]);

#endif /* UTILS_H */
```

- `#ifndef` & `#endif` = "Guards" to prevent double inclusions
- Files that use this header must include it with `#include "utils.h"`
- Other headers should be included here too!

### The Implementation File (utils.c)

```c++
#include "utils.h"

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}
```

- Only the corresponding header is included (note the **double quotes**)
  - < > = System Directories
  - " " = Local Directories
- All functions declared in the header must be implemented

### The Main File (create_file_h.c)

```c++
#include <stdio.h>
#include "utils.h"

int main () {
    char filename [] = "data.txt";
    FILE *file = open_file(filename, "w");

    fclose(file);
    return 0;
}
```

- Include the header file (again with **double quotes**)
- You can now use the functions defined there

### Compiling

To compile we now need three commands:

```c++
gcc -c utils.c              // Will produce utils.o
gcc -c create_file_h.c      // Will produce  create_file_h.o
gcc create_file.o utils.o -o create_file
```

1. Compile the implementation file with flag `-c`
2. Compile the main file with flag `-c`
3. Generate the executable by combining the object files (extension .o)

MAKE: A Linux tool that allows this compiling process to be simplified (Semester 2)

## Data Types & Structures

### Initialising Structures

#### Setup Template:

```c++
struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};
```

- `struct` is defined out of a function
- `struct student` has 3 fields, each with its own type
- Fields can be variables, arrays, structs, etc.

<br>

#### Initialise New Record + Input Data + Output Data:

```c++
int main () {
    struct student new_student = {"Name Surname", "28932123", 35};
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}
```

- The designator `.<fieldname>` is used to initialise individual fields:
  ```c++
  struct student new_student = {.name = "Name Surname", .student_id = "28932123", .mark = 35];}
  ```

#### Assigning Fields

```c++
#include <string.h>

int main() {
    struct student new_student;
    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "13902178");
    printf("Student name: %s\n", new_student.name);
    printf("Student ID: %s\n", new_student.student_id);
    printf("Final mark: %u\n", new_student.mark);
    return 0;
}
```

- `strcpy` = String Copy (Assigns data to fields) # Must include <string.h>

### Arrays of Structures

```c++
#include <stdio.h>

typedef struct {
    char name [20];
    char student_id [11];
    unsigned mark;
} student;

int main () {
    int number_of_students = 10, i;
    student students [] = {
        {...}, // Initialisation goes here
    };
    for (i = 0; i < number_of_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}
```

- All elements in the array can be initialised simultaneously
- `typedef` is used to define an alias for a struct
- The size of the array is not needed if entries are initialised
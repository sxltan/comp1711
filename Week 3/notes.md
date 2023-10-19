# Week 3 Notes

## Objectives

1. If... Else
2. Switch

## Conditions and Comparisons

```c
IF (CONDITIONAL_TEST)
{
    CODE IF TRUE
}
ELSE
{
    CODE IF FALSE
}
```

### Advanced Version (Chain):

```c
IF (CONDITIONAL_TEST)
{
    CODE IF TRUE
}
ELSE IF (CONDITIONAL_TEST)
{
    CODE IF TRUE
}
ELSE
{
    CODE IF FALSE
}
```

## Switch

A switch can be a neater way of testing against multiple values (rather than conditions).   
It's also great for providing simple meny systems.  

```c
switch (VARIABLE) {

        case 0: printf ("Option 0 has been selected\n");
        break;

        case 1: printf ("Option 1 has been selected\n");
        break;

        default: printf ("A different option has been selected\n");
    }
```

- Opening line is switch (with variable in brackets)
- This is tested against the various cases (EACH CASE IN ORDER)
- Final line is default (executed if none of the cases match)
- "Break" is there so that not ALL the other options get executed

## Functions

Functions allow us to:
- Split code into re-usable bit sized chunks.
- Perform particular tasks.
- Structure programs in a more readable way.

### Basic Use Example

```c
int sum (int a, int b)
{
    int answer;
    answer = a + b;
    return answer;
}
```

- `int` = Return type
- `int a, int b` = Input parameters

```c
int main ()
{
    int y = 2;
    int z = sum(5, y);

    printf ("The sum of 5 and %d is %d\n", y, z);
}
```

- `int z = sum(5, y)` = Function call (and pass two values into sum)

### Order Matters

- Compiler reads from top to bottom.
- Function needs to be defined BEFORE it is used in the program.
- C allows us to declare functions before they are used (forward declarations).
- A function delcaration is the definition of the function without the **payload** (e.g. `int sum (int a, int b);`)


### Regular Functions

Void Functions:
- Return multiple variables
- Return no variable at all


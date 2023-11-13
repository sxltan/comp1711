# Week 7 Notes

## New Functions

### getchar()

```c++
choice = getchar();
```

getchar() returns the next char from the stdin.

### sscanf()

```c++
sscanf(line, " %s ", filename);
```

sscanf is like scanf, but it reads from a string rather than the stfdin. 
It isoften paired with an fgets() line to get user inputs.

### #define 

```c++
#define buffer_size 100
```

This is a way of making a constant- wherever the name buffer_size is typed, Cwill replace this with 100.

### @brief

```c++
/**
* @brief ....
*/
```

This is a doxygen comment- you will see them throughout the code, and theyare a way of formatting top-level comments which means that VSCode cangive you more helpful tooltips when using your own functions. You do notneed to write these yourself!!
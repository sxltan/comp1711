# Week 8 Notes

## 2D Arrays

- A Matrix of values consisting of information arranged in rows and columns
  
- 2-d array: called arr
  arr[0][0] arr[0][1] arr[0][2] arr[0][3] arr[0][4]
  arr[1][0] arr[1][1] arr[1][2] arr[1][3] arr[1][4]
  arr[2][0] arr[2][1] arr[2][2] arr[2][3] arr[2][4]
  
- To assign a value to a particular element in the 2-d array arr:
  arr[1][2]=10;

### Initialising 2D Arrays

```c++
#include <stdio.h>

void printArray(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

int main() {
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  printf("Values in array1 by row are:\n");
  printArray(array1);

  int array2[2][3] = {1, 2, 3, 4, 5};
  printf("Values in array2 by row are:\n");
  printArray(array2);


  int array3[2][3] = {{1, 2}, {4}};
  printf("Values in array3 by row are:\n");
  printArray(array3);
  
  return 0;
}
```

- We define the dimension by using int array1[m][n], in our example m=2 and n=3.
  
- We can initialize the array either by:
  - Using two separate {}, each initializing the values in a row
  - Uing a single {}, in which case the values will automatically be inserted in the array in the sameorder they have been set.
  - Using two separate {} but fewer number of elements than the dimension, will set the unassigned elements to zero.

- Except the first index, all the subsequent indices of a multi-dimensional arrayare required. The compiler uses these indices to determine the locations inmemory.

### Assigning Columns in 2D Arrays

```c++
#include <stdio.h>

void printColumn(int a[][4], int colIndex, int rows, char when) {
    switch (when) {
        case 'B':
            printf("Values in column %d before change:\n", colIndex); break;

        case 'A':
            printf("Values in column %d after change:\n", colIndex); break;

        default: 
            printf("Invalid option\n");
            return;
    }

    for (int i = 0; i < rows; ++i) {
        printf("%d\n", a[i][colIndex]);
    }
}

void changeColumn(int a[][4], int colIndex, int rows, int newValue) {
    for (int i = 0; i < rows; ++i) {
        a[i][colIndex] = newValue;
    }
}

int main() {
    int array1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int colIndexToChange = 2; // Change the values in the third column (column at index 2)
    int newValue = 20;

    printColumn(array1, colIndexToChange, 3, 'B'); // 'B' stands for Before
    changeColumn(array1, colIndexToChange, 3, newValue);
    printColumn(array1, colIndexToChange, 3, 'A'); // 'A' stands for After

    return 0;
}
```

- We initialize a 2-d array in the main program.
- We call a function to print the values of a column before and after the changeusing a switch option.
- We change the content of a specific column by using a[i][colIndex] =newValue;


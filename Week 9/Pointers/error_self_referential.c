#include <stdio.h>

 struct list {
    int data;
    struct list *next_element;
};

int main()
{
    struct list first_node;
    // Run this program. Learn from the error. 

    // Why the error. 
}

// Fixed by adding * before "next_element"
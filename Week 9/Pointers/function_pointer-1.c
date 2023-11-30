# include <stdio.h>

void Prank_one() { printf("First type of prank\n"); } 
void Prank_two() { printf("Second_type_of_prank\n"); }

void wrapper( void (*function) () ) { 

    function();
}

int main()
{
    
    void (*function_variable)();
    
    function_variable = Prank_one;

    function_variable();

    function_variable = Prank_two;

    function_variable();
}
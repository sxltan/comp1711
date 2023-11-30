# include <stdio.h>

void Prank_one() { printf("First type of prank\n"); } 
void Prank_two() { printf("Second_type_of_prank\n"); }

void wrapper( void (*function) () ) { 

    function();
}

int main()
{
    char choice;
    printf("Enter the choice of prank = ");
    scanf(" %c",&choice);

    switch(choice)
    {
        case '1':
            wrapper(Prank_one); 
            break;
        case '2': 
            wrapper(Prank_two);
            break;
    }

    void (*function_variable)() = Prank_one;
}
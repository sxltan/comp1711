#include <stdio.h>

float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}

float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

float fahr_to_newton (float f_temp)
{
    float n_temp;
    n_temp = (f_temp - 32) / 5.45454555;
    return n_temp;
}

int main () 
{
    float fahrenheit;
    char option;

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit);

    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf ("Select C to convert to Newton\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option);

    switch (option)
    {
        case 'A':
        case 'a': printf ("Converted to degrees Celsius: %.2f\n", fahr_to_celsius(fahrenheit));
                  break;

        case 'B':
        case 'b': printf ("Converted to Kelvin: %.2f\n", fahr_to_kelvin(fahrenheit));
                  break;
        
        case 'C':
        case 'c': printf ("Converted to Newton: %.2f\n", fahr_to_newton(fahrenheit));
                  break;

        case 'Q':
        case 'q': printf ("You have decided to quit the program.\n");
                  break;

        default:  break;
    }

    return 0;
}
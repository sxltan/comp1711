#include <stdio.h>

int main() {

    int temperature;

    printf ("Enter the temperature: \n");
    scanf ("%d", &temperature);

    if (temperature >= -10 && temperature <= 40)
    {
        printf ("The temperature %d is perfectly between -10 and 40 degrees Celsius\n", temperature);
    }
    else
    {
        printf ("The temperature %d is not between -10 and 40 degrees Celsius\n", temperature);
    }
    return 0;
}
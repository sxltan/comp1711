#include <stdio.h>

int str_len (char* sentence) 
{
    int length = 0;
    while (*sentence != '\0')
    {
        length++;
        sentence++;
    }
    return length;
}

int main()
{
    char sentence[] = "Hello";
    int l = str_len(sentence);
    printf ("The amount of letters in %s is %i\n", sentence, l);
    return 0;
}
#include "main.h"
/**
* largest_number - returns the largest of 3 numbers
* @a: first integer
* @b: second integer
* @c: third integer
* Return: largest number
*/
int largest_number(int a, int b, int c)
{
    int largest;
    if (a > b && a > c)
    {
        largest = a;
    }
    else if (a > b && c > a)
    {
        largest = c;
    }
    else if (b > c)
    {
        largest = b;
    }
    else
    {
        largest = c;
    }
    return largest;
}

int main() {
    int a = 5, b = 10, c = 7;
    int largest = largest_number(a, b, c);
    
    printf("The largest number is: %d\n", largest);
    
    return 0;
}

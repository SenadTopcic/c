/*
Sum of digits in a C program allows a user to enter any number, divide that number into individual numbers, and sum those individual numbers.

Example 1:

Given number = 14892 => 1 + 4 + 8 + 9 + 2 = 24.

Sum of digits of a given number “14892” is 24.
*/
#include <stdio.h>
void sum_of_digits(char *num_char);

int main()
{
    char *num_char;
    printf("Please enter a number: ");
    scanf("%s", num_char);
    sum_of_digits(num_char);
    return (0);
}

// calculate sum of numbers in char number
void sum_of_digits(char *num_char)
{
    int result = 0;
    int i = 0;
    int is_digit = 1;
    while(num_char[i] != '\0')
    {
        if(num_char[i] >= 48 && num_char[i] <= 57 )
        {
            result += num_char[i] - 48;
        }
        else
        {
            is_digit = 0;
            break;
        }
        i++;
    }
    if (!is_digit)
    {
        printf("Please enter number");
    }else
        printf("Sum of digits of a given number %s is %d.", num_char, result);

}
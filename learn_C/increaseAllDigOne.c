/*
This is a C program to Increase 1 to all of the given Integer Digit.

Problem Description
This program increases 1 to all of the given integer digit and print the sum of all digits.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *user_number;
    int sign = 1;
    int i;
    int sum = 0;
    user_number = (char *)malloc(sizeof(char)*100);
    printf("Please enter a number : ");
    scanf("%s", user_number);

    i = 0;
    if (user_number[0] == '-')
    {
        sign = -1;
        i = 1;
    }
        //printf("OJHA %s", user_number);
    if (user_number[i] >= 48 && user_number[i] <= 57 )
    {    
        while (user_number[i] != '\0')
        {
            if(user_number[i] == '9')
                sum += 10;
            else if(user_number[i] >= '0' && user_number[i] < '9')
                sum += user_number[i] - 48 + 1;
            else
            {
                printf("Enter a valid number\n");
                return (0);
            }
            
            i++;
        }
    }else
    {
        printf("Enter a valid number\n");
        return (0);
    }
    printf("Sum of all digit increased by 1  = %d\n", sum*sign);
    return 0;
}


/*
This is a C Program which calculates the number of integers divisible by 5 in the given range.

Problem Description
1. This program takes the range as input and finds the number of integers divisible by 5 in the given range.
2. Also finds the sum of all integers that are divisible by 5 in the given range.
*/
#include <stdio.h>
void numbers_div_by_5(int i, int num);

int main()
{
    int star_range = 0;
    int end_range = 0;
    printf("Please enter a starting number in range: ");
    scanf("%d", &star_range);
    printf("Please enter a ending included number in range: ");
    scanf("%d", &end_range);
    numbers_div_by_5(star_range, end_range);
    return (0);
}

// Starting number represent "start_range", ending number represent "end_range"
void numbers_div_by_5(int start_range, int end_range)
{
    int sum_div_5 = 0;
    
    if (start_range - end_range != 0)
    {
        printf("List of numbers divisible by 5 is : ");
        while (start_range <= end_range)
        {
            if (start_range % 5 == 0 && end_range != 0)
            {
                sum_div_5 += start_range;
                if (start_range != end_range)
                    printf("%3d,", start_range);
                else
                    printf("%3d", start_range);
            }
            start_range++;
        } 
        printf("\nSum of all integers divisible by 5 = %d\n",sum_div_5);
    }else
        printf("There is no number divisible by 5!!!\n");
}
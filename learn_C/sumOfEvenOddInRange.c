/*
Problem Description
The program takes the number N and finds the sum of odd and even numbers from 1 to N.
*/

#include <stdio.h>

//version 1
int main()
{
    int i = 0;
    int sum_even = 0;
    int sum_odd = 0;
    int num = 0;
    printf("Please enter a range from 0 to N: ");
    scanf("%d", &num);
    while (i <= num)
    {
        if (i % 2 == 0)
            sum_even += i;
        else
            sum_odd += i;
        i++;
    } 
    printf("Sum of all even numbers is \t%d\nSum of all odd numbers is \t%d\n",sum_even, sum_odd);
}

//version 2
// int isNumEven(int num)
// {
//     int result = 0;

//     if (num & 1 == 1)
//         result = 0;
//     else
//         result = 1;
//     return result;
// }

// int main()
// {
//     int i = 0;
//     int sum_even = 0;
//     int sum_odd = 0;
//     int num = 0;
//     printf("Please enter a range from 0 to N: ");
//     scanf("%d", &num);
//     while (i <= num)
//     {
//         if(isNumEven(i))
//             sum_even += i;
//         else
//             sum_odd += i;
//         i++;
//     } 
//     printf("Sum of all even numbers is \t%d\nSum of all odd numbers is \t%d\n",sum_even, sum_odd);
// }
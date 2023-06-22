/*
Problem Description
Write a C Program to check whether a given number is even or odd.
*/
#include <stdio.h>
#include <stdlib.h>

// int main(int ac, char **argv)
// {
//     if (ac == 2)
//     {
//         int num1;
        
//         num1 = atoi(argv[1]);
//         (num1%2 == 0)? printf("Number %d is even!", num1) : printf("Number %d is odd!", num1);
//     }
//     return (0);
    
// }

//version 2 with if statement
// int main()
// {
//     int num;
//     printf("Please enter a number: ");
//     scanf("%d", &num);
//     if (num % 2 == 0)
//        printf("Number %d is even!", num);
//     else
//         printf("Number %d is odd!", num);
//     return (0);
// }

//version 3 with bitwise operator
int main()
{
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);
    if (num & 1 == 1)
       printf("Number %d is odd!", num);
    else
        printf("Number %d is even!", num);
    return (0);
}
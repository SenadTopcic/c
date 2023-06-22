/*
Problem Description
Write a C program that swaps the values of two variables based on user input.
*/
#include <stdio.h>

void swap_two_num(int *num1, int *num2)
{
    int tmp_var;
    tmp_var = *num1;
    *num1 = *num2;
    *num2 = tmp_var;
}

int main()
{
    int num1;
    int num2;
    printf("Please enter a number_1: ");
    scanf("%d", &num1);
    printf("Please enter a number_2: ");
    scanf("%d", &num2);
    
    printf("Before - Number_1 %d Number_2 %d \n", num1, num2);
    swap_two_num(&num1, &num2);
    printf("After  - Number_1 %d Number_2 %d \n", num1, num2);
    return (0);
}
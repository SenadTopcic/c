/*
Problem Description
Write a C program that takes the 3 numbers, sort them and finds the largest number Aamong three numbers.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **argv)
{
    if (ac == 4)
    {
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        int num3 = atoi(argv[3]);
        int arr_a[3];
        int arr_b[3];

        if (num1 < num2 && num1 < num3 ) 
        {
            if (num2 < num3)
            {
                arr_a[0] = num1;
                arr_a[1] = num2;
                arr_a[2] = num3;
            }else
            {
                arr_a[0] = num1;
                arr_a[1] = num3;
                arr_a[2] = num2;
            }
            
        }else if (num2 < num1 && num2 < num3 )
        {
            if (num1 < num3)
            {
                arr_a[0] = num2;
                arr_a[1] = num1;
                arr_a[2] = num3;
            }else
            {
                arr_a[0] = num2;
                arr_a[1] = num3;
                arr_a[2] = num1;
            }
            
        }else if (num3 < num1 && num3 < num2 )
        {
            if (num1 < num2)
            {
                arr_a[0] = num3;
                arr_a[1] = num1;
                arr_a[2] = num2;
            }else
            {
                arr_a[0] = num3;
                arr_a[1] = num2;
                arr_a[2] = num1;
            }
        }
        
        for (size_t i = 0; i < 3; i++)
        {
            printf("%d ",arr_a[i]);
        }
        printf("\n");
        printf("The largest number is %d\n",arr_a[2]);
    }
    return (0);   
}
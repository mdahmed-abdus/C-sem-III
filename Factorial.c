// factorial using recursion

#include <stdio.h>

int factorial(int num);

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    if (num >= 0)
        printf("Factorial of %d = %d\n", num, factorial(num));
    else
        printf("Invalid number\n");

    return 0;
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return (num * factorial(num - 1));
}

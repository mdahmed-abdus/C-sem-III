// gcd using recursion

#include <stdio.h>

int findGCD(int num1, int num2);

int main()
{
    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    int max = (num1 > num2) ? num1 : num2;
    int min = (num1 < num2) ? num1 : num2;

    printf("GCD of %d and %d is: %d\n", num1, num2, findGCD(max, min));

    return 0;
}

int findGCD(int num1, int num2)
{
    int remainder = num1 % num2;

    if (remainder == 0)
        return num2;
    else
        return findGCD(num1, remainder);
}

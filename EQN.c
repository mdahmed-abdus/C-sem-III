// exp(x, y) -> x^y using recursion

#include <stdio.h>

int calcEXP(int x, int y);

int main()
{
    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    printf("Result = %d\n", calcEXP(num1, num2));

    return 0;
}

int calcEXP(int x, int y)
{
    if (y == 0)
        return 1;
    else
        return (x * calcEXP(x, y - 1));
}

// fibonacci series using recursion

#include <stdio.h>

int fibonacci(int);

int main()
{
    int num;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("Fibonacci series is:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

int fibonacci(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return (fibonacci(num - 1) + fibonacci(num - 2));
}

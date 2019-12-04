// bubble sort

#include <stdio.h>

int main()
{
    int numbers[100];
    int size, temp;
    int i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - 1 - i; j++)
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }

    printf("Sorted elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}

// merge sort

#include <stdio.h>

void combine(int down, int middle, int up);
void mergeSort(int down, int up);

int numbers[100];
int temp[100];

int main()
{
    int i;
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    mergeSort(0, size - 1);

    printf("Sorted elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}

void combine(int down, int middle, int up)
{
    int i, j, k;
    k = i = down;
    j = middle + 1;

    while (i <= middle && j <= up)
    {
        if (numbers[i] <= numbers[j])
            temp[k++] = numbers[i++];
        else
            temp[k++] = numbers[j++];
    }
    while (i <= middle)
        temp[k++] = numbers[i++];
    while (j <= up)
        temp[k++] = numbers[j++];

    for (k = down; k <= up; k++)
        numbers[k] = temp[k];
}

void mergeSort(int down, int up)
{
    if (down < up)
    {
        int middle = (down + up) / 2;

        mergeSort(down, middle);
        mergeSort(middle + 1, up);
        combine(down, middle, up);
    }
}

// linear search

#include <stdio.h>

int linearSearch(int size, int toSearch);

int numbers[100];

int main()
{
    int i;
    int size;
    int toSearch, foundIndex;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &toSearch);

    foundIndex = linearSearch(size, toSearch);

    if (foundIndex == -1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n", foundIndex);

    return 0;
}

int linearSearch(int size, int toSearch)
{
    for (int i = 0; i < size; i++)
        if (numbers[i] == toSearch)
            return i;

    return -1;
}

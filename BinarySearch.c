// binary search

#include <stdio.h>

int binarySearch(int n, int x);

int numbers[100];

int main()
{
    int toSearch, size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements in ascending order\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &toSearch);

    int foundIndex = binarySearch(size, toSearch);

    if (foundIndex == -1)
        printf("Element not found\n");
    else
        printf("Element found at index: %d\n", foundIndex);

    return 0;
}

int binarySearch(int size, int toSearch)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;

        if (toSearch == numbers[middle])
            return middle;
        if (toSearch < numbers[middle])
            high = middle - 1;
        if (toSearch > numbers[middle])
            low = middle + 1;
    }

    return -1;
}

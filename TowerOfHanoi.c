// tower of hanoi

#include <stdio.h>

void towerOfHanoi(int n, char s, char d, char a);

int main()
{
    int noOfDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &noOfDisks);

    towerOfHanoi(noOfDisks, 'A', 'C', 'B');

    printf("\n");

    return 0;
}

void towerOfHanoi(int n, char s, char d, char a)
{
    if (n == 1)
        printf("\nMove from %c to %c", s, d);
    else
    {
        towerOfHanoi(n - 1, s, a, d);
        towerOfHanoi(1, s, d, a);
        towerOfHanoi(n - 1, a, d, s);
    }
}

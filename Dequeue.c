// input and output restriced queue (dequeue)

#include <stdio.h>
#define MAX 100

void inputDequeue();
void outputDequeue();

void insertLeft();
void insertRight();

void deletLeft();
void deletRight();

void display();

int deque[MAX];
int left = -1, right = -1;

int choice, value;

int main()
{
    do
    {

        printf("\nMain Menu\n1. Input restricted deque\n2. Output restricted deque\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputDequeue();
            break;

        case 2:
            outputDequeue();
            break;

        case 3:
            printf("Exitted\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 3);

    return 0;
}

void inputDequeue()
{
    do
    {
        printf("\nInput restricted dequeue - Menu\n");
        printf("1. Insert from right\n2. Delete from left\n3. Delete from right\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertRight();
            break;

        case 2:
            deletLeft();
            break;

        case 3:
            deletRight();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exitted - input restricted dequeue\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);
}

void outputDequeue()
{
    do
    {
        printf("\nOutput restricted dequeue - Main menu\n");
        printf("1.Insert at right\n2.Insert at left\n3.Delete from left\n4.Display\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertRight();
            break;

        case 2:
            insertLeft();
            break;

        case 3:
            deletLeft();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exitted - output restricted dequeue\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);
}

void insertRight()
{
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);

    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("Queue overflow\n");
        return;
    }
    else if (left == -1)
        left = right = 0;
    else if (right == MAX - 1)
        right = 0;
    else
        right = right + 1;

    deque[right] = value;
}

void insertLeft()
{
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);

    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("Queue overflow\n");
        return;
    }
    if (left == -1)
        left = right = 0;
    else if (left == 0)
        left = MAX - 1;
    else
        left = left - 1;

    deque[left] = value;
}

void deletLeft()
{
    if (left == -1) // if left = -1 then right = -1 -> condition for underflow
    {
        printf("Queue underflow\n");
        return;
    }

    printf("The deleted element is : %d\n", deque[left]);

    if (left == right)
        left = right = -1;
    else if (left == MAX - 1)
        left = 0;
    else
        left = left + 1;
}

void deletRight()
{
    if (left == -1) // if left = -1 then right = -1 -> condition for underflow
    {
        printf("Queue underflow\n");
        return;
    }

    printf("The element deleted is : %d\n", deque[right]);

    if (left == right)
        left = right = -1;
    else if (right == 0)
        right = MAX - 1;
    else
        right = right - 1;
}

void display()
{
    int front = left;
    int rear = right;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("The elements of the queue are:\n");
    if (front <= rear)
        while (front <= rear)
            printf("%d ", deque[front++]);
    else
    {
        while (front <= MAX - 1)
            printf("%d ", deque[front++]);

        front = 0;
        while (front <= rear)
            printf("%d ", deque[front++]);
    }
    printf("\n");
}

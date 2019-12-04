// circular queue using array

#include <stdio.h>
#define MAX 100

void insert(int cQueue[], int value);
int del(int cQueue[]);
int peek(int cQueue[]);
void display(int cQueue[]);

int cQueue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int choice, value;

    do
    {
        printf("\nMain Menu\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);

            insert(cQueue, value);
            break;

        case 2:
            value = del(cQueue);

            if (value != -1)
                printf("Deleted value is: %d\n", value);
            break;

        case 3:
            display(cQueue);
            break;

        case 4:
            printf("Exited\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

void insert(int cQueue[], int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else if (front != 0 && rear == MAX - 1)
        rear = 0;
    else
        rear++;

    cQueue[rear] = value;
}

int del(int cQueue[])
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow\n");
        return -1;
    }

    int deleted = cQueue[front];

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;

    return deleted;
}

void display(int cQueue[])
{
    int i;

    printf("Queue elements are:\n");
    if (front == -1 && rear == -1)
        printf("Queue is empty\n");
    else if (front < rear)
        for (i = front; i <= rear; i++)
            printf("%d ", cQueue[i]);
    else
    {
        for (i = front; i < MAX; i++)
            printf("%d ", cQueue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", cQueue[i]);
    }
}

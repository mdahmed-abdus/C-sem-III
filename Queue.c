// queue using array

#include <stdio.h>
#define MAX 100

void insert(int queue[], int value);
int del(int queue[]);
int peek(int queue[]);
void display(int queue[]);

int queue[MAX];
int front = -1;
int rear = -1;

int main()
{
    int choice;
    int value;

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

            insert(queue, value);
            break;

        case 2:
            value = del(queue);

            if (value != -1)
                printf("Deleted value is: %d", value);
            break;

        case 3:
            display(queue);
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

void insert(int queue[], int value)
{
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else
    {
        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;

        queue[rear] = value;
    }
}

int del(int queue[])
{
    if ((front == -1 && rear == -1) || front > rear)
    {
        printf("Queue underflow\n");
        return -1;
    }

    int deleted = queue[front];
    queue[front++] = -1;

    return deleted;
}

void display(int queue[])
{
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

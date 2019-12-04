// linear queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *insert(struct queue *queue, int value);
struct queue *delet(struct queue *queue);
struct queue *display(struct queue *queue);

int main()
{
    int choice;
    int value;

    struct queue *lQueue = (struct queue *)malloc(sizeof(struct queue));
    lQueue->front = NULL;
    lQueue->rear = NULL;

    do
    {
        printf("\nMain Menu\n");
        printf("1. Insert element\n2. Delete element\n3. Display queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted - in the queue: ");
            scanf("%d", &value);

            lQueue = insert(lQueue, value);
            break;

        case 2:
            lQueue = delet(lQueue);
            break;

        case 3:
            lQueue = display(lQueue);
            break;

        case 4:
            printf("Exited");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);

    printf("\n");
    return 0;
}

struct queue *insert(struct queue *lQueue, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (lQueue->front == NULL)
        lQueue->front = newNode;
    else
        lQueue->rear->next = newNode;

    lQueue->rear = newNode;

    return lQueue;
}

struct queue *delet(struct queue *lQueue)
{
    if (lQueue->front == NULL)
    {
        printf("Queue underflow, hence no value deleted\n");
        return lQueue;
    }

    struct node *ptr = lQueue->front;

    lQueue->front = lQueue->front->next;

    printf("The deleted element is: %d\n", ptr->data);
    free(ptr);

    return lQueue;
}

struct queue *display(struct queue *lQueue)
{
    if (lQueue->front == NULL)
    {
        printf("Queue is empty\n");
        return lQueue;
    }

    struct node *ptr = lQueue->front;

    printf("Queue elements are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return lQueue;
}

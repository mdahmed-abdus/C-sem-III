// priority queue

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *insert(struct node *start, int data, int priority);
struct node *delet(struct node *start);
struct node *display(struct node *start);

struct node *start = NULL;

int main()
{
    int choice;
    int data, priority;

    do
    {
        printf("\nMain Menu\n");
        printf("1. Insert element\n2. Delete element\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &data);
            printf("Enter its priority: ");
            scanf("%d", &priority);

            start = insert(start, data, priority);
            break;

        case 2:
            start = delet(start);
            break;

        case 3:
            start = display(start);
            break;

        case 4:
            printf("Exited\n");
            break;

        default:
            printf("Invlid choice\n");
            break;
        }
    } while (choice != 4);

    return 0;
}

struct node *insert(struct node *start, int data, int priority)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;

    newNode->data = data;
    newNode->priority = priority;

    if (start == NULL || priority < start->priority)
    {
        newNode->next = start;
        start = newNode;
        return start;
    }
    else
    {
        ptr = start;

        while (ptr->next != NULL && ptr->next->priority <= priority)
            ptr = ptr->next;

        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    return start;
}

struct node *delet(struct node *start)
{
    if (start == NULL)
    {
        printf("Queue underflow, hence no value deleted\n");
        return start;
    }

    struct node *ptr = start;

    start = start->next;

    printf("The deleted element is: %d\n", ptr->data);
    free(ptr);

    return start;
}

struct node *display(struct node *start)
{
    if (start == NULL)
    {
        printf("Queue is empty\n");
        return start;
    }

    struct node *ptr = start;

    printf("Queue elements are:\n");
    while (ptr != NULL)
    {
        printf("Element = %d\tPriority = %d\n", ptr->data, ptr->priority);
        ptr = ptr->next;
    }

    return start;
}
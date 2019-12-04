// doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insertBegin(struct node *start);
struct node *insertBefore(struct node *start);
struct node *insertAfter(struct node *start);
struct node *insertEnd(struct node *start);

struct node *deletBegin(struct node *start);
struct node *deletNode(struct node *start);
struct node *deletBefore(struct node *start);
struct node *deletAfter(struct node *start);
struct node *deletEnd(struct node *start);

struct node *display(struct node *start);
struct node *displayReverse(struct node *start);

struct node *start = NULL;

int location;
int choice;

int main()
{
    do
    {
        printf("\nMain Menu\n");
        printf("1. Insert - beginning\n2. Insert - before\n3. Insert - after\n4. Insert - end\n");
        printf("5. Delete - beginning\n6. Delete - node\n7. Delete - before\n8. Delete - after\n");
        printf("9. Delete - end\n10. Display\n11. Display in reverse\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = insertBegin(start);
            break;

        case 2:
            start = insertBefore(start);
            break;

        case 3:
            start = insertAfter(start);
            break;

        case 4:
            start = insertEnd(start);
            break;

        case 5:
            start = deletBegin(start);
            break;

        case 6:
            start = deletNode(start);
            break;

        case 7:
            start = deletBefore(start);
            break;

        case 8:
            start = deletAfter(start);
            break;

        case 9:
            start = deletEnd(start);
            break;

        case 10:
            start = display(start);
            break;

        case 11:
            start = displayReverse(start);
            break;

        case 12:
            printf("Exited");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 12);

    printf("\n");
    return 0;
}

struct node *insertBegin(struct node *start)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value to be inserted - at the beginning: ");
    scanf("%d", &newNode->data);

    if (start == NULL)
    {
        newNode->next = newNode->prev = NULL; // for singly ll, newNode->next = NULL
        start = newNode;
    }
    else
    {
        start->prev = newNode; //for singly ll, this is not needed
        newNode->next = start;
        newNode->prev = NULL; // for singly ll, this is not needed
        start = newNode;
    }

    return start;
}

struct node *insertBefore(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty, hence adding the value at the beginning\n");
        start = insertBegin(start);
        return start;
    }

    printf("Enter the location - before which the new node will be added: ");
    scanf("%d", &location);

    if (start->data == location)
    {
        printf("Location is at the beginning of the list, hence adding the value at the beginning\n");
        start = insertBegin(start);
        return start;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = start;
    struct node *preptr = ptr;

    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);

    while (ptr->data != location)
    {
        preptr = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("Invalid location, hence value not added\n");
            free(newNode); // deleting the newNode since it is not added to the list
            return start;
        }
    }

    preptr->next = newNode;
    newNode->prev = preptr; // for singly ll, this is not needed
    newNode->next = ptr;
    ptr->prev = newNode; // for singly ll, this is not needed

    return start;
}

struct node *insertAfter(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty, hence adding the value at the beginning\n");
        start = insertBegin(start);
        return start;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = start;
    struct node *preptr = ptr;

    printf("Enter the location - after which the new node will be added: ");
    scanf("%d", &location);

    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);

    if (start->data == location)
    {
        preptr = start;
        ptr = start->next;
    }
    else
        while (preptr->data != location)
        {
            preptr = ptr;
            ptr = ptr->next;

            if (preptr == NULL)
            {
                printf("Invalid location, hence value not added\n");
                free(newNode); // deleting the newNode since it is not added to the list
                return start;
            }
        }

    preptr->next = newNode;
    newNode->prev = preptr; // for singly ll, this is not needed
    newNode->next = ptr;
    ptr->prev = newNode; // for singly ll, this is not needed

    return start;
}

struct node *insertEnd(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty, hence adding the value at the beginning\n");
        start = insertBegin(start);
        return start;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = start;

    printf("Enter the value to be inserted - at the end: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr; // for singly ll, this is not needed

    return start;
}

struct node *deletBegin(struct node *start)
{
    if (start == NULL)
    {
        printf("List underflow, hence no value deleted\n");
        return start;
    }

    struct node *ptr = start;

    start = start->next;
    start->prev = NULL; // for singly ll, this is not needed

    printf("Deleted value is: %d\n", ptr->data);
    free(ptr);

    return start;
}

struct node *deletNode(struct node *start)
{
    if (start == NULL)
    {
        printf("List underflow, hence no value deleted\n");
        return start;
    }

    printf("Enter the value of the node to be deleted: ");
    scanf("%d", &location);

    if (start->data == location)
    {
        start = deletBegin(start);
        return start;
    }

    struct node *ptr = start;
    struct node *preptr = ptr;

    while (ptr->data != location)
    {
        preptr = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("Invalid location, hence no value deleted\n");
            return start;
        }
    }

    preptr->next = ptr->next;
    ptr->next->prev = preptr; //for singly ll, this is not needed

    printf("Deleted value is: %d\n", ptr->data);
    free(ptr);

    return start;
}

struct node *deletBefore(struct node *start)
{
    if (start == NULL)
    {
        printf("List underflow, hence no value deleted\n");
        return start;
    }

    printf("Enter the location - before which the new node will be deleted: ");
    scanf("%d", &location);

    if (start->data == location)
    {
        printf("Invalid location, hence no value deleted\n");
        return start;
    }
    else if (start->next->data == location)
    {
        start = deletBegin(start);
        return start;
    }

    struct node *postptr = start;
    struct node *ptr = postptr;
    struct node *preptr = ptr;

    while (postptr->data != location)
    {
        preptr = ptr;
        ptr = postptr;
        postptr = postptr->next;

        if (postptr == NULL)
        {
            printf("Invalid location, hence no value deleted\n");
            return start;
        }
    }

    preptr->next = postptr;
    postptr->prev = preptr; // for singly ll, this is not needed

    printf("Deleted value is: %d\n", ptr->data);
    free(ptr);

    return start;
}

struct node *deletAfter(struct node *start)
{
    if (start == NULL)
    {
        printf("List underflow, hence no value deleted\n");
        return start;
    }

    struct node *ptr = start;
    struct node *preptr = ptr;

    printf("Enter the location - after which the node has to be deleted: ");
    scanf("%d", &location);

    if (start->data == location)
    {
        preptr = start;
        ptr = start->next;

        if (ptr == NULL) // i.e., only one node in the list
        {
            printf("Invalid location, hence no value deleted\n");
            return start;
        }
    }
    else
        while (preptr->data != location)
        {
            preptr = ptr;
            ptr = ptr->next;

            if (ptr == NULL)
            {
                printf("Invalid location, hence no value deleted\n");
                return start;
            }
        }

    preptr->next = ptr->next;
    ptr->next->prev = preptr; // for singly ll, this is not needed

    printf("Deleted value is: %d\n", ptr->data);
    free(ptr);

    return start;
}

struct node *deletEnd(struct node *start) // same as singly ll
{
    if (start == NULL)
    {
        printf("List underflow, hence no value deleted\n");
        return start;
    }

    if (start->next == NULL)
    {
        start = NULL;
        return start;
    }

    struct node *ptr = start;
    struct node *preptr = ptr;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = ptr->next; // or preptr->next = NULL (since ptr->next is NULL)

    printf("Deleted value is: %d\n", ptr->data);
    free(ptr);

    return start;
}

struct node *display(struct node *start) // same as singly ll
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    struct node *ptr = start;

    printf("List elements are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return start;
}

struct node *displayReverse(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    struct node *ptr = start;

    while (ptr->next != NULL)
        ptr = ptr->next;

    printf("List elements in reverse are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");

    return start;
}
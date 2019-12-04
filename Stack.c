// stack using array

#include <stdio.h>
#define MAX 100

void push(int stack[], int value);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);

int stack[MAX];
int top = -1;

int main()
{
    int choice, value;

    do
    {
        printf("\nMain Menu\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);

            push(stack, value);
            break;

        case 2:
            value = pop(stack);

            if (value != -1)
                printf("Popped value is: %d", value);
            break;

        case 3:
            value = peek(stack);

            if (value != -1)
                printf("Top value is: %d", value);
            break;

        case 4:
            display(stack);
            break;

        case 5:
            printf("Exited\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

    } while (choice != 5);

    return 0;
}

void push(int stack[], int value)
{
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = value;
}

int pop(int stack[])
{
    int temp = -1;

    if (top == -1)
        printf("Stack underflow\n");
    else
    {
        temp = stack[top];
        stack[top--] = -1;
    }

    return temp;
}

int peek(int stack[])
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }

    return stack[top];
}

void display(int stack[])
{
    if (top == -1)
        printf("Stack empty\n");
    else
    {
        printf("Stack elements are:\n");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }
}

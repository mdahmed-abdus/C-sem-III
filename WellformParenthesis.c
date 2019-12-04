// wellform parenthesis

#include <stdio.h>
#define MAX 100

void checkExp(char exp[]);
void push(int stack[], int value);
int pop(int stack[]);

int stack[MAX];
int top = -1;

int main()
{
    char exp[100];

    printf("Enter the expression: ");
    gets(exp);

    checkExp(exp);

    printf("\n");
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
    if (top == -1) //underflow condition -> invalid parenthesis
        return -1;

    top--;

    return 1;
}

void checkExp(char exp[])
{
    int i = 0;
    int temp;

    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            push(stack, i);
        else if (exp[i] == ')')
        {
            temp = pop(stack);

            if (temp == -1)
            {
                top = 1;
                break;
            }
        }
        i++;
    }

    if (top == -1) // stack empty -> valid parenthesis
        printf("Valid parenthesis");
    else // stack not empty -> '(' is more than ')', hence invalid parenthesis
        printf("Invalid parenthesis\n");
}
// evaluate postfix expression // incompelte

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

void push(char stack[], char value);
char pop(char stack[]);
void evaluatePostfix(char postfix[]);

char stack[MAX];
int top = -1;

int main()
{
    int i;
    char postfix[MAX];

    printf("Enter the postfix expression: ");
    gets(postfix);

    evaluatePostfix(postfix);

    return 0;
}

void push(char stack[], char value)
{
    if (top != MAX - 1)
        stack[++top] = value;
    else
    {
        printf("Invalid expression\n");
        exit(1);
    }
}

char pop(char stack[])
{
    if (top != -1)
        return stack[top--];

    printf("Invalid expression\n");
    exit(1);
    return '0';
}

void evaluatePostfix(char postfix[])
{
    int value;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char chr = postfix[i];

        if (isdigit(chr))
            push(stack, chr);
        else if (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '%')
        {
            int a = (int)pop(stack);
            int b = (int)pop(stack);

            switch (chr)
            {
            case '*':
                value = b * a;
                break;

            case '/':
                value = b / a;
                break;

            case '+':
                value = b + a;
                break;

            case '-':
                value = b - a;
                break;

            default:
                break;
            }

            push(stack, value);
        }
    }

    printf("Result = %d\n", pop(stack));
}

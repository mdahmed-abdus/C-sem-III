// infix to postfix

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void push(char stack[], char value);
char pop(char stack[]);
int getPriority(char operator);
void infixToPostfix(char source[], char target[]);

char stack[MAX];
int top = -1;

int main()
{
    char infix[100], postfix[100];
    strcpy(postfix, "");

    printf("Enter the infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: ");
    puts(postfix);

    printf("\n");
    return 0;
}

void push(char stack[], char value)
{
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = value;
}

char pop(char stack[])
{
    char temp = ' ';

    if (top == -1)
        printf("Stack underflow\n");
    else
        temp = stack[top--];

    return temp;
}

int getPriority(char operator)
{
    if (operator== '*' || operator== '/' || operator== '%')
        return 1;

    return 0;
}

void infixToPostfix(char source[], char target[])
{
    int i, j;
    i = j = 0;

    strcpy(target, "");

    while (source[i] != '\0')
    {
        if (source[i] == '(')
            push(stack, source[i++]);
        else if (source[i] == ')')
        {
            while ((top != -1) && (stack[top] != '('))
                target[j++] = pop(stack);
            if (top == -1)
            {
                printf("Incorrect expression\n");
                exit(1);
            }
            pop(stack); // to remove left parenthesis
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
            target[j++] = source[i++];
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' ||
                 source[i] == '%')
        {
            while ((top != -1) && (stack[top] != '(') && (getPriority(stack[top]) > getPriority(source[i])))
                target[j++] = pop(stack);

            push(stack, source[i++]);
        }
        else
        {
            printf("Incorrect element in expression\n");
            exit(1);
        }
    }

    while ((top != -1) && (stack[top] != '('))
        target[j++] = pop(stack);

    target[j] = '\0';
}
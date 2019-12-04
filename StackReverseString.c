// reverse a string using stack

#include <stdio.h>
#include <string.h>
#define MAX 100

void push(char stack[], char value);
char pop(char stack[]);

char stack[MAX];
int top = -1;

int main()
{
    char str[100];
    int i;

    printf("Enter the String: ");
    gets(str);

    //push string into stack
    for (i = 0; i < strlen(str); i++)
        push(stack, str[i]);

    //string will be popped in reverse order
    printf("The string in reverse order is:\n");
    for (i = 0; i < strlen(str); i++)
        printf("%c", pop(stack));
    printf("\n");

    return 0;
}

void push(char stack[], char value)
{
    stack[++top] = value;
}

char pop(char stack[])
{
    char value = stack[top];
    stack[top--] = -1;
    return value;
}

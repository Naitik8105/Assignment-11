#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

char pop()
{
    if (top == -1)
    {
        printf("Empty Stack\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}

void reverse_string(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = pop();
    }
}

int main()
{
    char string[MAX_SIZE];
    printf("Input a string to be reversed: ");

    // gets(string);
    fgets(string, MAX_SIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    reverse_string(string);
    printf("Reversed string using a stack is: %s\n", string);
    return 0;
}
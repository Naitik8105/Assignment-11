#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char arr[100];
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        printf("The stack is full.Cannot perform given operation\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is empty.Cannot perform given operation.\n");
    }
    else
    {
        return ptr->arr[ptr->top--];
    }
}
char stackTop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}
int main()
{
    struct stack s1;
    s1.size = 100;
    s1.top = -1;
    char input[100];
    printf("Enter the input string: ");
    gets(input);
    push(&s1, input[0]);
    int i = 1;
    while (input[i] != '\0')
    {
        if (stackTop(&s1) == input[i])
        {
            char temp = pop(&s1);
        }
        else
        {
            push(&s1, input[i]);
        }
        i++;
    }
    char output[i + 1];
    i = 0;
    while (!isEmpty(&s1))
    {
        output[i] = pop(&s1);
        i++;
    }
    input[i] = '\0';
    strrev(output);
    printf("The output string is : ");
    puts(output);
    return 0;
}

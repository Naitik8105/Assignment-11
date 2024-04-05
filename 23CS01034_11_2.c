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

int main()
{
    char string[MAX_SIZE];
    printf("Input a string: ");
    fgets(string, MAX_SIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    push(string[0]);
    char x;
    for(int i = 1;i < strlen(string); ++i){
        if(stack[top] == string[i]){
            x = pop();
        }
        else{
            push(string[i]);
        }
    }
    char ans[MAX_SIZE];
    ans[top] = '\0';
    int i = 0;
    while(top != -1){
       ans[i] = stack[top] ;
       x = pop();
       ++i;
    }
    strrev(ans);
    printf("%s", ans);
    return 0;
}
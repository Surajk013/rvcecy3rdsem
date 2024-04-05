#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 20
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s, char item)
{
    s->data[++(s->top)] = item;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];
}
int preced(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 5;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 1;
    }
}
void infixtoprefix(STACK *s, char infix[SIZE])
{
    int i, j = 0;
    char *str1;
    char prefix[SIZE], temp, symbol;
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        symbol = infix[i];
        if (isalnum(symbol))
            prefix[j++] = symbol;
        else
        {
            switch (symbol)
            {
            case ')':
                push(s, symbol);
                break;
            case '(':
                temp = pop(s);
                while (temp != ')')
                {
                    prefix[j++] = temp;
                    temp = pop(s);
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (s->top == -1 || s->data[s->top] == ')')
                    push(s, symbol);
                else
                {
                    while (preced(s->data[s->top]) >
                               preced(symbol) &&
                           s->top != -1 && s->data[s->top] != ')')
                        prefix[j++] = pop(s);
                    push(s, symbol);
                }
                break;
            default:
                printf("\n Invalid!!!!!");
                exit(0);
            }
        }
    }
    while (s->top != -1)
        prefix[j++] = pop(s);
    prefix[j] = '\0';
    str1 = strrev(prefix);
    printf("\n The prefix expression is %s\n", str1);
}
int main()
{
    STACK s;
    s.top = -1;
    char infix[SIZE];
    printf("\n Read Infix expression\n");
    scanf("%s", infix);
    infixtoprefix(&s, infix);
    return 0;
}
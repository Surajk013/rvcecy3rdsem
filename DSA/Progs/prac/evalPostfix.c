#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s, float item)
{
    s->data[++(s->top)] = item;
}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}
float operate(float op1, float op2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    }
}
float eval(STACK *s, char postfix[SIZE])
{
    int i;
    char symbol;
    float res, op1, op2;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];
        if (isdigit(symbol))
            push(s, symbol - '0');
        else
        {
            op2 = pop(s);
            op1 = pop(s);
            res = operate(op1, op2, symbol);
            push(s, res);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[SIZE];
    STACK s;
    float ans;
    s.top = -1;
    printf("\n Read postfix expr\n");
    scanf("%s", postfix);
    ans = eval(&s, postfix);
    printf("\n The final answer is %f\n", ans);
    return 0;
}
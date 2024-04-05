#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int count;
struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;
NODE push(NODE start, int item)
{
    NODE temp;
    if (count >= SIZE)
    {
        printf("\n Stack Overflow");
        return start;
    }
    else
    {
        temp = (NODE)malloc(sizeof(struct node));
        count = count + 1;
        temp->data = item;
        temp->addr = NULL;
        if (start == NULL)
            return temp;
        temp->addr = start;
        return temp;
    }
}
NODE pop(NODE start)
{
    NODE temp;
    if (start == NULL)
    {
        printf("\n stack Underflow");
        return start;
    }
    else
    {
        temp = start;
        start = start->addr;
        printf("\n Element popped is %d\n", temp->data);
        count = count - 1;
        return start;
    }
}
void display(NODE start)
{
    NODE temp;
    if (start == NULL)
        printf("\n Stack is empty");
    else
    {
        printf("\n Stack Content are\n");
        temp = start;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->addr;
        }
    }
}
int main()
{
    NODE start = NULL;
    int item, ch;
    for (;;)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\n Read choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Read data to be pushed:");
            scanf("%d", &item);
            start = push(start, item);
            break;
        case 2:
            start = pop(start);
            break;
        case 3:
            display(start);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
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
NODE insertend(NODE last, int item)
{
    NODE temp;
    if (count >= SIZE)
    {
        printf("\n Queue full");
        return last;
    }
    count = count + 1;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    if (last == NULL)
    {
        temp->addr = temp;
        return temp;
    }
    else
    {
        temp->addr = last->addr;
        last->addr = temp;
        return temp;
    }
}
NODE deletebegin(NODE last)
{
    NODE temp;
    if (last == NULL)
    {
        printf("\n Queue empty");
        return NULL;
    }
    if (last->addr == last)
    {
        printf("\n Element deleted is %d\n", last->data);
        free(last);
        return NULL;
    }
    else
    {
        temp = last->addr;
        last->addr = temp->addr;
        printf("\n Element deleted is %d\n", temp->data);
        free(temp);
        return last;
    }
}
void display(NODE last)
{
    NODE temp;
    if (last == NULL)
        printf("\n Queue is empty");
    else
    {
        printf("\n Queue Content are\n");
        temp = last->addr;
        while (temp != last)
        {
            printf("%d\t", temp->data);
            temp = temp->addr;
        }
        printf("%d\t", temp->data);
    }
}
int main()
{
    NODE last = NULL;
    int item, ch;
    for (;;)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nRead Choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Read data to be inserted:");
            scanf("%d", &item);
            last = insertend(last, item);
            break;
        case 2:
            last = deletebegin(last);
            break;
        case 3:
            display(last);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
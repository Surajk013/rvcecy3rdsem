#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;
NODE insertend(NODE head, int item)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = NULL;
    if (head->addr == NULL)
    {
        head->addr = temp;
        return head;
    }
    else
    {
        cur = head->addr;
        while (cur->addr != NULL)
            cur = cur->addr;
        cur->addr = temp;
        return head;
    }
}
NODE insertbegin(NODE head, int item)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->addr = NULL;
    if (head->addr == NULL)
    {
        head->addr = temp;
        return head;
    }
    else
    {
        temp->addr = head->addr;
        head->addr = temp;
        return head;
    }
}
void display(NODE head)
{
    NODE temp;
    if (head->addr == NULL)
        printf("\n List is Empty");
    else
    {
        temp = head->addr;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->addr;
        }
    }
}
void appendzero(NODE head1, NODE head2)
{
    int ct1 = 0, ct2 = 0, i;
    NODE cur;
    cur = head1->addr;
    while (cur != NULL)
    {
        ct1 = ct1 + 1;
        cur = cur->addr;
    }
    cur = head2->addr;
    while (cur != NULL)
    {
        ct2 = ct2 + 1;
        cur = cur->addr;
    }
    if (ct1 > ct2)
    {
        for (i = 0; i < ct1 - ct2; i++)
            head2 = insertbegin(head2, 0);
    }
    else
    {
        for (i = 0; i < ct2 - ct1; i++)
            head1 = insertbegin(head1, 0);
    }
}
NODE reverse(NODE head)
{
    NODE next, prev, cur;
    cur = head->addr;
    prev = NULL;
    while (cur != NULL)
    {
        next = cur->addr;
        cur->addr = prev;
        prev = cur;
        cur = next;
    }
    head->addr = prev;
    return head;
}
void add(NODE head1, NODE head2)
{
    NODE t1, t2, head;
    int sum, carry = 0;
    head = (NODE)malloc(sizeof(struct node));
    head->addr = NULL;
    head1 = reverse(head1);
    head2 = reverse(head2);
    t1 = head1->addr;
    t2 = head2->addr;
    while (t1 != NULL)
    {
        sum = t1->data + t2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        head = insertbegin(head, sum);
        t1 = t1->addr;
        t2 = t2->addr;
    }
    if (carry != 0)
        head = insertbegin(head, carry);
    printf("\n The added number is\n");
    display(head);
}
int main()
{
    NODE head1, head2;
    char first[20], second[20];
    int i, j;
    printf("\n Read first number :");
    scanf("%s", first);
    head1 = (NODE)malloc(sizeof(struct node));
    head1->addr = NULL;
    for (i = 0; first[i] != '\0'; i++)
        head1 = insertend(head1, first[i] - '0');
    printf("\n First Number is\n");
    display(head1);
    printf("\n Read second number :");
    scanf("%s", second);
    head2 = (NODE)malloc(sizeof(struct node));
    head2->addr = NULL;
    for (i = 0; second[i] != '\0'; i++)
        head2 = insertend(head2, second[i] - '0');
    printf("\n Second Number is\n");
    display(head2);
    appendzero(head1, head2);
    printf("\n First Number is\n");
    display(head1);
    printf("\n Second Number is\n");
    display(head2);
    add(head1, head2);
    return 0;
}
#include <stdio.h>

struct node
{
    int ele;
    struct node *next;
};

typedef struct node *LIST;
typedef LIST L;

L ListInsert(int num, L p)
{
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    if (p->next != NULL)
        temp->next = p->next;
    else
        temp->next = NULL;
    p->next = temp;
    return p;
}
L findInsert(int num, L h)
{
    L temp;
    temp = h;
    while (temp->next != NULL && temp->ele != num)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    printf("Enter the number of elements ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the elements : ");
    int arr[n], x;
    L head;
    head = (LIST)malloc(sizeof(LIST));
    head->ele = 0;
    head->next = NULL;
    L p = head;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        p = ListInsert(x, p);
        p = p->next;
    }

    p = head;
    p = p->next;
    while (p != NULL)
    {
        printf("%d ", p->ele);
        p = p->next;
    }

    int y;
    printf("\nEnter the element to be inserted : ");
    scanf("%d", &x);
    printf("\nAfter which element: ");
    scanf("%d", &y);

    p = findInsert(y, head);
    p = ListInsert(x, p);
    p = head->next;
    printf("\nAfter insertion : ");
    while (p != NULL)
    {
        printf("%d ", p->ele);
        p = p->next;
    }
    return 0;
}
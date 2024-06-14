#include <stdio.h>

struct node
{
    int ele;
    struct node *next;
};

typedef struct node *LIST;
typedef LIST L;

L CreateNode(int num)
{
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    temp->next = NULL;
    return temp;
}
L InsertNode(L p, int num)
{
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    p->next = temp;
    temp->next = NULL;
    return temp;
}

int main()
{
    printf("Enter the number of elements : ");
    int n;
    scanf("%d", &n);
    L head;
    head = NULL;
    L p = head;
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (head == NULL)
        {
            head = CreateNode(num);
            p = head;
        }
        else
            p = InsertNode(p, num);
    }

    printf("\nAfter insertion : ");
    p = head;
    int count = 0;
    while (p != NULL)
    {
        printf("%d ", p->ele);
        p = p->next;
        count++;
    }
    printf("\nNumber of nodes : %d", count);

    return 0;
}

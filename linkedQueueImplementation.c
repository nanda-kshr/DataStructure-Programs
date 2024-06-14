#include <stdio.h>
#define max 5
#include <stdlib.h>
struct node
{
    int ele;
    struct node *next;
};

typedef struct node *LIST;
typedef LIST L;

L CreateNode()
{
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->next = NULL;
    return temp;
}
L InsertAtBeginning(int num)
{
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    temp->next = NULL;
    return temp;
}
L InsertAtEnd(L REAR, int num)
{
    L p = REAR;
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    p->next = temp;
    temp->next = NULL;
    return temp;
}
L DeleteAtBeginning(L head)
{
    L p = head;
    head = head->next;
    p->next = NULL;
    free(p);
    return head;
}
void Display(L head)
{
    L p = head;
    if (p == NULL)
        printf("\nNo element to print");

    while (p != NULL)
    {
        printf("%d ", p->ele);
        p = p->next;
    }
}
int main()
{
    L FRONT = NULL, REAR = NULL;
    int ele;

    int ch;
    printf("\nEnter \n1 - Enqueue \n2 - Dequeue\n3 - Display\n0 - Exit\n");
    scanf("%d", &ch);
    do
    {
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            printf("\nEnter the element to enqueue : ");
            scanf("%d", &ele);

            if (REAR == NULL)
            {
                FRONT = InsertAtBeginning(ele);
                REAR = FRONT;
                printf("\nInserted the element ");
            }
            else
            {
                REAR = InsertAtEnd(REAR, ele);
                REAR = FRONT;
                REAR->ele = ele;
                printf("\nInserted the element ");
            }
            break;
        case 2:
            if (FRONT == NULL)
                printf("\nQueue is Empty. You cant Dequeue");
            else
            {
                printf("\nDequeued the element %d", FRONT->ele);
                FRONT = DeleteAtBeginning(FRONT);
            }
            break;
        case 3:
            if (FRONT == NULL)
                printf("Queue is empty");
            else
                for (L i = FRONT; i != NULL; i = i->next)
                    printf("%d ", i->ele);
            break;
        default:
            printf("\nEnter a valid number : ");
            break;
        }
        printf("\nEnter \n1 - Enqueue \n2 - Dequeue\n3 - Display\n0 - Exit\n");
        scanf("%d", &ch);
    } while (ch > 0 && ch <= 3);
    return 0;
}
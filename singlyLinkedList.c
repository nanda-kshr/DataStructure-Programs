#include <stdio.h>
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
void InsertAtEnd(L head, int num)
{
    L p = head;
    while (p->next != NULL)
        p = p->next;
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    p->next = temp;
    temp->next = NULL;
    // return temp;
}
L InsertAtBeginning(L head1, int num)
{
    L temp;
    temp = (LIST)malloc(sizeof(LIST));
    temp->ele = num;
    temp->next = head1;
    head1 = temp;
    return head1;
}
void InsertAfterElement(L head, int num, int a)
{
    L p = head;
    while (p->ele != a && p->next != NULL)
    {
        p = p->next;
    }

    if (p->next == NULL && p->ele != a)
    {
        printf("\nElement not found...enter some other positon");
    }
    else
    {
        L temp;
        p = p->next;
        temp = (LIST)malloc(sizeof(LIST));
        temp->ele = num;
        temp->next = p->next;
        p->next = temp;
        printf("\nElement is pushed");
        // return temp;
    }
}

L DeleteAtEnd(L head)
{
    L p = head;
    while (p->next->next != NULL)
        p = p->next;
    L temp = p->next;
    p->next = NULL;
    free(temp);
    return p;
}
L DeleteAtBeginning(L head)
{
    L p = head;
    head = head->next;
    p->next = NULL;
    free(p);
    return head;
}
void DeleteThisElement(L head, int num)
{
    L p = head;
    while (p->next->ele != num && p->next != NULL)
        p = p->next;
    if (p->next->ele != num)
    {
        printf("\nElement not found");
    }
    else
    {
        L temp = p->next;
        p->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
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
    int ch, ele;
    L head = NULL, p = head;
    printf("\nEnter \n1 - Insert Node\n2 - Delete Node\n3 - Display Node\n0 - Exit\n");
    scanf("%d", &ch);
    do
    {
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            if (head == NULL)
            {
                printf("\nEnter the element to push : ");
                scanf("%d", &ele);
                head = CreateNode();
                head->ele = ele;
                p = head;
                printf("\nPushed");
            }
            else
            {
                int ch1;
                printf("\nEnter \n1 - Insert at beginning \n2 - Insert at end \n3 - Insert after a number \n0 - exit\n");

                scanf("%d", &ch1);
                do
                {
                    switch (ch1)
                    {

                    case 1:
                        printf("\nEnter the element to push : ");
                        scanf("%d", &ele);
                        head = InsertAtBeginning(head, ele);
                        printf("\nElement is pushed");

                        break;
                    case 2:
                        printf("\nEnter the element to push : ");
                        scanf("%d", &ele);
                        InsertAtEnd(head, ele);
                        printf("\nElement is pushed");
                        break;
                    case 3:
                        printf("\nEnter the element to push : ");
                        scanf("%d", &ele);
                        printf("\nAfter which element ");
                        int a;
                        scanf("%d", &a);
                        InsertAfterElement(head, ele, a);

                        break;
                    case 0:
                        break;
                    default:
                        printf("Enter a valid Option ");
                    }
                    printf("\nEnter \n1 - Insert at beginning \n2 - Insert at end \n3 - Insert after a number \n0 - exit\n");

                    scanf("%d", &ch1);
                } while (ch1 <= 3 && ch1 > 0);
            }
            break;
        case 2:
            if (head == NULL)
            {
                printf("\nNo element to POP");
            }
            else
            {
                int ch1;
                printf("\nEnter \n1 - Delete at beginning \n2 - Delete at end \n3 - Delete a number \n0 - exit\n");

                scanf("%d", &ch1);
                do
                {
                    switch (ch1)
                    {
                    case 1:
                        head = DeleteAtBeginning(head);
                        break;
                    case 2:
                        p = DeleteAtEnd(head);
                        break;
                    case 3:
                        printf("\nDelete which element ");
                        int a;
                        scanf("%d", &a);
                        DeleteThisElement(head, a);
                        break;
                    case 0:
                        break;
                    default:
                        printf("\nEnter a valid Number ");
                        break;
                    }
                    printf("\nelement is deleted");
                    printf("Enter \n1 - Delete at beginning \n2 - Delete at end \n3 - Delete a number \n0 - exit");

                    scanf("%d", &ch1);
                } while (ch1 > 0 && ch1 <= 3);
            }
            break;
        case 3:
            Display(head);
            break;
        default:
            printf("\nEnter a valid number : ");
            break;
        }
        printf("\nEnter \n1 - Insert Node\n2 - Delete Node\n3 - Display Node\n0 - Exit\n");
        scanf("%d", &ch);
    } while (ch > 0 && ch <= 3);
    return 0;
}
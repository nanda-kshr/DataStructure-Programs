#include <stdio.h>
#define max 5

int main()
{
    int q[max];
    int ele, FRONT = -1, REAR = -1;

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

            if (REAR == max - 1)
                printf("\nQueue is Full. You cant Insert");
            else if (REAR == -1)
            {
                FRONT++;
                REAR++;
                q[REAR] = ele;
                printf("\nInserted the element ");
            }
            else
            {
                REAR++;
                q[REAR] = ele;
                printf("\nInserted the element ");
            }
            break;
        case 2:
            if (FRONT > REAR || FRONT == -1)
                printf("\nQueue is Empty. You cant Dequeue");
            else
            {
                printf("\nDequeued the element %d", q[FRONT]);
                FRONT++;
            }
            break;
        case 3:
            if (FRONT > REAR || FRONT == -1)
                printf("Stack is empty");
            else
                for (int i = FRONT; i <= REAR; i++)
                    printf("%d ", q[i]);
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
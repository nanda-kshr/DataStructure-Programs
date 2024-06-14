#include <stdio.h>
#define max 5

int main()
{
    int s[max];
    int ele, TOP = -1;

    int ch;
    printf("\nEnter \n1 - Push \n2 - POP\n3 - Display\n0 - Exit\n");
    scanf("%d", &ch);
    do
    {
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            printf("\nEnter the element to push : ");
            scanf("%d", &ele);
            if (TOP == max - 1)
                printf("\nStack is Full. You cant PUSH");
            else
            {
                TOP++;
                s[TOP] = ele;
                printf("\nPushed the element ");
            }
            break;
        case 2:
            if (TOP == -1)
                printf("\nStack is Empty. You cant POP");
            else
            {
                printf("\nPopped the element %d", s[TOP]);
                TOP--;
            }
            break;
        case 3:
            if (TOP == -1)
                printf("Stack is empty");
            else
                for (int i = 0; i <= TOP; i++)
                    printf("%d ", s[i]);
            break;
        default:
            printf("\nEnter a valid number : ");
            break;
        }
        printf("\nEnter \n1 - Push \n2 - POP\n3 - Display\n0 - Exit\n");
        scanf("%d", &ch);
    } while (ch > 0 && ch <= 3);
    return 0;
}
#include <stdio.h>
int main()
{
    printf("Enter the number of elements ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the elements : ");
    int arr[n], x;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter the element to search : ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++)
        if (arr[i] == x)
        {
            printf("\nElement is found at %d", i);
            return 1;
        }
    printf("Element not found ");
    return 0;
}
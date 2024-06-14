#include <stdio.h>
int main()
{
    printf("Enter the number of elements ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the elements : ");
    int arr[n + 1], x, p;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter the element to insert : ");
    scanf("%d", &x);
    printf("\nEnter the position : ");
    scanf("%d", &p);
    for (int i = n; i >= p; i--)
    {
        arr[i + 1] = arr[i];
    }
    n++;
    arr[p] = x;
    printf("\nnew array is ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
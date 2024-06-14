#include <stdio.h>
int main()
{
    printf("Enter the number of elements ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the elements : ");
    int arr[n + 1], x;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter the element to delete : ");
    scanf("%d", &x);
    for (int i = n - 1; arr[i] != x && i > 0; i--)
    {
        arr[i - 1] = arr[i];
    }
    n--;
    printf("\nnew array is ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
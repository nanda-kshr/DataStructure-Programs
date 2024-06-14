#include <stdio.h>
int main()
{
    printf("Enter the number of elements of 1st array: ");
    int n;
    scanf("%d", &n);

    printf("\nEnter the number of elements of 2nd array ");
    int m;
    scanf("%d", &m);
    printf("\nEnter the elements of 1st array: ");
    int arr[n + m];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nEnter the elements of 2nd array : ");
    int b[n];
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m; i++)
        arr[n + i] = b[i];

    for (int i = 0; i < m + n; i++)
        printf("%d ", arr[i]);
    return 0;
}
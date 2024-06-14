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
    int low = 0, high = n;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            printf("\nElement is found at %d", mid);

            return 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("Element not found ");
    return 0;
}
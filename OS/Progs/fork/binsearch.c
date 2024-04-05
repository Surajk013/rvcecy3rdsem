#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return 1;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void swap(int *xp, int *yp)
{

    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main(void)
{

    int n, key, arr[10];
    printf("Enter the number of elements in the array:  ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, n);
    printf("Enter element to be searched:  ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present");
    return 0;
}

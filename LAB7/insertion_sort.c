#include <stdio.h>

void Insertion_Sort(int arr[], int n)
{
    int temp;
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    printf("Sorted list using Insertion Sort:\n");
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int n, i, j, temp;

    printf("Enter number of elements\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    Insertion_Sort(arr, n);

    return 0;
}
#include <stdio.h>

// Utility function to print LIS
void printLDS(int arr[], int n)
{   printf("The LDC length is: %d",n);
    printf("\nThe LDS is: ");
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to construct and print Longest Increasing Subsequence
void constructPrintLDS(int arr[], int n)
{
    int L[n];
    int path[n];
    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        L[i] = 1;
        path[i] = -1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j] && L[i] < L[j] + 1)
            {
                L[i] = L[j] + 1;
                path[i] = j;
            }
        }
        if (L[i] > maxLen)
        {
            maxLen = L[i];
        }
    }

    int lds[maxLen];
    int t = 0;
    for (int i = 1; i < n; i++)
    {
        if (L[i] == maxLen)
        {
            t = i;
            break;
        }
    }

    for (int i = maxLen - 1; i >= 0; i--)
    {
        lds[i] = arr[t];
        t = path[t];
    }

    // Print the LDS
    printLDS(lds, maxLen);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    // Construct and print LIS of arr
    constructPrintLDS(arr, n);

    return 0;
}


















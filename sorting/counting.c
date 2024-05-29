#include<stdio.h>  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  
int main() {  
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
   
    printf("Before sorting array elements are - \n");  
    printArr(arr, size);  
    countSort(arr, size);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(arr,size );  
    return 0;  
  
}  

/*
Best Case Complexity - It occurs when there is no sorting required, 
i.e. the array is already sorted.
 The best-case time complexity of counting sort is O(n + k).

Average Case Complexity - It occurs when the array elements are in jumbled 
order that is not properly ascending and not properly descending.
The average case time complexity of counting sort is O(n + k).

Worst Case Complexity - It occurs when the array elements are required to be sorted in reverse order.
 That means suppose you have to sort the array elements in ascending order,
  but its elements are in descending order.
   The worst-case time complexity of counting sort is O(n + k).

In all above cases,
 the time complexity of counting sort is same.
  This is because the algorithm goes through n+k times, 
  regardless of how the elements are placed in the array.

Counting sort is better than the comparison-based sorting techniques 
because there is no comparison between elements in counting sort. 
But, when the integers are very large the counting sort is bad because arrays of that size have to be created.
*/
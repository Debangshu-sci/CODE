#include <stdio.h>

// A function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
  // Loop through all elements
  for (int i = 0; i < n - 1; i++) {
    // Loop through unsorted elements
    for (int j = 0; j < n - i - 1; j++) {
      // Compare adjacent elements and swap if needed
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

// A function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// A main function to test the program
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
  printf("Original array: \n");
  printArray(arr, size);

  // Sort the array using bubble sort
  bubbleSort(arr, size);

  // Print the sorted array
  printf("\nSorted array: \n");
  printArray(arr, size);

  return 0;
}


/*
What is bubble sort?
Bubble sort is a sorting algorithm that uses comparison methods to sort an array.
The algorithm compares pairs of elements in an array and swaps them if the left pair(position) is greater than the right pair(position+1). This process is repeated until the entire array is sorted.


How many passes does bubble sort require?
Bubble Sort requires n(n-1)/2 passes through all elements in order for the final array to be sorted in ascending order.

What is the worst time complexity of bubble sort?
The worst time complexity of bubble sort is O(n2).

What is the best time complexity of bubble sort?
The best time complexity of bubble sort is O(n), and this occurs when the array is already sorted.

What is the space complexity of bubble sort?
Bubble sort has an O(1) space complexity, as it works in-place by modifying the input directly.
*/
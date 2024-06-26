// C Program to implement Radix Sort
#include <stdio.h>

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	// output array
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);}

        printf("\n");


}

// Driver program to test above functions
int main()
{
	 int size;
 printf("Enter the size: ");
 scanf("%d", &size);
 int arr[size];
 printf("Enter the elements of array: ");
 for (int i = 0; i < size; i++)
 {
     scanf("%d", &arr[i]);
 }
printf("The original array: ");	
print(arr, size);
	// Radix sort function
	radixsort(arr, size);

  printf("The sorted array:  ");
	print(arr, size);
	return 0;
}

/*
Complexity Analysis of Radix Sort:
Time Complexity: 

Radix sort is a non-comparative integer sorting algorithm that sorts
 data with integer keys by grouping the keys by the individual
  digits which share the same significant position and value. 
  It has a time complexity of O(d * (n + b)), where d is the number of digits,
   n is the number of elements, and b is the base of the number system being used.
In practical implementations,
 radix sort is often faster than other comparison-based sorting algorithms,
  such as quicksort or merge sort, for large datasets,
   especially when the keys have many digits. However,
    its time complexity grows linearly with the number of digits,
	 and so it is not as efficient for small datasets.

Auxiliary Space: 

Radix sort also has a space complexity of O(n + b),
 where n is the number of elements and b is the base of the number system.
This space complexity comes from the need to create buckets for each digit value and to copy the elements back to the original array after each digit has been sorted.
Frequently Asked Questions about RadixSort

Q1. Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort? 
If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.

Q2.What if the elements are in the range from 1 to n2?

The lower bound for the Comparison based sorting algorithm (Merge Sort, 
Heap Sort, Quick-Sort .. etc) is Ω(nLogn), i.e.,
 they cannot do better than nLogn.
  Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in the range from 1 to k.
We can’t use counting sort becaus
e counting sort will take O(n2) which is worse than comparison-based sorting algorithms.
 Can we sort such an array in linear time? 
Radix Sort is the answer.
 The idea of Radix Sort is to do digit-by-digit sorting starting from the least significant digit to the most significant digit.
  Radix sort uses counting sort as a subroutine to sort.
*/
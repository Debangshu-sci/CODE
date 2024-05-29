// Heap Sort in C

#include <stdio.h>

// Function to swap the position of two elements

void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
	// Find largest among root,
	// left child and right child

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int left = 2 * i + 1;

	// right = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest
	// so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// Swap and continue heapifying
	// if root is not largest
	// If largest is not root
	if (largest != i) {

		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);

		// Heapify root element
		// to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);}

        printf("\n");

}

// Driver's code
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
	

	// Function call
	heapSort(arr, size);
	
    printf("The sorted array:  ");
	print(arr, size); 
	
}

/*
Heap Sort - Key takeaways
Heap Sort is a sorting technique that implements binary heap data structure,
using 'Heapify' and 'BuildHeap' operations and following a 'bottom-up' approach,
to kind an array in ascending order by removing the largest element from heap.

Heap Sort structures include Max-Heap and Min-Heap.
 The algorithm initially uses Max-Heap to sort in ascending order as
the largest element is stored at the root of the Max-Heap.

Heap Sort's best, worst, and average time complexity
 are all O(n log n) making it one of the most efficient sorting techniques. 
 However, it isn't stable, meaning equal-sort items may not keep their relative order, 
 which might affect data of complex type.
In analysing Heap Sort Time Complexity,
 best-case scenario occurs when elements are already sorted,
  the worst-case when smallest or largest element is always chosen,
   and on average, it takes O(n log n) time.
    Heap Sort guarantees O(n log n) performance unlike Quick Sort which can deteriorate to O(n^2) in the worst-case scenario.
Heap Sort Pseudocode illustrates the process of heap sort including
 creation of max heap from the unsorted array, repeatedly extracting
  maximum from the heap, and restoring heap property after each removal
   until all elements are sorted.*/

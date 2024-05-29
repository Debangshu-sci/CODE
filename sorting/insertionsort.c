#include<stdio.h>




void insertionsort(int arr[],int size){
     int i,index,value;

     for(i=1;i<size;i++){
        value=arr[i];
        index=i;
     while (index>0 && arr[index-1]>value)
     {
        arr[index]=arr[index-1];
        index--;
     }
      arr[index]=value;  

     }
};


int main(){
     int size;
 printf("Enter the size: ");
 scanf("%d", &size);
 int arr[size];
 printf("Enter the elements of array: ");
 for (int i = 0; i < size; i++)
 {
     scanf("%d", &arr[i]);
 }
    
    insertionsort(arr,size);
    for(int i =0;i<size;i++){
        printf("  %d  ",arr[i]);
    }
    return 0;
}

/*
Is Insertion Sort Stable?
Yes, insertion sort is a stable sorting algorithm.
A stable sorting algorithm is one that maintains the relative order of equal elements in the sorted output.
In other words, if two elements have the same value, their relative order in the input array should be preserved in the sorted array.

What Kind of Algorithm is Insertion Sort?
Insertion sort is a comparison-based algorithm.
It compares the current and previous elements to determine their correct position in the sorted list.
 It is a simple and efficient algorithm that is easy to implement.

Is Insertion Sort a Greedy Algorithm?
No, insertion sort is not a greedy algorithm.
A greedy algorithm is an algorithm that makes a locally optimal choice at each step with the hope of finding a global optimum.
Insertion sort does not make any locally optimal choice but instead inserts each element in its correct position to achieve the global optimum.

Time Complexity of Insertion Sort Algorithm
The time complexity of the insertion sort algorithm is O(n^2) in the worst case and O(n) in the best case.

Best Case Running Time of an Insertion Sort Algorithm
The best-case running time of an insertion sort algorithm is O(n). This occurs when the input array is sorted, and no elements must be moved.
This results in n-1 comparisons, which is approximately equal to n. Therefore, the time complexity is O(n).

Best Case Time Efficiency of Insertion Sort
The best-case time efficiency of an insertion sort algorithm is Ω(n), which is the lower bound of the running time. This occurs when the input array is sorted and no elements need to be moved.

Worst Time Complexity of Insertion Sort
The worst-case time complexity of an insertion sort algorithm is O(n^2).
This occurs when the input array is in reverse order, and each element must be moved to its correct position by shifting all the larger elements to the right.
The input array is in reverse order. Every element has to be compared and swapped with every other element in the array. This results in n*(n-1)/2 comparisons and swaps, approximately equal to n^2/2. Therefore, the time complexity is O(n^2).

Average Case Running Time of an Insertion Sort Algorithm
The average case running time of an insertion sort algorithm is O(n^2).
This occurs when the input array is randomly ordered, and each element must be moved to its correct position by shifting all the larger elements to the right.

Typical Runtime for Insertion Sort for Singly Linked Lists
Insertion sort can also be used to sort singly-linked lists.

The typical runtime for insertion sort for singly linked lists is also O(n^2), the same for arrays. However, the space complexity may differ due to the data structure difference.

Does Insertion Sort Use Divide and Conquer?
No, insertion sort does not use the Divide and Conquer approach.

Divide and Conquer is an algorithmic paradigm that involves breaking a problem into sub-problems, solving them independently, and then combining their solutions to solve the original problem.

Insertion sort works by sorting the elements individually without breaking the problem into sub-problems.

Why is Insertion Sort Slow?
Insertion sort is slow because it has a time complexity of O(n^2) in the worst case.

This means that as the input size increases, the algorithm's running time also increases rapidly. Insertion sort is not the best choice for large input sizes, but it can be very efficient for small input sizes or for partially sorted data.

Wrapping Up
Insertion sort is a simple and efficient algorithm for small input sizes or partially sorted data. It has a time complexity of O(n^2) in the worst case and O(n) in the best case.
*/
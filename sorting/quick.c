#include<stdio.h>
#define max 25
void quicksort(int number[max],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
int main(){
   int i, count, number[max];
   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);
   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
   scanf("%d",&number[i]);
   quicksort(number,0,count-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
   printf(" %d",number[i]);
   return 0;
}

/*
Time Complexity Analysis of Quick Sort:
Let us consider the following terminologies:

T(K): Time complexity of quicksort of K elements
P(K): Time complexity for finding the position of pivot among K elements.

Best Case:
The best case occurs when we select the pivot as the mean. So here
T(N) = 2 * T(N / 2) + N * constant
Now T(N/2) is also 2*T(N / 4) + N / 2 * constant. So,
T(N) = 2*(2*T(N / 4) + N / 2 * constant) + N * constant
= 4 * T(N / 4) + 2 * constant * N.
So, we can say that
T(N) = 2k * T(N / 2k) + k * constant * N
then, 2k = N
k = log2N
So T(N) = N * T(1) + N * log2N. Therefore, the time complexity is O(N * logN).

Worst Case:
The worst case will occur when the array gets divided into two parts,
 one part consisting of N-1 elements and the other and so on. So,
T(N) = T(N – 1) + N * constant
= T(N – 2) + (N – 1) * constant + N * constant = T(N – 2) + 2 * N * constant – constant
= T(N – 3) + 3 * N * constant – 2 * constant – constant
= T(N – k) + k * N * constant – (k – 1) * constant – . . . – 2*constant – constant
= T(N – k) + k * N * constant – constant * (k*(k – 1))/2
If we put k = N in the above equation, then
T(N) = T(0) + N * N * constant – constant * (N * (N-1)/2)
= N2 – N*(N-1)/2
= N2/2 + N/2
So the worst case complexity is O(N2)

Average Case:
For the average case consider the array gets divided into two parts of size k and (N-k). So,
T(N) = T(N – k) + T(k)
= 1 / N * [ \sum_{i = 1}^{N-1} T(i)    + \sum_{i = 1}^{N-1} T(N-i)    ]
As \sum_{i = 1}^{N-1} T(i)    and \sum_{i = 1}^{N-1} T(N-i)    are equal likely functions, we can say
T(N) = 2/N * [ \sum_{i = 1}^{N-1} T(i)    ]
N * T(N) = 2 * [ \sum_{i = 1}^{N-1} T(i)    ]
Also, we can write
(N – 1) * T(N – 1) = 2 * [ \sum_{i = 1}^{N-2} T(i)    ]
If we subtract the above two equations, we get
N * T(N) – (N – 1) * T(N – 1) = 2 * T(N – 1) + N2 * constant – (N – 1)2 * constant
N * T(N) = T(N – 1) * (2 + N – 1) + constant + 2 * N * constant – constant
= (N + 1) * T(N – 1) + 2 * N * constant
Divide both side by N*(N-1) and we will get
T(N) / (N + 1) = T(N – 1)/N + 2 * constant / (N + 1)      — (i)
If we put N = N-1 it becomes
T(N – 1) / N = T(N – 2)/(N – 1) + 2*constant/N
Therefore, the equation (i) can be written as
T(N) / (N + 1) = T(N – 2)/(N – 1) + 2*constant/(N + 1) + 2*constant/N
Similarly, we can get the value of T(N-2) by replacing N by (N-2) in the equation (i).
 At last it will be like
T(N) / (N + 1) = T(1)/2 + 2*constant * [1/2 + 1/3 + . . . + 1/(N – 1) + 1/N + 1/(N + 1)]
T(N) = 2 * constant * log2N * (N + 1)
If we ignore the constant it becomes
T(N) = log2N * (N + 1)
So the time complexity is O(N * logN).

Space Complexity Analysis of Quick Sort
The required space is O(1) as we are not using any extra space in the algorithm.
if we don’t consider the recursive stack space.
If we consider the recursive stack space then,
 in the worst case quicksort could make O(N).
*/
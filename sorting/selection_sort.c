#include<stdio.h>


void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;

};

void selectionsort(int arr[],int size){
     int i,j;
     for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
     }
};

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);}

        printf("\n");

}

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
printf("The original array: ");	
print(arr, size);
    
selectionsort(arr,size);

 printf("The sorted array:  ");
	print(arr, size); 
       
    return 0;
}
/*
The number of comparisons in selection sort can be
 calculated as the sum of (n-1) + (n-2) + (n-3) + ... + 1   ,
 which is approximately equal to n(n-1)/2   
  or roughly n^2. This results in a time complexity of O(n^2). 
*/
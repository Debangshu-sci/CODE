// This code implemented using Algorithm in Coremen book
 
#include<stdio.h>
#include<limits.h>
 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
 
int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix
 
    //Here L is chain length. It varies from length 2 to length n.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  //assigning to maximum value
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    }
 
    return m[1][n-1];   //returning the final answer which is M[1][n]
 
}
 
int main()
{
    int n,i;
    printf("Enter number of matrices\n");
    scanf("%d",&n);
 
    n++;
 
    int arr[n];
 
    printf("Enter dimensions \n");
 
    for(i=0;i<n;i++)
    {
        printf("Enter d%d :: ",i);
        scanf("%d",&arr[i]);
    }
 
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d ", MatrixChainMultiplication(arr, size));
 
    return 0;

}
/*Time Complexity: The time complexity of the dynamic programming approach is O(n^3), 
where n is the number of matrices. 
This is because we have nested loops iterating over the matrix dimensions to fill in the optimal costs.

Space Complexity: The space complexity of the dynamic programming approach is O(n^2), 
where n is the number of matrices. 
This is the space required to store the matrices for optimal costs and split points.*/

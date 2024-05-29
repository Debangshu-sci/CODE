#include<stdio.h>
#include<stdlib.h>

int minmum_cost(int matrix[20],int t){
    int x,small;
    if(t==1) return matrix[0];
    else{small=matrix[0];
         for(x=1;x<t;x++)
         if(matrix[x]<small)small=matrix[x];
        return small;
        }
}

int main(){
    int t,i,l,j,k,limit,f;
    int matrix[30],multipliere[10][15]={0},column[15],rows[15],temp[15];
    printf("Enter the total num of matrix: \t");
    scanf("%d",&limit);
    for ( i = 0; i < limit; i++)
    {
        printf("\n Enter Num of rows of %d:\t",i+1);
        scanf("%d",&rows[i]);
        printf("\n Enter Num of columns of %d:\t",i+1);
        scanf("%d",&column[i]);
     }
    printf("\n\n\n");
    for (i = 0; i < limit; i++)
    temp[i]=rows[i];

    temp[i]=column[i-1];
    
    for ( l = 2; l <= limit; l++)
    {
       for ( j = l,i=1; j <=limit; j++,i++)
       {
        t=0;
        for ( k = i; k <j; k++)
        {
            matrix[t]=(multipliere[i][k]+multipliere[k+1][j])+(temp[i-1]*temp[k]*temp[j]);
            t++;
        }
        multipliere[i][j]=minmum_cost(matrix,t);

       }
       
    }
    printf("\nMinmum Scalar Multiplication:\t%d\n",multipliere[1][limit]);
    return 0;
}
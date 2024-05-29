#include<stdio.h>

int fibdp(int n,int dp[]){
   if(n==0||n==1)
   return dp[n]=n;

   if(dp[n]!=-1)
   return dp[n];

   int subAns1=fibdp(n-1,dp);
   int subAns2=fibdp(n-2,dp);

   dp[n]=subAns1+subAns2;

   return dp[n];

}


int main(){
    int n;
    printf("Enter the NUM: ");
    scanf("%d",&n);
    
    int dp[100];
    for(int i=0;i<n+1;i++)
    dp[i]=-1;


    int fib= fibdp(n,dp);
    printf("\n%d",fib);
}
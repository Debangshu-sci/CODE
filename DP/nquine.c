#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#define SIZE 30
int position[SIZE]={0};   

int place(int k){ 
	int i;
	for(i=1;i<k;i++){
	    if((position[i]==position[k])||((abs(position[i]-position[k])==abs(i-k)))) /*if same column or same diagonal*/
	    	return 0;
	}
	return 1;
}
void print_sol(int n){
	int i,j;
	printf("\n\n The solution: \n" );	
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
	        if(position[i]==j)
	            printf("Q\t");
	        else
	            printf("*\t");
	        }
	    printf("\n");
	}
}
int queen(int k, int n){ 
	if (k==0)
		return 0;
	position[k]=position[k]+1;
	while((position[k]<=n)&&!place(k)){
	    position[k]++;
	}
	if(position[k]<=n){ 
	    if(k==n){ 
	        print_sol(n);
	        return 1;
	    }
	    else{
	       
			position[++k]=0; 
	        queen(k,n);
	    }
	}
	else
	    queen(k-1,n); 
}

int main(){
	int n;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
	if(!queen(1,n)) /*1 is for the first queen*/
		printf("\n No valid solution!\n");

}

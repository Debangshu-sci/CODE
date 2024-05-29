#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
char infix[MAX];char postfix[MAX];
int top=-1;

void push(char symbol){
   if(top == MAX-1){
      printf("The stack is overflow");
      return;
   }
   top++;
   stack[top]=symbol;
}

char pop(){
   if(top==-1){
      printf("The stack is underflow");
      exit(1);
   }
   char c;
   c=stack[top];
   top=top-1;
   return c;
}

int isEmpty(){
   if(top==-1){
      return 1;
   }
   else{
   return 0;
   }
}

int precedence(char symbol){
   switch (symbol)
   {
   case '^':
      return 3;

   case '/':
   case '*':
      return 2;

   case '+':
   case '-':
      return 1;


   default:
      return 0;
   }
}
int isSpace(char symbol){
   if(symbol==' '|| symbol=='\t')
     return 1;
   else
   return 0;  
   

}
void intopost(){
    int j=0;
    char symbol, next ;
    for(int i=0;i<strlen(infix);i++ ){
       symbol=infix[i];
      if (!isSpace(symbol))
      {
        
      
       
      switch (symbol)
       {
      case '(':
        push(symbol);
        break;

      case ')':
         while ((next=pop()) != '(')
         {
            postfix[j] = next;
            j=j+1;
         }
         break;

      case '+': 
      case '-': 
      case '*': 
      case '/': 
      case '^':
        while (!isEmpty() && precedence(stack[top]>=precedence(symbol)))
        {
         postfix[j++]=pop();
        }
        push(symbol);break;
       
      default:
        postfix[j]=symbol;
        j=j+1; 

       }
      }
    }

    while (!isEmpty())
    {
      postfix[j++]=pop();
    }
    postfix[j]='\0';
    
}

void print(){
   int i=0;
   printf("The equvalant postfix Expression is: ");
   while(postfix[i]){
      printf("%c",postfix[i++]);
   }
   printf("\n");
}


int main(){

printf("Enter the Infix expression: ");
gets(infix);

intopost();

print();
 
return 0;
}
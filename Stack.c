#include<Stdio.h>
#include <stdlib.h>
struct arrayStack{
int top;
int capacity;
int *array;
};
 struct arrayStack *stack;
 void creatingStack(int cap){
	 stack=(struct arrayStack *)malloc(sizeof( struct arrayStack));
     stack->capacity=cap;	 
     stack->top=-1;
     stack->array=malloc(sizeof(4*(cap)));
 }
 
 void push(){
	 int data;
	 if(stack->top==(stack->capacity)-1){
		 printf("\n stack is overflow \n");
	 }
	 else{
	     printf("\n enter the number that u want to insert in the stack=> ");
	     scanf("%d",&data);
		 stack->top= stack->top+1;
	     stack->array[ stack->top]=data;
	 }
 }
 
 void pop(){
	 int data;
	 if(stack->top==-1){
		 printf("\n stack is underflow \n");
		 
	 }
	 else{
	 data=stack->array[ stack->top];
	  stack->top= stack->top-1;
	   printf("\n poped data => %d \n",data);
	 }
	
	 
 }
 
 void main(){
printf("\n <<<<<<<<-----------WELCOME TO MY STACK---------->>>>>>>>> \n");
printf("\n enter the capacity of the strack =>");
int cap;
scanf("%d",&cap);
creatingStack(cap);
 while(1){
	 int n;
     printf("\n Click on-> \n 1->push \n 2->pop \n 3->exit \n");
     scanf("%d",&n);
 switch(n){
	 case 1:push();break;
	 case 2:pop();break;
	 case 3:exit(0);break;
 }
 }	 
 }
 
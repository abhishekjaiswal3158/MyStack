#include<stdio.h>
#include <stdlib.h>
#define max 100
int stack[max];
int top=-1;

void push(int *stk,int *top,int data){
    if(*top==(max-1)){
        printf("!!!!!!!STACK OVERFLOW!!!!!!!!!!\n");
    }
    else
    {
        (*top)++;
        stk[*top]=data;
    }
    
}

int   pop(int *stk,int *top){
if(*top==-1){
    printf("!!!!!!!STACK OVERFLOW!!!!!!!!!!\n");
}
else{
    int data=stk[*top];
    (*top)--;
    return data;
}
}

int peek(int *stk,int *top){
    if(*top==-1){
    printf("!!!!!!!STACK OVERFLOW!!!!!!!!!!\n"); 
}
else
{
    return stk[*top];
}

}

void display(int *stk,int *top){
    if(*top==-1){
    printf("!!!!!!!STACK OVERFLOW!!!!!!!!!!\n");
  
}
else
{
    printf("THE ELEMENT IN THE STACK =");
    for(int i=*top;i>=0;i--){
        printf("%d\n",stk[i]);
    }
}

}



int main(){
    printf("!!!!!!!!!!<<<<<<<<WELCOME TO MY STACK>>>>>>>>!!!!!!!!!!");
   while (1)
   {
    printf("\n<<<<<<<<<<<-----------MENU---------->>>>>>>>>>>>>\n");
    printf("1=PUSH ELEMENT\n2=POP ELEMENT\n3=PEEK ELEMENT\n4=DISPLAY THE ELEMENTS OF STACK\n5=CLOSE THE PROGRAM\nENTER THE SERIAL NO TO DO OPERATION ON STACK=");
    int num;
    scanf("%d",&num);
    switch (num)
    {
    case 1:
        printf("ENTER THE NUMBER THAT YOU WANT TO PUSH INTO THE STACK=");
        int data;
        scanf("%d",&data);
        push(&stack[0],&top,data);
        break;
    case 2:
    if(top!=-1)
        printf("THE DELETED DATA= %d",pop(&stack[0],&top));
        else
        pop(&stack[0],&top);
        break;
    case 3:
    if(top!=-1)
        printf("THE PEEK ELEMENT OF THE STACK= %d",peek(&stack[0],&top));
    else
        peek(&stack[0],&top);
        break;
    case 4:
        display(&stack[0],&top);
        break;
    case 5:
          exit(0);
    default:
        printf("\n!!!!!!!!!!YOU HAVE ENTERED WRONG NUMBER!!!!!!!!!!!!\n");
        printf("PLEASE WRITE THE RIGHT NUMBER\n");
        break;
    }
 
}
}
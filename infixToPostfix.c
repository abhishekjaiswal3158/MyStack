#include<stdio.h>
#include <stdlib.h>

typedef struct stack_using_linked_list SLL;
struct stack_using_linked_list
{
    char data;
    SLL *next;
}*top=NULL;

void push(SLL **top,char data){
    SLL *new_node=(SLL *)malloc(sizeof(SLL));
    if(new_node==NULL){
        printf("!!!!!!!!STACK OVERFLOW!!!!!!!!!!\n");
    }
    else{
        new_node->next=NULL;
        new_node->data=data;
        if(*top==NULL){
            *top=new_node;
        }
        else{
            new_node->next=*top;
            *top=new_node;
        }
    }
}

char pop(SLL **top){
    if(*top==NULL){
        printf("!!!!!!!!STACK UNDERFLOW!!!!!!!!!!pop\n");
    }
    else{
        SLL *temp=*top;
        char data=temp->data;
        (*top)=(*top)->next;
        free(temp);
return data;
    }
}

void display(SLL ** top){
     if(*top==NULL){

     }
     else{
        SLL *temp=*top;
        while(temp!=NULL){
            printf("%c",temp->data);
            temp=temp->next;
        }
     }
}

int priority(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'||c=='%'){
        return 2;
    }
    else if(c=='(')
    {
     return 0;   
    }
}

int main(){
    printf("ENTER THE STRING THAT U WANT TO CONVERT FROM INFIX TO POSTFIX=");
    char s[100],out[100];
    gets(s);
    int i=0;
    int j=0;
    while(s[i]!='\0'){
    if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122||s[i]>=48&&s[i]<=57){
    out[j]=s[i];
    j++;
    }
    else if(s[i]=='('){
        push(&top,s[i]);
    }
    else if(s[i]==')'){
       while(1){
           char popped=(pop(&top));
           if(popped=='('){
               break;
           }
           else{
               out[j]=popped;
               j++;
           }
       }
    }
    else{
        if(top!=NULL){
       while(priority(s[i])<=priority(top->data)&&top!=NULL){
            out[j]=pop(&top);
            j++;
        }}
        push(&top,s[i]);
        }
        i++;
    }
  
    
     out[j]='\0';
     for(int k=0;k<j;k++){
         printf("%c",out[k]);
     }
     display(&top);
}
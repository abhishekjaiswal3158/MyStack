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
        printf("!!!!!!!!STACK UNDERFLOW!!!!!!!!!!\n");
    }
    else{
        SLL *temp=*top;
        int data=temp->data;
        (*top)=(*top)->next;
        free(temp);
return data;
    }
}

char peek(SLL **top){
     if(*top==NULL){
        printf("!!!!!!!!STACK UNDERFLOW!!!!!!!!!!\n");
    }
    else{
        return (*top)->data;
    }
}

void display(SLL ** top){
     if(*top==NULL){
        printf("!!!!!!!!STACK UNDERFLOW!!!!!!!!!!\n");
    }
    else{
        printf("ELEMENT IN THE STACK=");
        SLL *temp=*top;
        while(temp!=NULL){
            printf("%c\n",temp->data);
            temp=temp->next;
        }
    }
}

int checker(SLL **top,char s[]){
    int check=0;
    int i=0;
while (s[i]!='\0')
{
   
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
        push(top,s[i]);
    }
    else if(s[i]==')'||s[i]=='}'||s[i]==']'){
        if(s[i]==')'&&peek(top)=='('){
            pop(top);
        }
        else if(s[i]=='}'&&peek(top)=='{'){
            pop(top);
        }
        else if(s[i]==']'&&peek(top)=='['){
            pop(top);
        }

        else{
          return check;
        }
    }
i++;
}
if(*top==NULL){
    check=1;
   return check;
}
else{
    return check;
}
}

int main(){
    printf("ENTER THE STRING THAT U WANT TO CHECK=");
    char s[100];
    gets(s);
int check=checker(&top,s);
if(check==0){
    printf("not correct");
}
else if(check==1){
    printf("correct");
}

return 0;
}
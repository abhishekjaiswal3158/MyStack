#include<stdio.h>
#include <stdlib.h>

typedef struct stack_using_linked_list SLL;
struct stack_using_linked_list
{
    int data;
    SLL *next;
}*top1=NULL,*top2=NULL;

void push(SLL **top,int data){
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

int pop(SLL **top){
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

int peek(SLL **top){
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
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void reverse(SLL **top,SLL **revTop ){
    if(*top==NULL){
        printf("!!!!!!!!!!!!!STACK UNDERFLOW!!!!!!!!!!");
    }
    else{
        SLL *temp=*top;
        while(temp!=NULL){
            push(revTop,temp->data);
            temp=temp->next;
        }
    }
}

void deleteAll(SLL **top){
    if(*top==NULL){

    }
    else{
     SLL *curr=*top;
     *top=NULL;
     SLL *next=curr;
     while (next!=NULL)
     {
         next=curr->next;
         printf("deleted:%d  ",curr->data);
         free(curr);
         if(next!=NULL){
         curr=next;
         }
     }
     
    }
}

int main(){
    printf("!!!!!!!!!!<<<<<<<<WELCOME TO MY STACK>>>>>>>>!!!!!!!!!!");
   while (1)
   {
    printf("\n<<<<<<<<<<<-----------MENU---------->>>>>>>>>>>>>\n");
    printf("1=PUSH ELEMENT\n2=POP ELEMENT\n3=PEEK ELEMENT\n4=DISPLAY THE ELEMENTS OF STACK\n5=REVRSE THE DATA\n6=CLOSE THE PROGRAM\nENTER THE SERIAL NO TO DO OPERATION ON STACK=");
    int num;
    scanf("%d",&num);
    switch (num)
    {
    case 1:
        printf("ENTER THE NUMBER THAT YOU WANT TO PUSH INTO THE STACK=");
        int data;
        scanf("%d",&data);
        push(&top1,data);
        break;
    case 2:
    if(top1!=NULL)
        printf("THE DELETED DATA= %d",pop(&top1));
        else
        pop(&top1);
        break;
    case 3:
    if(top1!=NULL)
        printf("THE PEEK ELEMENT OF THE STACK= %d",peek(&top1));
    else
        peek(&top1);
        break;
    case 4:
        display(&top1);
        break;
    case 5:
        reverse(&top1,&top2);
        display(&top2);
        deleteAll(&top2);
        break;
    case 6:
          exit(0);
    default:
        printf("\n!!!!!!!!!!YOU HAVE ENTERED WRONG NUMBER!!!!!!!!!!!!\n");
        printf("PLEASE WRITE THE RIGHT NUMBER\n");
        break;
    }
 
}
}


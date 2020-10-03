#include<stdio.h>
#include <stdlib.h>

typedef struct stack_using_linked_list SLL;
struct stack_using_linked_list
{
    int data;
    SLL *next;
}*top=NULL;

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
        push(&top,data);
        break;
    case 2:
    if(top!=NULL)
        printf("THE DELETED DATA= %d",pop(&top));
        else
        pop(&top);
        break;
    case 3:
    if(top!=NULL)
        printf("THE PEEK ELEMENT OF THE STACK= %d",peek(&top));
    else
        peek(&top);
        break;
    case 4:
        display(&top);
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


#include <stdio.h>
#include <stdlib.h>

typedef struct stack_using_linked_list SLL;
struct stack_using_linked_list
{
    int data;
    SLL *next;
} *top = NULL;

void push(SLL **top, int data)
{
    SLL *new_node = (SLL *)malloc(sizeof(SLL));
    if (new_node == NULL)
    {
        printf("!!!!!!!!STACK OVERFLOW!!!!!!!!!!\n");
    }
    else
    {
        new_node->next = NULL;
        new_node->data = data;
        if (*top == NULL)
        {
            *top = new_node;
        }
        else
        {
            new_node->next = *top;
            *top = new_node;
        }
    }
}

int pop(SLL **top)
{
    if (*top == NULL)
    {
        printf("!!!!!!!!STACK UNDERFLOW!!!!!!!!!!\n");
    }
    else
    {
        SLL *temp = *top;
        int data = temp->data;
        (*top) = (*top)->next;
        free(temp);
        return data;
    }
}

int main()
{
    printf("!!!!!!!!!!!PLEASE NOTE THAT ENTER THE NUMBER BY SEPARATING SPACE!!!!!!!!!!!\n");
    printf("ENTER THE POSTFIX EXPRESSION =");
    char a[100];
    gets(a);
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] >= 48 && a[i] <= 57)
        {
            int data = (int)a[i] - 48;
        start:
            if (a[i + 1] >= 48 && a[i + 1] <= 57)
            {
                data = data * 10 + ((int)a[i + 1] - 48);
                i++;
                goto start;
            }
            push(&top, data);
            i++;
        }
        else if (a[i] == ' ')
        {
            i++;
            continue;
        }
        else
        {
            int data1 = pop(&top);
            int data2 = pop(&top);
            switch (a[i])
            {
            case '+':
                push(&top, data1 + data2);
                break;
            case '-':
                push(&top, data2 - data1);
                break;
            case '*':
                push(&top, data1 * data2);
                break;
            case '/':
                push(&top, data2 / data1);
                break;
            case '%':
                push(&top, data2 % data1);
                break;
            default:
                printf("invalid Symbol");
            }
            i++;
        }
    }
    printf("RESULT=%d", pop(&top));
}
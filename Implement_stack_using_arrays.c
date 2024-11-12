#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define STACK_SIZE 5
int top = -1;
int s[10];
int item;
void push(){
    if(top==STACK_SIZE-1){
        printf("Stack in full");
    return;
    }
    top = top+1;
    s[top] = item;
    }
int pop(){
    if(top==-1){
        printf("Stack underflow");
        return -1;
    }
    top = top-1;
    return s[top+1];
    }
void display(){
    int i;
    if(top==-1){
        printf("Stack is empty");
    return;
    }
    printf("Contents of the stack \n");
    for(i=0;i<=top;i++){
        printf("%d\n",s[i]);
    }
    }
void main(){
    int item_deleted;
    int choice;
    while(true)
        {
        printf("\n 1:push\n 2:pop\n 3:display\n 4:exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice){
    case 1:
        printf("Enter number to be inserted: ");
        scanf("%d",&item);
        push();
        break;
    case 2:
        item_deleted = pop();
        if(item_deleted==-1)
        printf("stack is empty\n");
        else
        printf("item deleted is %d\n",item_deleted);
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Choice entered not in options ");
        break;
        }
    }
    }

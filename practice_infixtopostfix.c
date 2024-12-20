#include<stdio.h>
#include <ctype.h>


char stack[20];
int top = -1;


void push(char x){
    stack[++top] = x;
}

char pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }
}

int priority(char x){
    if(x=='('){
        return 0;
       }
    else if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='/'|| x=='*'){
        return 2;
    }
}
void main(){
    char *e,x;
    char exp[20];
    printf("Enter your infix expression: \n");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e=='('){
            push(*e);
        }
        else if(*e == ')'){
            while((x=pop())!='('){
                    printf("%c",x);
            }
        }
        else {
            while(priority(stack[top])>=priority(*e)){
                printf("%c",pop());
            }
            push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}

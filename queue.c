#include<stdio.h>
#define MAX_TERMS 5
int front=0, rear = 0;

void enqueue(int s[] , int* front , int* rear , int value){
    if((*front)  == 0 && (*rear) == 0){
        s[(*rear)++] = value;

        return;
    }
    else if(*rear == MAX_TERMS){
        printf("Queue overload .");
        return;
    }
    else{
        s[(*rear)++] = value;
        return;
    }
}

int dequeue(int s[] , int*front , int* rear){
    if(*front == *rear){
        printf("Queue empty. ");
        return -1;
    }
    else{
        return s[(*front)++];
    }
}

void display(int s[] , int front , int rear){
    for(int i = front;i<rear;i++){
        printf("%d\n",s[i]);
    }
}
void main(){
    int queue1[MAX_TERMS];
    enqueue(queue1 ,&front ,&rear , 1 );
    enqueue(queue1 ,&front ,&rear , 2 );
    enqueue(queue1 ,&front ,&rear , 3 );
    enqueue(queue1 ,&front ,&rear , 4 );
    enqueue(queue1 ,&front ,&rear , 5 );
    display(queue1,front,rear);
    int x = dequeue(queue1,&front,&rear);
    printf("Element removed: %d \n",x);
    int y = dequeue(queue1,&front,&rear);
    printf("Element removed: %d \n",y);
    int z = dequeue(queue1,&front,&rear);
    printf("Element removed: %d \n",z);
    int p = dequeue(queue1,&front,&rear);
    printf("Element removed: %d \n",p);
    int q = dequeue(queue1,&front,&rear);
    printf("Element removed: %d \n",q);
    int r = dequeue(queue1,&front,&rear);
    printf("Element removed: %d \n",r);
    display(queue1,front,rear);
}

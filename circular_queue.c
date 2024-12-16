#include<stdio.h>
#define MAX_TERMS 5

int front = -1;
int rear = -1;
int q[MAX_TERMS];

void insert() {
    int x;
    printf("Enter the element to insert: ");
    scanf("%d", &x);


    if ((front == 0 && rear == MAX_TERMS - 1) || (rear + 1 == front)) {
        printf("List overflow.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }

    else if (rear == MAX_TERMS - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    q[rear] = x;
}

void delete1() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    int a = q[front];

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX_TERMS - 1) {
        front = 0;
    }
    else {
        front++;
    }
    printf("Deleted element is %d\n", a);
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
    } else {
        for (int i = front; i < MAX_TERMS; i++) {
            printf("%d ", q[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", q[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete1();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define STACK_SIZE 5


void push(int item, int s[], int *top);
int pop(int s[], int *top);
void display(int top, int s[]);

void main() {
    int item, s[STACK_SIZE];
    int item_deleted;
    int choice;
    int top = -1;

    while (true) {
        printf("\n 1: push\n 2: pop\n 3: display\n 4: exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                push(item, s, &top);
                break;
            case 2:
                item_deleted = pop(s, &top);
                if (item_deleted != 0)
                    printf("Item deleted is %d\n", item_deleted);
                break;
            case 3:
                display(top, s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void push(int item, int s[], int *top) {
    if (*top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    s[*top] = item;
}

int pop(int s[], int *top) {
    int item_deleted;
    if (*top == -1) {
        printf("Stack underflow, cannot delete\n");
        return 0;
    }
    item_deleted = s[*top];
    *top = *top - 1;
    return item_deleted;
}

void display(int top, int s[]) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Contents of the stack:\n");
    for (i = 0; i <= top; i++) {
        printf("%d\n", s[i]);
    }
}

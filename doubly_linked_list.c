#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct node *insertAtBeginning(struct node *head, int value) {
    struct node *newNode = createNode(value);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

void insert_left(struct node** head, int value, int data) {
    struct node* newnode = createNode(data);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node* temp = *head;


    if (temp->data == value) {
        newnode->next = temp;
        temp->prev = newnode;
        *head = newnode;
        return;
    }


    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        free(newnode);
        return;
    }

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newnode;
    }
    temp->prev = newnode;
}

void deleteNodeByValue(struct node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;


    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }


    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;


    insert_left(&head, 6, 5);
    insert_left(&head, 5, 4);
    insert_left(&head, 4, 3);
    insert_left(&head, 3, 2);

    display(head);


    display(head);

    deleteNodeByValue(&head, 5);
    display(head);

    return 0;
}

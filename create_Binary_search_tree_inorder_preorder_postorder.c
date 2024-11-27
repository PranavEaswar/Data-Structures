#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right= NULL;
    return temp;
}

struct node* insertnode(struct node* root , int value){
    if(root==NULL){
        return createnode(value);
    }
    else if(value>root->data){
        root->right = insertnode(root->right,value);
    }
    else{
        root->left = insertnode(root->left,value);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
        if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

    }
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void main(){
    struct node* root = NULL;
    root=insertnode(root,50);
    insertnode(root,30);
    insertnode(root,20);
    insertnode(root,80);
    insertnode(root,70);
    insertnode(root,40);
    insertnode(root,90);
    printf("preorder\n");
    preorder(root);
    printf("\n");
    printf("postorder\n");
    postorder(root);
    printf("\n");
    printf("inorder\n");
    inorder(root);
}

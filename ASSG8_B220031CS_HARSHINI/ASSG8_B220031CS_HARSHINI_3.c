#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
    struct node* parent;
};

typedef struct node node;

node* createnode(int k){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->key=k;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;
}

node* insert(node* root, int key){
    if (root == NULL) {
        return createnode(key);
    }
    else if (key<root->key) {
        root->left = insert(root->left , key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

node* min(node* node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}

void transplant(node* head, node* u, node* v){
    if (u->parent==NULL){
        head=v;
    }
    else if (u==u->parent->left){
        u->parent->left=v;
    }
    else 
        u->parent->right=v;
    if (v!=NULL){
        v->parent=u->parent;
    }
    return;
}

node* search(node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}


node* delete(node* root,node* z){
    if (z->left==NULL)  
        transplant(root,z,z->right);
    else if (z->right==NULL) 
        transplant (root,z,z->left);
    else{
        node* y= min(z->right);
        if (y->parent!=z){
            transplant(root,y,y->right);
            y->right=z->right;
            y->right->parent=y;
        }
        transplant(root,z,y);
        y->left=z->left;
        y->left->parent=y;
    }
}

void paranthesis(node* root){
    if (root==NULL){
        printf("()");
        return;
    }
    printf("( %d ",root->key);
    paranthesis(root->left);
    printf(" ");
    paranthesis(root->right);
    printf(" )");
}

int main(){
    struct node* root = NULL;
    char option;
    int key;

    while (1) {
        scanf(" %c", &option);

        if (option == 'i') {
            scanf(" %d", &key);
            root = insert(root, key);
        } 
        else if (option == 'd') {
            scanf(" %d", &key);
            struct node* z = search(root, key);
            if (z) {
                root = delete(root, z);
                free(z);
            }
        }
        else if (option == 'p') {
            paranthesis(root);
            printf("\n");
        } 
        else if (option == 'e') {
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
};

typedef struct node node;

node* createnode(int k){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=k;
    newnode->parent=NULL;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insertnode(node** head, int k, node* parent){
    struct node* p=NULL;
    struct node* x= *head;
    struct node* z= createnode(k);
    while (x!=NULL){
        p=x;
        if (z->data<x->data){
            x=x->left;
        }
        else x=x->right;
    }
    z->parent=p;
    if (p==NULL){
        *head=z;
    }
    else {
        if (z->data<=p->data){
            p->left=z;
        }
        else p->right=z;
    }
}

node* max(node* head){
    if (head==NULL){
        return head;
    }
    while (head->right!=NULL){
        head=head->right;
    }
    return head;
}

node* min(node* head){
    if (head==NULL){
        return head;
    }
    while (head->left!=NULL){
        head=head->left;
    }
    return head;
}

node* successors(node* x){
    if (x!=NULL)
        return min(x->right);
    struct node* y=x->parent;
    while (y!=NULL && x==y->right){
        x=y;
        y=y->parent;
    }
    printf("%d\n",y->data);
    return y;
}

struct node* search(node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}


node* predecessors(node* x){
    if (x!=NULL)
        return min(x->left);
    struct node* y=x->parent;
    while (y!=NULL && x==y->left){
        x=y;
        y=y->parent;
    }
    printf("%d\n",y->data);
    return y; 
}

void preorder(struct node *root){
    if (root==NULL){
        return;
    }
    printf(" %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void transplant(node* head,node* u, node* v){
    if (u->parent==NULL){
        head=v;
    }
    else if (u==u->parent->left)
        u->parent->left=v;
    else
        u->parent->right=v;
    if (v!=NULL){
        v->parent=u->parent;
    }
}

node* delete(node* head,node* z){
    if (z->left==NULL) 
        transplant(head,z,z->right);
    else if (z->right==NULL)
        transplant(head,z,z->left);
    else{
        node* y=min(z->right);
        if (y->parent!=z)
        {
            transplant(head,y,y->right);
            y->right=z->right;
            y->right->parent=y;
        }
        transplant(head,z,y);
        y->left=z->left;
        y->left->parent=y;    
    }
    return head;
}

int main() {
    struct node* root = NULL;
    char option;
    int k;
    while (1) {
        scanf(" %c", &option);
        if (option == 'a') {
            scanf(" %d", &k);
            insertnode(&root, k, NULL);
        } else if (option == 'd') {
            scanf(" %d", &k);
            struct node* z = search(root, k);
            if (z) {
                root = delete(root, z);
                free(z);
            }
        } else if (option == 'c') {
            scanf(" %d", &k);
            struct node* successor = successors(root);
            if (successor)
                printf("%d\n", successor->data);
            else
                printf("-1\n");
        } else if (option == 'r') {
            scanf(" %d", &k);
            struct node* predecessor = predecessors(root);
            if (predecessor)
                printf("%d\n", predecessor->data);
            else
                printf("-1\n");
        } else if (option == 'p') {
            if (root) {
                preorder(root);
                printf("\n");
            } else {
                printf("-1\n");
            }
        } else if (option == 'e') {
            break;
        }
    }
}

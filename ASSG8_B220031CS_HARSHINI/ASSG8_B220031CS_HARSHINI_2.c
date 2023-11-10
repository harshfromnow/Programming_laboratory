#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

typedef struct node node;

node* createnode(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insertnode(node** head, int k,node* parent)
{
    if (*head == NULL)
    {
        *head = createnode(k);
        (*head)->parent = parent; 
    }
    else if (k > (*head)->data)
    {
        insertnode(&((*head)->left), k, *head); 
    }
    else if (k <= (*head)->data)
    {
        insertnode(&((*head)->right), k, *head); 
    }
}

void preorder(node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(node* node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void max(node* head)
{   
    if(head==NULL)
    {
        return;
    }
    while (head->left != NULL)
    {
        head = head->left;
    }
    printf("%d\n", head->data);
}

int min(node* head)
{   
    if(head==NULL)
    {
        return;
    }
    while (head->right != NULL)
    {
        head = head->right;
    }
    return head->data;
}

node* succesor(node* node)
{
    if (node == NULL)
        return NULL;
    if (node->right)
    {
        return min(node->right);
    }

    struct node* successor = NULL;
    struct node* current = node->parent;

    while (current != NULL && node == current->right)
    {
        node = current;
        current = current->parent;
    }

    return current;
}

node* findpredecessor(node* node){
    if (node == NULL)
        return NULL;
    if (node->left!=NULL)
        return min(node->left);
    struct node* y=node->parent;
    while (y!=NULL && node==y->left){
        node=y;
        y=y->parent;
    }
 printf("%d\n",y->data);
 return y;
}

node* search(node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

void Preorderprint(struct node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    Preorderprint(node->left);
    Preorderprint(node->right);
}

int main()
{
    struct node* root = NULL;

    char option;
    int k;

    do {
        scanf(" %c", &option);
        if (option == 'a')
        {
            scanf(" %d", &k);
            insertnode(&root, k, NULL);
        }   
        else if (option == 'c')
        {
            scanf(" %d", &k);
            struct node* successor = findSuccessor(root);
            if (successor)
                printf("%d\n", successor->data);
            else
                printf("-1\n");
        }
        else if (option == 'r')
        {
            scanf(" %d", &k);
            struct node* predecessor = findpredecessor(root);
            if (predecessor)
                printf("%d\n", predecessor->data);
            else
                printf("-1\n");
        }
        else if (option == 'p')
        {
            if (root)
            {
                Preorderprint(root);
                printf("\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (option == 'e')
        {
            break;
        }
    } while (1);

    return 1;
}
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

void min(node* head)
{   
    if(head==NULL)
    {
        return;
    }
    while (head->right != NULL)
    {
        head = head->right;
    }
    printf("%d\n", head->data);
}

void inorder(node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
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

node* search(node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main()
{
    node* root = NULL;
    char option;
    while (1)
    {
        scanf(" %c", &option);

        if (option == 'a')
        {
            int x;
            scanf(" %d", &x);
            insertnode(&root, x, NULL);
        }
        else if (option == 's')
        {   
            if(root!=NULL)
            {
                int k;
                scanf(" %d", &k);
                node* result = search(root, k);
                if (result != NULL) 
                {
                    printf("F\n");
                } 
                else {
                    printf("N\n");
                }
            }
        }
        else if (option == 'x')
        {
            max(root);
        }
        else if (option == 'n')
        {
            min(root);
        }
        else if (option == 'i')
        {
            if (root) 
            {
                inorder(root);
                printf("\n");
            }
        }
        else if (option == 'p')
        {
            if (root) 
            {
                preorder(root);
                printf("\n"); 
            }
        }
        else if (option == 't')
        {
            if (root) 
            {
                postorder(root);
                printf("\n"); 
            }
        }
        else if (option == 'e')
        {
            break;
        }
    } 
    return 1;
}
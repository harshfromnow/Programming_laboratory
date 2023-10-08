#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node* next;
};

typedef struct node node;

node* create_node(int k) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = k;
    newnode->next = NULL;
    return newnode;
}

void list_insert_front(node** L, node* x) {
    x->next = *L;
    *L = x;
}

void list_insert_tail(node** L, node* x) {
    if (*L == NULL) {
        *L = x;
    } else {
        node* temp = *L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = x;
    }
}

void list_insert_after(node** L, node* x, node* y) {
    if (y == NULL) {
        return;
    }
    x->next = y->next;
    y->next = x;
}

void list_insert_before(node** L, node* x, node* y) {
    if (*L == NULL || y == NULL) {
        return;
    }
    if (*L == y) {
        x->next = *L;
        *L = x;
        return;
    }
    node* current = *L;
    while (current != NULL && current->next != y) {
        current = current->next;
    }
    if (current != NULL) {
        x->next = current->next;
        current->next = x;
    }
}

int list_delete(node **L, node *x) {
    if ((*L) == NULL || x == NULL) {
        return -1;
    }

    if ((*L) == x) {
        int deleted = x->key;
        (*L) = x->next;
        free(x);
        return deleted;
    }

    node *temp = (*L);

    while (temp->next != NULL && temp->next != x) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return -1; 
    }

    int deleted = x->key;
    temp->next = x->next;
    free(x);
    return deleted;
}

int list_delete_first(node** L) {
    if (*L == NULL) {
        return -1; 
    } else {
        node* temp = *L;
        int deleted = temp->key;
        *L = (*L)->next;
        free(temp);
        return deleted;
    }
}

int list_delete_last(node** L) {
    if (*L == NULL) {
        return -1; 
    } else if ((*L)->next == NULL) {
        int deleted = (*L)->key;
        free(*L);
        *L = NULL;
        return deleted;
    } else {
        node* temp = *L;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        int deleted = temp->next->key;
        node* lastNode = temp->next;
        temp->next = NULL;
        free(lastNode);
        return deleted;
    }
}

int list_search(node* L, int k) {
    node* current = L;
    while (current != NULL) {
        if (current->key == k) {
            return 1;
        }
        current = current->next;
    }
    return -1;
}

void list_reverse(node** L) {
    node* next = NULL;
    node* current = *L;
    node* prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *L = prev; 
}


void list_display(node* L) {
    node* temp = L;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
}

void list_reverse_even(node** L)
{
    node* evenhead = NULL;
    node* eventail = NULL;
    node* current = *L;
    int i = 1;

    while (current != NULL)
    {
        if (i % 2 == 0)
        {
            node* newNode = create_node(current->key);
            if (evenhead == NULL)
            {
                evenhead = newNode;
                eventail = newNode;
            }
            else
            {
                newNode->next = evenhead;
                evenhead = newNode;
            }
        }
        current = current->next;
        i++;
    }
    current = *L;
    i = 1;
    node* even_current = evenhead;
    while (current != NULL && even_current != NULL)
    {
        if (i% 2 == 0)
        {
            current->key = even_current->key;
            even_current = even_current->next;
        }
        current = current->next;
        i++;
    }
    while (evenhead != NULL)
    {
        node* temp = evenhead;
        evenhead = evenhead->next;
        free(temp);
    }
}


int main() {
    node* L = NULL;
    char option[3];
    int key1, key2, result;

    while (1) {
        if (scanf("%2s", option) != 1) {
            break;  
        }
        if (strcmp(option, "f") == 0) {
            scanf("%d", &key1);
            list_insert_front(&L, create_node(key1));
        } 
        else if (strcmp(option, "t") == 0) {
            scanf("%d", &key1);
            list_insert_tail(&L, create_node(key1));
        } 
        else if (strcmp(option, "a") == 0) {
            scanf("%d %d", &key1, &key2);
            node* node1 = create_node(key1);
            node* node2 = L;
            while (node2 != NULL && node2->key != key2) {
                node2 = node2->next;
            }
            if (node2 != NULL) {
                list_insert_after(&L, node1, node2);
            }
        } 
        else if (strcmp(option, "b") == 0) {
            scanf("%d %d", &key1, &key2);
            node* node3 = create_node(key1);
            node* node4 = L;
            while (node4 != NULL && node4->key != key2) {
                node4 = node4->next;
            }
            if (node4 != NULL) {
                list_insert_before(&L, node3, node4);
            }
        } 
        else if (strcmp(option, "d") == 0) {
            scanf("%d", &key1);
            node *deletenode = L;
            while (deletenode != NULL && deletenode->key != key1) {
                deletenode = deletenode->next;
            }
            if (deletenode != NULL) {
                result = list_delete(&L, deletenode);  
                printf("%d\n", result);
            } 
            else {
                printf("-1\n");
            }
        }
        else if (strcmp(option, "i") == 0) {
            result = list_delete_first(&L);
            if (result != -1) {
                printf("%d\n", result);
            } else {
                printf("-1\n");
            }
        } 
        else if (strcmp(option, "l") == 0) {
            result = list_delete_last(&L);
            if (result != -1) {
                printf("%d\n", result);
            } else {
                printf("-1\n");
            }
        } 
        else if (strcmp(option, "s") == 0) {
            scanf("%d", &key1);
            result = list_search(L, key1);
            if (result != -1) {
                printf("1\n");
            } else {
                printf("-1\n");
            }
        } 
        else if (strcmp(option, "r") == 0) {
            list_reverse(&L);
            list_display(L);
            printf("\n");
        } 
        else if (strcmp(option, "ds") == 0) {
            list_display(L);
            printf("\n");
        } 
        else if (strcmp(option, "re") == 0) {
            list_reverse_even(&L);
            list_display(L);
            printf("\n");
        } 
        else if (strcmp(option, "e") == 0) {
            break;
        }
    }
    return 1;
}

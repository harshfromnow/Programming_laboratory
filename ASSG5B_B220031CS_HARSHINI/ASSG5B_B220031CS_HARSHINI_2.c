#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

node* create_node(int k) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = k;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void list_insert_front(node** L, node* x) {
    x->next = *L;
    if (*L != NULL) {
        (*L)->prev = x;
    }
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
        x->prev = temp;
    }
}

void list_insert_after(node** L, node* x, node* y) {
    if (y == NULL) {
        return;
    }
    x->prev = y;
    x->next = y->next;
    if (y->next != NULL) {
        y->next->prev = x;
    }
    y->next = x;
    if (x->next == NULL) {
        *L = x; 
    }
}

void list_insert_before(node** L, node* x, node* y) {
    if (y == NULL) {
        return;
    }
    x->prev = y->prev;
    x->next = y;
    if (y->prev != NULL) {
        y->prev->next = x;
    } else {
        *L = x; 
    }
    y->prev = x;
}


int list_delete(node **L, node *x) {
    if ((*L) == NULL || x == NULL) {
        return -1;
    }

    if ((*L) == x) {
        int deleted = x->key;
        (*L) = x->next;
        if ((*L) != NULL) {
            (*L)->prev = NULL;
        }
        free(x);
        return deleted;
    }

    node *temp = (*L);

    while (temp != NULL) {
        if (temp == x) {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            int deleted = temp->key;
            free(temp);
            return deleted;
        } else {
            temp = temp->next;
        }
    }

    return -1;  
}


int list_delete_initial(node** L) {
    if (*L == NULL) {
        return -1;
    } else {
        node* temp = *L;
        int deleted = temp->key;
        *L = (*L)->next;
        if (*L != NULL) {
            (*L)->prev = NULL;
        }
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

int list_search(node** L, int k) {
    node* current = *L;
    while (current != NULL) {
        if (current->key == k) {
            return 1;
        }
        current = current->next;
    }
    return -1;
}

void list_display(node* L) {
    node* temp = L;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
}

node* list_reverse_negative(node* L) {
    if (L == NULL || L->next == NULL) {
        return L;
    }
    node* prev = NULL;
    node* current = L;
    node* nextnode;
    int foundnegative = 0;
    while (current != NULL) {
        nextnode = current->next;
        if (current->key < 0) {
            current->next = prev;
            prev = current;
            foundnegative = 1;
        } else {
            if (foundnegative) {
                node* temp = prev;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = current;
                foundnegative = 0; 
            }
        }
        current = nextnode;
    }
    return prev; 
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
                result = list_delete(&L, deletenode);  // Pass the node pointer
                printf("%d\n", result);
            } 
            else {
                printf("-1\n");
            }
        }
        else if (strcmp(option, "i") == 0) {
            result = list_delete_initial(&L);
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
            result = list_search(&L, key1);
            if (result != -1) {
                printf("1\n");
            } else {
                printf("-1\n");
            }
        } 
        else if (strcmp(option, "ds") == 0) {
            list_display(L);
            printf("\n");
        } 
        else if (strcmp(option, "rn") == 0) {
            L=list_reverse_negative(L);
            list_display(L);
            printf("\n");
        } 
        else if (strcmp(option, "e") == 0) {
            break;
        }
    }
    return 1;
}

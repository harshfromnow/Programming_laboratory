#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 100

struct stack {
    char* arr[max]; 
    int top;
};

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

void push(struct stack* s, char* op) {
    if (s->top < max - 1) {
        s->top = s->top + 1;
        s->arr[s->top] = strdup(op); 
    }
}

char* pop(struct stack* s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    return NULL;
}

void display(struct stack* s) {
    for (int i = 0; i <= (s->top); i++) {
        printf("%s", s->arr[i]);
    }
}

void initializestack(struct stack* s) {
    s->top = -1;
}

void Infix(char postfix[]) {
    struct stack stack;
    initializestack(&stack);
    int i = 0;
    for (i = 0; postfix[i] != '\0'; ++i) {
        if (postfix[i] == ' ' || postfix[i] == '\t') {
            continue;
        } 
        else if (postfix[i] >= '0' && postfix[i] <= '9') {
            char temp[2] = {postfix[i], '\0'}; 
            push(&stack, temp);
        } 
        else if (isOperator(postfix[i])) {
            if (stack.top >= 1) {
                char* op1 = pop(&stack);
                char* op2 = pop(&stack);
                char str[max];
                if (postfix[i+1] != '\0' && postfix[i+2] != '\0') {
                    snprintf(str, sizeof(str), "(%s%c%s)", op2, postfix[i], op1);
                } 
                else {
                    snprintf(str, sizeof(str), "%s%c%s", op2, postfix[i], op1);
                }
                push(&stack, str);
            }
        }
    }
    
    display(&stack);
}


int main() {
    char postfix[max];
    fgets(postfix, max, stdin);
    Infix(postfix);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

struct stack {
    int arr[max];
    int top;
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void push(struct stack* s, int value) {
    if (s->top < max - 1) {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack* s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    return -1; 
}

void initializestack(struct stack* s) {
    s->top = -1;
}

int evaluateExpression(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            }
            return -1; 
        default:
            return -1; 
    }
}

int PostfixEvaluation(char postfix[]) {
    struct stack stack;
    initializestack(&stack);
    int i = 0;
    char token[20]; 

    while (sscanf(&postfix[i], "%s", token) != EOF) {
        i += strlen(token) + 1; 

        if (strlen(token) > 0) {
            if (token[0] >= '0' && token[0] <= '9') {
                int value = atoi(token);
                push(&stack, value);
            } 
            else if (isOperator(token[0])) {
                int result;
                if (stack.top >= 1) {
                    int operand2 = pop(&stack);
                    int operand1 = pop(&stack);
                    result = evaluateExpression(operand1, operand2, token[0]);
                    }
                    push(&stack, result);
                } 
                else {
                    return -1; 
                }
            } 
            else {
                return -1; 
            }
        }

    if (stack.top == 0) {
        return pop(&stack); 
    }
    return -1; 
}

int main() {
    char postfix[max];
    fgets(postfix, max, stdin);
    int result = PostfixEvaluation(postfix);
    printf("%d\n", result);
    return 0;
}

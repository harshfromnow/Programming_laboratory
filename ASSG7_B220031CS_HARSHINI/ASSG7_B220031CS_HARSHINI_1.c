#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100

struct stack{
    char arr[max];
    int top;
};

int isOperator(char c){
    if (c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else return 0;
}

int Precedence(char c){
    if (c=='+' || c=='-')
        return 1;
    else if (c=='*' || c=='/')
        return 2;
    return 0;
}

void initializestack(struct stack* s){
    s->top=-1;
}

void push(struct stack* s,char op){
    if (s->top<max-1){
        s->top=s->top+1;
        s->arr[s->top]=op;
    }
    return;
}

char pop(struct stack* s){
    if (s->top>=0){
        char data=s->arr[s->top];
        s->top=s->top-1;
        return data;
    }
    return '\0';
}

void InfixPostfix(char infix[],char postfix[]){
    struct stack stack;
    initializestack(&stack);
    int i,j=0;
    for (i=0;infix[i]!='\0';i++){
        if (infix[i]==' ' || infix[i]=='\t'){
            continue;
        }

        else if (isalpha(infix[i])){
            postfix[j++]=infix[i];
        }
        else if (isOperator(infix[i])){
            while (stack.top>=0 && stack.arr[stack.top]!='(' && Precedence(stack.arr[stack.top]) >= Precedence(infix[i])){
                postfix[j++]=pop(&stack);
            }
            push(&stack,infix[i]);
        }
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        else if (infix[i]==')'){
            while (stack.top>=0 && stack.arr[stack.top]!='('){
                postfix[j++]=pop(&stack);
            }
            if (stack.top >= 0 && stack.arr[stack.top] == '(') {
                pop(&stack);
            }
        }
    }
    while (stack.top >= 0) {
        postfix[j] = pop(&stack);
        j = j + 1;
    }
    postfix[j] = '\0';
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char infix[max];
    char postfix[max];
    fgets(infix,max,stdin);
    InfixPostfix(infix, postfix);
    int size = sizeof(postfix) / sizeof(postfix[0]);
    for(int i=0;i<size;i++){
        printf("%c ",postfix[i]);
    }
    return 1;
}
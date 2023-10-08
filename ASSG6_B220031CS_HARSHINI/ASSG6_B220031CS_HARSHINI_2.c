#include <stdio.h>
#define max 1000

struct Stack{
    int arr[max];
    int top;
};

int STACK_EMPTY(struct Stack *s){
    if (s->top==-1){
        return -1;
    }
    else
        return 1;
}

int STACK_FULL(struct Stack *s,int n){
    if (s->top==n-1){
        return -1;}
    else
        return 1;
}

void PUSH(struct Stack *s,int c,int n){
    if (STACK_FULL(s,n)==-1){
        printf("-1\n");
    }
    else{
        s->top=s->top+1;
        s->arr[s->top]=c;
    }
    return;
}

void POP(struct Stack *s){
    if (STACK_EMPTY(s) == -1) {
        return;  
    }
    else{
        char temp=s->arr[s->top];
        s->top=s->top-1;
        return;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int nextgreater[n];
    struct Stack stack;
    stack.top=-1;

    for (int i=0;i<n;i++){
        nextgreater[i]=-1;
    }
    for (int i = 0; i < n; i++) {
        while (STACK_EMPTY(&stack)==1 && arr[i] > arr[stack.arr[stack.top]]) {
            nextgreater[stack.arr[stack.top]] = arr[i];
            POP(&stack);
        }
        PUSH(&stack,i,n);
    }

    for (int i = 0; i < n-1; i++) {
        printf("%d ", nextgreater[i]);
    }
    printf("%d",nextgreater[n-1]);
    return 1;
}

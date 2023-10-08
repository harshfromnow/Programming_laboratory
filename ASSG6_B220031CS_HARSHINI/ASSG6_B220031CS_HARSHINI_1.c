#include <stdio.h>
#define max 100000
struct Stack{
    char A[max];
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
void PUSH(struct Stack *s,char c,int n){
    if (STACK_FULL(s,n)==-1){
        printf("-1\n");
    }
    else{
        s->top=s->top+1;
        s->A[s->top]=c;
    }
    return;
}

void POP(struct Stack *s){
    if (STACK_EMPTY(s) == -1) {
        printf("-1\n");
        return;  
    }
    else{
        char temp=s->A[s->top];
        s->A[s->top]='\0';
        printf("%c\n",temp);
        s->top=s->top-1;
        return;
    }
}

void PEEK(struct Stack *s){
    if (STACK_EMPTY(s)==-1){
        printf("-1\n"); 
        return;
    }
    else{
         printf("%c\n",s->A[s->top]);
         return;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char choice;
    struct Stack stack;
    stack.top=-1;

    while (1) {
        scanf(" %c", &choice);

        if (choice == 'i') {
            char ch;
            scanf(" %c", &ch); 
            PUSH(&stack,ch,n);
        } 
        else if (choice == 'd') {
            POP(&stack);
        } 
        else if (choice == 'p') {
            PEEK(&stack);
        } 
        else if (choice == 't') {
            return 0;
        } 
        else {
            continue;
        }
    }
    return 1;
}

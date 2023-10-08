#include <stdio.h>
#include <string.h>
#define max 100000
#define stringlen 20

struct Queue{
    char A[max][stringlen];
    int head;
    int tail;
};

int QUEUEEMPTY(struct Queue *q){
    if (q->head == -1){
        return -1;
    }
    else{
        return 1;
    }
}

int QUEUEFULL(struct Queue *q, int n){
    if ((q->tail + 1)%n==q->head){
        return -1;
    }
    else {
        return 1;}
}

void ENQUEUE(struct Queue *q, char str[],int n){
    if (QUEUEFULL(q,n)==-1){
        printf("-1\n");
        return;
    }
    if (QUEUEEMPTY(q)==-1){
        q->head=0;
    }
    q->tail=(q->tail+1)%n;
    strcpy(q->A[q->tail],str);
    return;
}

void DEQUEUE(struct Queue *q,int n){
    if (QUEUEEMPTY(q)==-1){
        printf("-1\n");
        return;
    }
    printf("%s\n",q->A[q->head]);
    if (q->head==q->tail){
        q->head=-1;
        q->tail=-1;
    }
    else{
        q->head=(q->head+1)%n;
    }
    return;
}


int main(){
    struct Queue q;
    q.head=-1;
    q.tail=-1;

    int n;
    scanf("%d", &n);

    char choice;
    while (1){
        scanf(" %c",&choice);
        switch(choice){
            case 'i':
                char str[stringlen];
                char* str_ptr = str;
                scanf("%s",str_ptr);
                ENQUEUE(&q,str,n);
                break;
            case 'd':
                DEQUEUE(&q,n);
                break;
            case 'f':
                printf("%d\n", QUEUEFULL(&q, n));
                break;
            case 'e':
                printf("%d\n", QUEUEEMPTY(&q));
                break;
            case 't':
                return 0;
            default:
                continue;
        }
    }
    return 1;
}

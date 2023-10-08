#include <stdio.h>
#include <stdlib.h>
#define max 1000

struct Queue {
    int queue[max];
    int head;
    int tail;
};

int queueEmpty(struct Queue* q) {
    return (q->head == -1 && q->tail==-1);
}

int queueFull(struct Queue* q) {
    return ((q->tail+1)% max ==q->head);
}

void enqueue(struct Queue* q, int x) {
    if (queueFull(q)) {
        return;
    }
    if (queueEmpty(q)) {
        q->head = 0;
        q->tail = 0;
    } 
    else {
        q->tail = (q->tail + 1) % max;
    }
    q->queue[q->tail] = x;
}

void dequeue(struct Queue* q) {
    if (queueEmpty(q)) {
        return;
    }
    if (q->head == q->tail) {
        q->head = -1;
        q->tail = -1;
    } 
    else {
        q->head = (q->head + 1) % max;
    }
}

int size(struct Queue* queue) {
    if (queueEmpty(queue)) {
        return 0;
    }
    return (queue->tail - queue->head + 1 + max) % max;
}

int front(struct Queue* q) {
    if (queueEmpty(q)) {
        return -1;
    }
    return q->queue[q->head];
}

void reverseFirstK(struct Queue* q, int k) {
    if (k <= 1 || k > size(q)) {
        return;
    }

    int* temp = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        temp[i] = front(q);
        dequeue(q);
    }

    for (int i = k - 1; i >= 0; i--) {
        enqueue(q, temp[i]);
    }

    for (int i = 0; i < size(q)-k; i++) {
        enqueue(q,front(q));
        dequeue(q);
    }
    free(temp);
    return;
}


int main() {
    int n, k;
    struct Queue q;
    q.head=-1;
    q.tail=-1;
    scanf("%d %d",&n,&k);

    for (int i = 0; i <n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    reverseFirstK(&q, k);

    for (int i = 0; i < n; i++){
        printf("%d ", front(&q));
        dequeue(&q);
    }
    return 1;
}


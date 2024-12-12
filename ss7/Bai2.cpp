#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Hang doi day!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->data[++(q->rear)] = value;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1; // Indicate that the queue is empty
    } else {
        return q->data[q->front++];
    }
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initializeQueue(&q);
    
    // Thêm một số phần tử vào hàng đợi
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    // In hàng đợi ban đầu
    printf("Trang thai hang doi ban dau: ");
    printQueue(&q);

    // Thực hiện dequeue
    int dequeuedValue = dequeue(&q);
    if (dequeuedValue != -1) {
        printf("Phan tu da duoc lay khoi hang doi: %d\n", dequeuedValue);
    }

    // In trạng thái hàng đợi sau khi dequeue
    printf("Trang thai hang doi sau khi dequeue: ");
    printQueue(&q);

    return 0;
}

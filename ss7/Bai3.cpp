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

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Hang doi day!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->data[++(q->rear)] = value;
    }
    printf("Hang doi %s\n", isEmpty(q) ? "rong" : "khong rong");
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1; // Indicate that the queue is empty
    } else {
        int value = q->data[q->front++];
        printf("Hang doi %s\n", isEmpty(q) ? "rong" : "khong rong");
        return value;
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
    
    int choice, value;
    do {
        printf("Menu:\n");
        printf("1. Them vao hang doi\n");
        printf("2. In hang doi\n");
        printf("3. Lay phan tu khoi hang doi\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Nhap gia tri de them vao hang doi: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                printQueue(&q);
                break;
            case 3:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Phan tu da duoc lay khoi hang doi: %d\n", value);
                }
                break;
            case 4:
                printf("Dang thoat...\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 4);

    return 0;
}

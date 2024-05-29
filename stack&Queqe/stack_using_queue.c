#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);
void push(Queue *q1, Queue *q2, int value);
int pop(Queue *q1, Queue *q2);

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);
    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(&q1, &q2, value);
                break;
            case 2:
                value = pop(&q1, &q2);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                printf("Stack contents:\n");
                display(&q1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Add an element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

// Remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int removed = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return removed;
}

// Display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Push element onto the stack
void push(Queue *q1, Queue *q2, int value) {
    while (!isEmpty(q1)) {
        enqueue(q2, dequeue(q1));
    }
    enqueue(q1, value);
    while (!isEmpty(q2)) {
        enqueue(q1, dequeue(q2));
    }
}

// Pop element from the stack
int pop(Queue *q1, Queue *q2) {
    if (isEmpty(q1)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return dequeue(q1);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool isEmptyQueue(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int x) {
    if (q->size == MAX_SIZE) {
        printf("Queue overflow!\n");
        return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}

int frontQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue empty!\n");
        return -1;
    }
    return q->data[q->front];
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&stack->q1);
    initQueue(&stack->q2);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);

    // Move all elements from q1 to q2
    while (!isEmptyQueue(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    // Swap q1 and q2
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    return frontQueue(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate();
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("Top: %d\n", myStackTop(stack)); // 2
    printf("Pop: %d\n", myStackPop(stack)); // 2
    printf("Empty: %d\n", myStackEmpty(stack)); // 0 (false)
    myStackFree(stack);
    return 0;
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
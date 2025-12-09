#include <stdio.h>
#define MAX 5    
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) front = 0;   
        queue[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to dequeue\n");
        return -1;
    } else {
        return queue[front++];
    }
}
int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return queue[front];
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
 
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Front element is: %d\n", peek());

    printf("Dequeued element: %d\n", dequeue());
    display();

    return 0;
}

#include <stdio.h>
#define MAX 5   
int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
 
int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Top element is: %d\n", peek());

    printf("Popped element: %d\n", pop());
    display();

    return 0;
}

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    if(front == 0 && rear == SIZE-1) return 1;
    if(front > rear) return 1;
    return 0;
}

// Check if queue is empty
int isEmpty() {
    return front == -1;
}

// Enqueue - add to rear (circular)
void enqueue(int data) {
    if(isFull()) {
        printf("Queue FULL!\n");
        return;
    }
    if(front == -1) front = 0;  // First element
    rear = (rear + 1) % SIZE;   // Circular rear
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}

// Dequeue - remove from front
int dequeue() {
    if(isEmpty()) {
        printf("Queue EMPTY!\n");
        return -1;
    }
    int data = queue[front];
    if(front == rear) {
        front = rear = -1;  // Last element
    } else {
        front = (front + 1) % SIZE;  // Circular front
    }
    printf("Dequeued: %d\n", data);
    return data;
}

// Peek - front element only
void peek() {
    if(isEmpty()) {
        printf("Queue EMPTY!\n");
        return;
    }
    printf("Front: %d\n", queue[front]);
}

// Display all elements
void display() {
    if(isEmpty()) {
        printf("Queue EMPTY!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while(1) {
        printf("\n1=Enqueue 2=Dequeue 3=Peek 4=Display 0=Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
        }
        else if(choice == 2) dequeue();
        else if(choice == 3) peek();
        else if(choice == 4) display();
        else if(choice == 0) break;
        else printf("Invalid!\n");
    }
    return 0;
}

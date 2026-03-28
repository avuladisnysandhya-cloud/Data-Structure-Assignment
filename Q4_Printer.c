#include <stdio.h>
#define MAX 10

char queue[MAX][50];  // Store document names
int front = 0;        // front=0 (not -1)
int rear = -1;        // rear=-1 empty

void addDoc() {
    if(rear < MAX-1) {  // Check full
        printf("Enter document name: ");
        scanf("%s", queue[++rear]);
        printf("Added '%s' to queue!\n", queue[rear]);
    } else {
        printf("Queue FULL!\n");
    }
}

void printDoc() {
    if(front > rear) {  //empty check
        printf("Queue empty!\n");
        return;
    }
    printf("Printing: %s\n", queue[front]);
    front++;  // Move front
}

void display() {
    if(front > rear) {
        printf("No pending documents!\n");
        return;
    }
    printf("Pending: ");
    for(int i = front; i <= rear; i++) {
        printf("%s ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    
    while(1) {
        printf("\n1=Add  2=Print  3=Display  0=Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) addDoc();
        else if(choice == 2) printDoc();
        else if(choice == 3) display();
        else if(choice == 0) break;
    }
    return 0;
}
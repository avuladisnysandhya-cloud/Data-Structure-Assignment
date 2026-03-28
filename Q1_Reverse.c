#include <stdio.h>
#include <string.h>

#define MAX 100

// Global variables for the stack
char stack[MAX];
int top = -1;

// Function to push character onto stack
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop character from stack
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    // Step 1: Push all characters of the string into the stack
    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Step 2: Pop characters from the stack to reverse the string
    for (i = 0; i < length; i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
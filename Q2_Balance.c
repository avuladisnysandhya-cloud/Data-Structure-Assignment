#include <stdio.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

// Push '(' to stack
void push() {
    if(top < SIZE-1) {
        stack[++top] = '(';
    }
}

// Pop '(' from stack
char pop() {
    if(top >= 0) {
        return stack[top--];
    }
    return ' ';
}

int main() {
    char exp[SIZE];
    
    printf("Enter expression: ");
    scanf("%s", exp);
    
    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i] == '(') {
            push();  // Open bracket - push
        }
        else if(exp[i] == ')') {
            if(pop() == ' ') {  // Close bracket - pop & check
                printf("Unbalanced\n");
                return 0;
            }
        }
        i++;
    }
    
    if(top == -1) {
        printf("Balanced Expression\n");
    } else {
        printf("Unbalanced\n");
    }
    return 0;
    }
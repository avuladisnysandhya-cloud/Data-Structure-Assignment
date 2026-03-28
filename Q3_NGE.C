#include <stdio.h>
#define MAX 100

int stk[MAX];
int top = -1;

int main() {
    int arr[MAX];
    int n;
    
    // User input
    printf("Enter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nNext Greater Elements:\n");
    
    // Right to left processing
    for(int i = n-1; i >= 0; i--) {
        while(top >= 0 && stk[top] <= arr[i]) {
            top--;
        }
        
        int next = (top >= 0) ? stk[top] : -1;
        printf("%d -> %d\n", arr[i], next);
        
        stk[++top] = arr[i];
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int * arr;
    int size;
    int top;
};

// Function to create a stack of given size
struct Stack* createStack (int size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->arr = (int *) malloc(size * sizeof(int));
 
    return stack;
}

int isFull (struct Stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty (struct Stack* stack) {
    return stack->top == -1;
}

void push (struct Stack* stack, int data) {
    if ( isFull(stack) ) {
        printf("Stack Overflow");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop (struct Stack* stack) {
    if ( isEmpty(stack) ) {
        printf("Stack Underflow");
        return;
    }
    return stack->arr[stack->top--];    
}

int main(int argc, char const *argv[]) {

    struct Stack* stack = createStack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));

    return 0;
}
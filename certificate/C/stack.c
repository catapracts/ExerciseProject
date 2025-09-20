#include <stdio.h>

int stack[10];
int top = -1;

void push(int data){
    if(top >= sizeof(stack) / sizeof(int) - 1) {
        printf("full");
    }

    else {
        stack[++top] = data;
    }
}

int pop() {
    if(top == -1) {
        printf("empty");
    }

    else return stack[top--];
}

int isEmpty() {
    if(top == -1) {
        return 1;
    }

    else return 0;
}

int main() {
    push(20);
    push(30);
    push(40);
    while(!isEmpty()) {
        int e = pop();
        printf("value = %d\n", e);
    }
}
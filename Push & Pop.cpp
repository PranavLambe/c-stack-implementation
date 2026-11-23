#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return false;
    }
    s->data[++(s->top)] = value;
    return true;
}

bool pop(Stack *s, int *out) {
    if (isEmpty(s)) {
        printf("Stack underflow! Nothing to pop\n");
        return false;
    }
    *out = s->data[(s->top)--];
    return true;
}

bool peek(Stack *s, int *out) {
    if (isEmpty(s)) {
        return false;
    }
    *out = s->data[s->top];
    return true;
}

int main(void) {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    int topVal;
    if (peek(&s, &topVal)) {
        printf("Top element: %d\n", topVal);
    }

    int popped;
    while (pop(&s, &popped)) {
        printf("Popped: %d\n", popped);
    }

    return 0;
}
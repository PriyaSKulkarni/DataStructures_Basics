#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack *stack) {
    stack->top = -1;
}

bool stack_push(Stack *stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        return false; // Stack overflow
    }
    stack->data[++stack->top] = value;
    return true;
}

bool stack_pop(Stack *stack, int *value) {
    if (stack->top < 0) {
        return false; // Stack underflow
    }
    *value = stack->data[stack->top--];
    return true;
}

// Queue implementation
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void queue_init(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool queue_enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        return false; // Queue overflow
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
    return true;
}

bool queue_dequeue(Queue *queue, int *value) {
    if (queue->front == -1 || queue->front > queue->rear) {
        return false; // Queue underflow
    }
    *value = queue->data[queue->front++];
    return true;
}

// Singly linked list implementation
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node nodes[MAX_SIZE];
    int head;
} LinkedList;

void linkedlist_init(LinkedList *list) {
    list->head = -1;
}

bool linkedlist_insert(LinkedList *list, int value) {
    if (list->head == MAX_SIZE - 1) {
        return false; // List full
    }
    Node *newNode = &list->nodes[++list->head];
    newNode->data = value;
    newNode->next = NULL;
    return true;
}

bool linkedlist_remove(LinkedList *list, int value) {
    if (list->head == -1) {
        return false; // List empty
    }
    Node *current = &list->nodes[0];
    Node *prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head--;
            } else {
                prev->next = current->next;
            }
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false; // Value not found
}

int main() {
    // Example usage
    Stack stack;
    stack_init(&stack);
    stack_push(&stack, 1);
    stack_push(&stack, 2);
    int popped;
    stack_pop(&stack, &popped);
    printf("Popped from stack: %d\n", popped);

    Queue queue;
    queue_init(&queue);
    queue_enqueue(&queue, 1);
    queue_enqueue(&queue, 2);
    int dequeued;
    queue_dequeue(&queue, &dequeued);
    printf("Dequeued from queue: %d\n", dequeued);

    LinkedList list;
    linkedlist_init(&list);
    linkedlist_insert(&list, 1);
    linkedlist_insert(&list, 2);
    linkedlist_remove(&list, 1);
    printf("Size of linked list: %d\n", list.head + 1);

    return 0;
}

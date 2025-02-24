#include <stdio.h> 
#include <stdlib.h> 

#define MAX 5 

struct Stack{
    int top; 
    int arr[MAX];
}; 

void initStack(struct Stack *s){
    s->top =-1; 
}

int isEmpty(struct Stack *s) { 
return (s->top == -1); 
} 
int isFull(struct Stack *s){ 
return (s->top == MAX-1); 
}

void push(struct Stack *s, int value){
    if (isFull(s)) { 
    printf("Stack Overflow! Cannot push %d\n", value); 
    return;
    }


    s->arr[++s->top] = value; 
    printf("Pushed %d into stack\n", value); 
}

int pop(struct Stack *s) { 
    if (isEmpty(s)) { 
    printf("Stack Underflow! Cannot pop\n"); 
    return -1; 
    }
    return s->arr[s->top--]; 
} 


int peek(struct Stack *s) { 
    if (isEmpty(s)) { 
        printf("Stack is empty!\n"); 
        return -1; 
    } 
    return s->arr[s->top]; 
} 


void display(struct Stack *s) { 
    if (isEmpty(s)) { 1
        printf("Stack is empty!\n"); 
        return; 
    } 
    printf("Stack elements: "); 
    for (int i=s->top; i >= 0; i--){
        printf("%d",s->arr[i]);
    }
    printf("\n");
}

int main() { 
    struct Stack s; 
    initStack(&s); 
    int choice, value; 
    do { 
        printf("\nStack Operations Menu:\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Peek\n"); 
        printf("4. Display\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
        case 1: 
            printf("Enter value to push: "); 
            scanf("%d", &value); 
            push(&s, value); 
            break; 
        case 2: 
            value = pop(&s); 
            if (value != -1) 
            printf("Popped element: %d\n", value); 
            break;
        case 3: 
            value = peek(&s); 
            if (value != -1) 
            printf("Top element: %d\n", value); 
            break; 
        case 4: 
            display(&s); 
            break; 
        case 5: 
            printf("Exiting program...\n"); 
            break; 
        default: 
            printf("Invalid choice! Please try again.\n"); 
            
            
            
        }
    }while (choice != 5); 
    return 0; 
}
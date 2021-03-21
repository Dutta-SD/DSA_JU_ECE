/* Stack implementation with fixed memory array */
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define NULL_STACK -1
# define MAX_STACK_CAPACITY 100

/* Stack has a fixed memory capacity
a top pointer */
typedef struct stk{
    int capacity;
    int top;
    int* arr;
}Stack;

/* Init a stack */
Stack* initStack(const int capacity){
    Stack *stk = malloc(sizeof(Stack));

    stk -> top = NULL_STACK;
    stk -> capacity = capacity;
    stk -> arr = malloc(capacity * sizeof(int));

    if(stk == NULL || stk->arr == NULL){
        printf("\nNot enough memory! Aborting\n");
        return NULL;
    }

    return stk;
}

/* Checker method for empty or not */
int isEmpty(const Stack* stk){
    return (stk->top == NULL_STACK);
}

/* Checker to see if stack is full or not */
int isFull(const Stack* stk){
    return (stk->top == stk->capacity - 1);
}

/* Size of the stack */
int size(const Stack *stk){
    return stk->top + 1;
}

/* push data into stack */
void push(Stack *stk, int data){
    /* If full, OVERFLOW */
    if(isFull(stk)){
        printf("\nOVERFLOW\n");
        return;
    }
    printf("Added : %d\n", data);
    ++(stk -> top);
    stk -> arr[stk -> top] = data;
}

/* Pop data from stack */
int pop(Stack *stk){
    if(isEmpty(stk)){
        printf("\nUNDERFLOW\n");
        return INT_MIN;
    }
    return stk->arr[stk->top--];
}

/* print the stack */
void printStack(const Stack *stk){
    int lim = NULL_STACK;
    int i = stk -> top;

    if(isEmpty((stk))) return;
    while(i > lim){
        printf("%d ", stk->arr[i]);
        i--;
    }
    printf("\n");
}

void printMenu(){
    printf("\n============================\n");
    printf("[1] Push Element in Stack\n");
    printf("[2] Pop Element from Stack\n");
    printf("[3] Print the Stack\n");
    printf("============================\n");
}

int main(){
    int capacity = MAX_STACK_CAPACITY;
    Stack* stk = initStack(capacity);
    int element, choice;

    printMenu();

    do{
        printf("CHOICE >>> ");
        scanf("%d", &choice);

        switch(choice){
            default : 
                printf("\nEXITING\n");
                choice = -1;
                break;
            case 1 :
                printf("\nEnter the Element\n>>> ");
                scanf("%d", &element);
                push(stk, element);
                break;
            case 2 : 
                element = pop(stk);
                printf("\nElement Popped : %d\n", element);
                break;
            case 3:
                printStack(stk);
        }
    } while(choice != -1);
    return 0;   
}
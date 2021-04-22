/*Min priority queue with 2 stacks*/

/* Stack implementation with fixed memory array */
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define NULL_STACK -1
# define MAX_STACK_CAPACITY 3

#ifndef min
    #define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

// Pair - a data structure for holding 2 things
typedef struct pair{
    int first;
    int second;
}pair;

pair makePair(int f, int s){
    pair p;
    p.first = f;
    p.second = s;
    return p;       
}

/* Stack has a fixed memory capacity
a top pointer */
typedef struct stk{
    int capacity;
    int top;
    pair* arr;
}Stack;

/* Init a stack */
Stack* initStack(const int capacity){
    Stack *stk = malloc(sizeof(Stack));

    stk -> top = NULL_STACK;
    stk -> capacity = capacity;
    stk -> arr = malloc(capacity * sizeof(pair));

    if(stk == NULL || stk->arr == NULL){
        printf("\nNot enough memory! Aborting\n");
        return NULL;
    }

    return stk;
}
/*peeks at first element*/
pair peek(const Stack* s1){
    return s1->arr[s1->top];
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
Stack* push(Stack *stk, pair p, int output){
    /* If full, OVERFLOW */
    if(isFull(stk)){
        printf("\nOVERFLOW\n");
        return stk;
    }
    if(output) printf("Added : %d\n", p.first);
    ++(stk -> top);
    stk -> arr[stk -> top] = p;
    return stk;
}

/* Pop data from stack */
pair pop(Stack *stk){
    if(isEmpty(stk)){
        printf("\nUNDERFLOW\n");
        return makePair(INT_MIN, INT_MIN);
    }
    return stk->arr[stk->top--];
}

/* print the stack */
void printStack(const Stack *stk){
    int lim = NULL_STACK;
    int i = stk -> top;

    if(isEmpty((stk))) return;
    while(i > lim){
        printf("%d ", stk->arr[i].first);
        i--;
    }
    printf("\n");
}
/*-------------------------------------------------*/
/*QUEUE FUNCTIONS*/
int getMin(const Stack* s1, const Stack* s2){
    int minimum;
    if (isEmpty(s1) || isEmpty(s2)) 
        minimum = isEmpty(s1) ? peek(s2).second : peek(s1).second;
    else
        minimum = min(peek(s1).second, peek(s2).second);

    return minimum;
}

void enqueue(Stack** s1, int new_element){
    int minimum = isEmpty(*s1) ? new_element : min(new_element, peek(*s1).second);
    *s1 = push(*s1, makePair(new_element, minimum), 1);
}

int dequeue(Stack** s1, Stack **s2){
    if (isEmpty(*s2)) {
        while (!isEmpty(*s1)) {
            int element = peek(*s1).first;
            pop(*s1);
            int minimum = isEmpty(*s1) ? element : min(element, peek(*s2).second);
            push(*s2, makePair(element, minimum), 0);
        }
    }
    int remove_element = peek(*s2).first;
    pop(*s2);
    return remove_element;
}
/*------------------------------------------------*/

void printMenu(){
    printf("\n==================================\n");
    printf("[1] Insert Element into Queue\n");
    printf("[2] Remove Element From Queue\n");
    printf("[3] Get Minimum Element of Queue\n");
    printf("====================================\n");
}

int main(){
    Stack* s1 = initStack(MAX_STACK_CAPACITY);
    Stack* s2 = initStack(MAX_STACK_CAPACITY);
    int element, choice;
    pair elem;

    printMenu();

    do{
        printf("CHOICE >>> ");
        scanf("%d", &choice);

        switch(choice){
            default : 
                printf("\nEXITING...\n");
                choice = -1;
                break;
            case 1 :
                printf("Enter the Element >>> ");
                scanf("%d", &element);
                enqueue(&s1, element);
                break;
            case 2 : 
                element = dequeue(&s1, &s2);
                printf("Element Dequeued : %d\n", element);
                break;
            case 3:
                printf("The Minimum Element is : %d\n", getMin(s1, s2));
                break;            
        }
    } while(choice != -1);
    return 0;   
}
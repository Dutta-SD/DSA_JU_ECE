/* ToWER of hanoi using user defined stack */
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
/* Macros for easy interpretation */
# define NULL_STACK -1
# define MAX_STACK_CAPACITY 1000

/* Stack has a fixed memory capacity and a top pointer */
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
    ++(stk -> top);
    stk -> arr[stk -> top] = data;
}

/* Pop data from stack */
int pop(Stack *stk){
    if(isEmpty(stk)){
        return INT_MIN;
    }
    return stk->arr[stk->top--];
}

/* print the stack */
void printStack(const Stack *stk){
    int lim = NULL_STACK;
    int i = stk -> top;
    printf("Stack Contents -> (top) ");

    if(isEmpty((stk))) {
        printf("\n");
        return;
    }
    
    while(i > lim){
        printf("%d -> ", stk->arr[i]);
        i--;
    }
    printf("\n");
}

/* Tower of Hanoi specific utilites */
void printMove(char from, char to, char diskno){
	printf("\n\tSTEP : Move the disk %d from %c to %c\n", diskno, from, to);
}

void moveDisks(Stack *src, Stack *dest, char s, char d){
    int pole1Top = pop(src);
    int pole2Top = pop(dest);

    if (pole1Top == INT_MIN){
		/* Empty */
        push(src, pole2Top);
        printMove(d, s, pole2Top);
    }
 
    else if (pole2Top == INT_MIN){
		/* Empty */
        push(dest, pole1Top);
        printMove(s, d, pole1Top);
    }
 
    else if (pole1Top > pole2Top){
		/* Put greater pole disk size */
        push(src, pole1Top);
        push(src, pole2Top);
        printMove(d, s, pole2Top);
    }
 
    else{
        push(dest, pole2Top);
        push(dest, pole1Top);
        printMove(s, d, pole1Top);
    }
}


/* Hanoi main function */
void towerOfHanoi(int num_of_disks, Stack *src, Stack *aux, Stack *dest){
    int i, total_num_of_moves;
    char s = 'A', d = 'B', a = 'C';
 
   /*  If number of disks is even, then interchange
    dest and aux*/
    if (num_of_disks % 2 == 0){
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;
 
    for (i = num_of_disks; i >= 1; i--)
        push(src, i);
 
    for (i = 1; i <= total_num_of_moves; i++){
        printf("SOURCE : ");
        printStack(src);
        printf("AUX : ");
        printStack(aux);
        printf("DEST : ");
        printStack(dest);
        if (i % 3 == 1)
        moveDisks(src, dest, s, d);
 
        else if (i % 3 == 2)
        moveDisks(src, aux, s, a);
 
        else if (i % 3 == 0)
        moveDisks(aux, dest, a, d);
    }
}
 
int main(){
    int num_of_disks;
 
    Stack *src, *dest, *aux;

	printf("Enter number of disks [Less than 10 as huge runtime] : ");
	scanf("%d", &num_of_disks);

    if(num_of_disks > 10 || num_of_disks < 1){
        perror("BAD INPUT. ABORT\n");
        exit(EXIT_FAILURE);
    }
 
    /* Create three stacks of size 'num_of_disks'
    to hold the disks */
    src = initStack(num_of_disks);
    aux = initStack(num_of_disks);
    dest = initStack(num_of_disks);
 
    towerOfHanoi(num_of_disks, src, aux, dest);
    return 0;
}
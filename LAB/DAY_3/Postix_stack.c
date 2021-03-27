
/* Stack implementation with fixed memory array */
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define NULL_STACK -1
# define MAX_STACK_CAPACITY 100
# define END_OF_EXPRESSION '$'

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
        return END_OF_EXPRESSION;
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

// Stack type
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}


// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	int i;

	// See if stack was created successfully
	if (!stack) return -1;

	// Scan all characters one by one
	for (i = 0; exp[i]; ++i)
	{
		// If the scanned character is an operand (number here),
		// push it to the stack.
		if (isdigit(exp[i]))
			push(stack, exp[i] - '0');

		// If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			}
		}
	}
	return pop(stack);
}

// Driver program to test above functions
int main()
{
	char exp[] = "231*+9-";
	printf ("postfix evaluation: %d", evaluatePostfix(exp));
	return 0;
}

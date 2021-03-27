
/* Stack implementation with fixed memory array */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

/* Macros for easy interpretation */
# define NULL_STACK -1
# define MAX_STACK_CAPACITY 100
# define END_OF_EXPRESSION '$'
# define MAX_EXPRESSION_LENGTH 100

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
    printf("Stack Contents : ");

    if(isEmpty((stk))) return;
    while(i > lim){
        printf("%d ", stk->arr[i]);
        i--;
    }
    printf("\n");
}


int evaluatePostfixExpresssion(char* expression){
	Stack* stack = initStack(strlen(expression));
	int i, value1, value2;

	if (!stack){
        printf("No memory could be allocated. Operation failed.\n");
        exit(EXIT_FAILURE);
    }

	for (i = 0; expression[i] != END_OF_EXPRESSION; ++i){

		if (isdigit(expression[i]))
			push(stack, expression[i] - '0');

		else {
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (expression[i]){
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2 / val1); break;
            case '^': push(stack, (int)pow(val2, val1)); break;
			}
		}
        printStack(stack);
	}
	return pop(stack);
}

int main(){
    char expression[MAX_EXPRESSION_LENGTH];
    int finalExpressionValue;
    printf("Enter an expression with last char $. [MAX LEN 100] : ");
    scanf("%s", expression);
    finalExpressionValue = evaluatePostfixExpresssion(expression);
    printf("\nValue of Expression is : %d ", finalExpressionValue);
    return 0;     
}
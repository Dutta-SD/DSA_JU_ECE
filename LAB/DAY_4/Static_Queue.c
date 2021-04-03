/* Queue Implementation with fixed memory */
# include <stdio.h>
# include <stdlib.h>

// Maxsize of the Static Queue
# define MAX_SIZE 10 
 
// Queue Structure Declaration
typedef struct Static_Queue{
    /* data */
    int front, rear;
    int* queue;
}Queue;


// init queue
void initQueue(){
    _q.front = -1;
    _q.rear = -1;
    _q.queue = malloc(MAX_SIZE * sizeof(int));
    if(_q.queue == NULL){
        printf("NO MEMORY ALLOCATED!!\nEXITING!!");
        exit(EXIT_FAILURE);
    }
}

// Queue - declare and init
Queue _q;

// Functions to Handle the Queue

// enqueue : Inputs the value to Queue
void enqueue();
// dequeue : Removes value from queue, returns it
void dequeue();
// Displays the Queue
void displayQueue();
// displays menu
void displayMenu();
 
int main(){
    initQueue();
	int choice;
	clrscr();
	do{
		clrscr();
        displayMenu();		
		scanf("%d", &choice);
 
		switch(choice){
			case 1:
				enqueue();
				displayQueue();
				break;
			case 2:
				 dequeue();
				 displayQueue();
				 break;
			case 3:
				displayQueue();
				break;
			case 4:
				printf("\nEND OF PROGRAM\n");
		}
	} while(choice != 4);

    return 0;
}
 
void enqueue(){
	int no;
	printf("\n Enter Number to be inserted to Queue > ");
	scanf("%d",&no);
 
	if(_q.rear < MAX_SIZE-1){
		_q.queue[++(_q.rear)] = no;
		if(_q.front==-1)
		_q.front = 0;
	}else{
		printf("\nQueue overflow...");
	}
}
 
void dequeue(){
	if(_q.front == -1){
		printf("\nQueue Underflow...");
		return;
	}else{
		printf("\nDeleted Item --> %d",_q.queue[_q.front]);
	}
	if(_q.front == _q.rear){
		_q.front=-1;
		_q.rear=-1;
	}else{
        _q.front++;
	}
}
 
void displayQueue(){
	int i;
	if(_q.front == -1){
		printf("\nQueue is empty....\n");
		return;
	}
    printf("Queue : [front] -> ");
	for(i = _q.front; i <= _q.rear - 1; i++)
		printf("%d --> ",_q.queue[i]);
    printf("%d [rear]", _q.rear);
}

void displayMenu(){
    printf("Queue Menu\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n"); 
	printf("Enter Your Choice > ");
}
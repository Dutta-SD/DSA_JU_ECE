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

static Queue q_;

// init queue
void initQueue(){
    q_.front = -1;
    q_.rear = -1;
    q_.queue = (int*)malloc(MAX_SIZE * sizeof(int));
    if(q_.queue == NULL){
        printf("NO MEMORY ALLOCATED!!\nEXITING!!");
        exit(EXIT_FAILURE);
    }
}

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
	do{
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
	printf("Enter Number to be inserted to Queue > ");
	scanf("%d",&no);
 
	if(q_.rear < MAX_SIZE-1){
		q_.queue[++(q_.rear)] = no;
		if(q_.front==-1)
		q_.front = 0;
	}else{
		printf("\nQueue overflow...");
	}
}
 
void dequeue(){
	if(q_.front == -1){
		printf("\nQueue Underflow...");
		return;
	}else{
		printf("\nDeleted Item --> %d",q_.queue[q_.front]);
	}
	if(q_.front == q_.rear){
		q_.front=-1;
		q_.rear=-1;
	}else{
        q_.front++;
	}
}
 
void displayQueue(){
	int i;
	if(q_.front == -1){
		printf("\nQueue is empty....\n");
		return;
	}
    printf("Queue : [front] -> ");
	for(i = q_.front; i < q_.rear; i++)
		printf("%d --> ",q_.queue[i]);
    printf("%d [rear]\n", q_.rear);
}

void displayMenu(){
    printf("Queue Menu\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n"); 
	printf("Enter Your Choice > ");
}
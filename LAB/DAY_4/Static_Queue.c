/* Queue Implementation with fixed memory */
# include <stdio.h>
# include <stdlib.h>

// Maxsize of the Static Queue
# define MAX_SIZE 3
 
// Queue Declaration
int front = -1, rear = -1;
int queue[MAX_SIZE];

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
 
	if(rear < MAX_SIZE-1){
        ++(rear);
		queue[rear] = no;
		if(front == -1)
		front = 0;
	}else{
		printf("\nQueue overflow...\n");
	}
}
 
void dequeue(){
	if(front == -1){
		printf("\nQueue Underflow...\n");
		return;
	}else{
		printf("Deleted Item --> %d\n",queue[front]);
	}
	if(front == rear){
		front=-1;
		rear=-1;
	}else{
        front++;
	}
}
 
void displayQueue(){
	int i;
	if(front == -1){
		printf("\nQueue is empty....\n");
		return;
	}
    printf("Queue : [front] ");
	for(i = front; i < rear; i++)
		printf("%d --> ",queue[i]);
    printf("%d [rear]\n", queue[rear]);
}

void displayMenu(){
    printf("Queue Menu\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n"); 
	printf("Enter Your Choice > ");
}
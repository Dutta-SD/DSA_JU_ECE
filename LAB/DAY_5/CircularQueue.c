//Circular Queue Implementation - Sandip Dutta
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
 
// Data structure to represent a queue
struct queue{
    int *items;     // array to store queue elements
    int maxsize;    // maximum capacity of the queue
    // pointers
    int front;      
    int rear;       
    int size; // current q capacity
};
 
// initialize a queue
// We will be implementing using modulo
struct queue* newQueue(int size){
    struct queue *Node = NULL;
    Node = (struct queue*)malloc(sizeof(struct queue));

    //Initialization defaults
    Node->items = (int*)malloc(size * sizeof(int));
    Node->maxsize = size;
    Node->front = 0;
    Node->rear = -1;
    Node->size = 0;
 
    return Node;
}

void display(const struct queue* q){
    if(q->front == 0 && q->rear == -1){
        printf("UNDERFLOW ... \n");
    }
    printf("\nThe Queue is now : ");
    for(int i = q ->front; i <= q->rear; ++i){
        printf("%d --> ", q->items[i]);
    }
    printf("\n");
}
 
// current size of the queue
int size(const struct queue *Node) {
    return Node->size;
}
 
// queue is emptey or not
int isEmpty(struct queue *Node) {
    return !size(Node);
}
 
// front element of the queue
int front(struct queue *Node){
    if (isEmpty(Node)){
        printf("UNDERFLOW ... \n");
        return INT_MIN;
    } 
    return Node->items[Node->front];
}
 
// add an element `x` to the queue
void enqueue(struct queue *Node, int x){
    if (size(Node) == Node->maxsize){
        printf("OVERFLOW... \n");
        return;
    }
  
    Node->rear = (Node->rear + 1) % Node->maxsize;    // circular queue
    Node->items[Node->rear] = x;
    Node->size++;
 
    printf("ADDED %d", x); 
}
 
// dequeue the front element
int dequeue(struct queue *Node){
    if (isEmpty(Node)){
        printf("UNDERFLOW ... \n");
        return INT_MIN;
    }
 
    int data = front(Node);
 
    Node->front = (Node->front + 1) % Node->maxsize;  // circular queue
    Node->size--;

    return data;
}

void displayMenu(){
    printf("Queue Menu\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n"); 
	printf("Enter Your Choice > ");
}

int main(){

    struct queue *q = newQueue(3);
    int element;

	int choice;
	do{
        displayMenu();		
		scanf("%d", &choice); 
		switch(choice){
			case 1:
                printf("\nENTER A VALUE : ");
                scanf("%d", &element);
				enqueue(q, element);
				display(q);
				break;
			case 2:
				element = dequeue(q);
                printf("\nDELETED VALUE IS: %d", element);
				display(q);
				break;
			case 3:
				display(q);
				break;
			case 4:
				printf("\nEND OF PROGRAM\n");
		}
	} while(choice != 4);

    return 0;
}

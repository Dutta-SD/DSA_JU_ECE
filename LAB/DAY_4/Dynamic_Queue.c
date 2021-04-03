// Dynamic Queue - Sandip Dutta
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// Node for Dynamic Queue
struct Node{
	int data;
	struct Node *next;
}*front, *rear; 
 
// enqueue
void enqueue(int data){
    struct Node *newNode; 
    newNode = (struct Node*) malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL;

    if(rear == NULL || front == NULL) front = newNode;
    else rear -> next = newNode;

    rear = newNode;
}

// dequeue
int dequeue(){
    struct Node *temp;
    int number;

    if(front == NULL || rear == NULL){
        printf("\nUnder Flow..Returning Garbage Value");
        return INT_MIN;
    }else{
        temp = front;
        number = temp -> data;
        front = front->next;
        free(temp);
    }
    return number;
}

// display
void display(){
    struct Node *temp;
    temp = front;

    if(front == NULL||rear == NULL){
        printf("\nQueue is empty");
        return;
    }

    if(front == rear){
        printf("Queue [front] %d [rear]\n", front->data);
        return;
    }

    printf("Queue [front] ");

    while(temp -> next != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("%d [rear]\n", rear -> data);
} 

// main
int main(){ 
    int choice, number;
    rear = NULL;
    front = NULL;

    while(1){
        printf("\nQueue Menu");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice > ");

        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter The Element Value : \n");
                scanf("%d",&number);
                enqueue(number);
                printf("\nQueue after insertion : ");
                display();
                break;

            case 2:
                number = dequeue();
                printf("\nThe deleted element -> %d",number);
                printf("\nQueue after deletion");
                display();
                break;

            case 3:
                printf("\nQueue : ");
                display();
                break;

            case 4:
                printf("EXITING...");
                exit(0);
                break;

            default:
                printf("\n SELECT AGAIN!");
        } 
    } 
    return 0;
}
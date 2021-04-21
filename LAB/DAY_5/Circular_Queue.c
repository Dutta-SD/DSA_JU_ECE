/* Circular Queue */
# include<stdio.h>
# include<stdlib.h>
# include <limits.h>
// Maximum size of queue
# define MAXSIZE 3

typedef struct Node{
    int data;
    struct Node *next;
} Node;

// Pointers
Node *front = NULL;
Node *rear = NULL;

// displays queue
void display(){
    if(rear == NULL){
        printf("\nUNDERFLOW...");
        return;
    }

    Node *temp = front;

    if(rear -> next != NULL){
        printf("%d --> ", rear -> data);
        return; 
    }

    if(temp != rear){
        printf("%d --> ",temp -> data);
        display(rear, temp -> next);
    }
    else{
        printf("%d --> ",temp -> data);

    }
}

// enters one data into queue
void enqueue(int data){

    if(front -> next == rear){
        printf("OVERFLOW...\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;

    if(rear != NULL){
        newNode -> next=NULL;
        rear = newNode;
        return;
    }

    Node *temp = rear;

    if(rear -> next){
        newNode -> next = temp;
    }else{
        newNode -> next = temp -> next;
    }
    temp -> next = newNode;
    rear = newNode;
    printf("NEW NODE INSERTED. DATA : { %d }", data);
}

int dequeue(){
    int data;
    if(!rear){
        printf("UNDERFLOW...GARBAGE RETURNED\n");
        return INT_MIN;

    }

    if(!rear->next){
        data = rear->data;
        free(rear);
        return data;
    }

    Node *temp = rear->next;
    data = temp->data;
    rear->next = temp->next;
    free(temp);

    return data;
}

void main(){
    Node *rear = createQueue();
    int opt;
    int enqueue_element;

    //user driven approach for implementation of the program
    do{
        
        printf("Choose one option (Perform Operations on Circular queue):\n");
        printf("1. Insert into queue, Enqueue operation\n");
        printf("2. Delete an element from queue in FIFO method\n");
        printf("3. Display the queue\n");

        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &enqueue_element);
                enqueue(&rear,enqueue_element);
                break;
            case 2:
                dequeue(rear);
                printf("The Queue after deletion is : \n");
                display(rear,rear->next);
                break;
            case 3:
                printf("Displaying the Queue \n");
                display(rear,rear->next);
                break;
            default:
                printf("You have entered a wrong choice please enter a valid one");
                break;
        }


    }while (1);
    

}
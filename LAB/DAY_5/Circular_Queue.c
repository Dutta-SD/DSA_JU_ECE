#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

int data;

struct Node *next;

}Node;

Node *createQueue(){
    Node *rear=NULL,*front=NULL;
    printf("How many items you want to create in queue?");
    int n,data;
    scanf("%d",&n);
    int i = 0;
    while(i<n){
        if(i==0){
        printf("Enter the data: ");
        scanf("%d",&data);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next=NULL;
        rear = newNode;
        front = rear;

    }
    else
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next=front;
        rear->next=newNode;
        rear = newNode;

    }
    ++i;

    }

    return rear;

}

void display(Node *rear, Node *front){
    if(!rear){

        printf("\nNOTHING TO DISPLAY\n");
        return;
    }

    Node *temp = front;

    if(!rear->next)
    {
        printf("%d\n",rear->data);
        return ; 
    }

    if(temp!=rear)
    {
        printf("%d ",temp->data);
        display(rear, temp->next);
    }
    else{
        printf("%d\n",temp->data);

    }
}

void enqueue(Node **rear,int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if(!(*rear)){
    newNode->next=NULL;
    *rear = newNode;
    return;
    }
    Node *temp = *rear;
    if(!(*rear)->next){
        newNode->next = temp;
    }
    else{
        newNode->next = temp->next;
    }
    temp->next = newNode;
    *rear = newNode;
    printf("a new Node with data %d enqueued successfully\n",data);

}

int dequeue(Node *rear){
    int data;
    if(!rear){
        printf("\nNO ITEMS IN THE QUEUE\n");
        return 0;

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
    printf("Delete item is: %d\n",data);
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
#include<stdio.h>
#include<stdlib.h>

/* Here we have implemented Circular Doubly Linked List
using only a single pointer head. Some implementations use
a tail pointer for speeding up some routines. 
We have tried all variations in this assignment */

/* Doubly linked list node */
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

/* Global Head Node */
struct Node* head = NULL;

/* For printing list */
void printList(){
    struct Node* curr = head;
    if(head!=NULL && head -> next != NULL && head -> prev != NULL) {
        do{
            printf("%d ", curr->data);
            curr = curr->next;
        }while(curr != head);
    }
    printf("\n");
}

/* Returns the length of the linked list */
int getLength(){
    struct Node* curr = head;
    int count=0;
    if(head!=NULL&& head -> next != NULL && head -> prev != NULL){
        do{
            count++;
            curr = curr->next;
        }while(curr!=head);
    }
    return count;
}

/* For Deleting a node from the list */
void deleteAtPosition(int position){
    int length = getLength();
    int j;
    struct Node *temp = head, *temp2 = NULL;

    if(length == 0 || position > length){
        printf("INVALID POSITION\n");
        return;
    }    

	if(position == 1){
        /* Delete head. Get the pointer pointing 
        to head and swap */
        temp = temp -> prev;
        temp -> next = head -> next;
        head->next->prev = temp;

        free(head);        
        head = temp->next;
        return;
    }

    /* Middle or end deletion */
    for(j = 0;j < length - 2;++j) temp = temp -> next;

    temp2 = temp->next;
    temp -> next = temp2 -> next;
    temp2 -> next -> prev = temp;
    free(temp2);
}

/* Insertion at beginning of node.
Since the insert function becomes very large
We have broken it up into 3 parts */
void insertAtBeginning(int data){
    struct Node *newNode, *prevNode;

    /* Allocate a new Node */
    newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode -> data = data;
    newNode -> next = newNode;
    newNode -> prev = newNode;

    /* No node */
    if(head == NULL){
        head = newNode;
        newNode -> next = head;
        return;
    }

    prevNode = head -> prev;
    newNode->next = head;
    prevNode->next = newNode;
    head = newNode;    
}

/* End insertion */
void insertAtEnd(int data){   
    struct Node *newNode, *prevNode;

    /* Allocate a new Node */
    newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode -> data = data;
    newNode -> next = newNode;
    newNode -> prev = newNode;

    if(head == NULL){
        head = newNode;
        newNode -> next = head;
        return;      
    }

    prevNode = head -> prev;  
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next->prev = newNode;
    return;
}

/* Insert at any general position */
void insertAtPosition(int position, int data){    
    int length = getLength();
	struct Node *newNode, *prevNode;
    int j;

	if(position >= length + 2){
		printf("\nINVALID POSITION\n");
		return;
	}

	if(position == 1){
        insertAtBeginning(data);
        return;
    } 
    else if(position == length){
        insertAtEnd(data);
        return;
    }

    /* Allocate a new Node */
    newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode -> data = data;
    newNode -> next = newNode;
    newNode -> prev = newNode;

    for(j = 0;j < length - 2; j++) prevNode = prevNode->next;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    return;
}

/*Show menu*/
void show_menu(){
    printf("\nSelect from the options\n");
    printf("[1] print the list\n");
    printf("[2] get length of list\n");
    printf("[3] insert at position\n");
    printf("[4] delete at position\n");
    printf("Press anything else to exit\n");
    printf(">>> ");
}

/* Driver Function */
int main(){
    int choice, position, data;

    do{
        show_menu();
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nThe List is: ");
                printList(head);
                break;
            case 2:
                printf("\nThe length of the List is: %d", getLength(head));
                break;
            case 3:
                printf("\nEnter Position to insert and data ");
                scanf("%d %d", &position, &data);
                insertAtPosition(position, data);
                printf("\nInserted!");
                break;
            case 4:
                printf("\nEnter Position to delete ");
                scanf("%d", &position);
                deleteAtPosition(position);
                printf("\nDeleted!");
                break;
            default:
                exit(0);
                break;        
        }
    }while(1);
    return 0;
}
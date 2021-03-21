#include <stdio.h>
#include <stdlib.h>

/*
NOTE:
1. In this implementation, we use 2 pointers.
One for the head and one for the tail.
This can be used to implement a circular queue
2. We declare head and tail, two pointers globally to try 
out this variation
*/

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} node;

node* head = NULL, *tail = NULL;

void insertAtBeginning(int data)
{
    /*Insert data at the beginning of the list*/
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

/*Insert a node at tail of a circular singly linked list*/
void insertAtEnd(int data)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

/* Insert a node at position of a circular singly linked list */
void insertAtPosition(int data, int position)
{
    if (position == 1)
    {
        insertAtBeginning(data);
        return;
    }
    else if (position > 1 && head != NULL)
    {
        node *current = head;
        node *temp = (node *)malloc(sizeof(node));
        int count = 0;

        do
        {
            count++;
            temp = current;
            current = current->next;
        } while (current->next != head && count < position - 1);

        if (count == position - 1)
        {
            if (temp == tail)
                insertAtEnd(data);
            else
            {
                node *newNode = (node *)malloc(sizeof(node));
                newNode->data = data;

                temp->next = newNode;
                newNode->next = current;
            }
            return;
        }
    }
}

/* Delete HEAD node of a circular SLL */
void deleteAtBeginning()
{
    if (head == NULL)
        return;

    node *temp = head;

    tail->next = head->next;
    head = head->next;

    free(temp);
}

/* Delete TAIL node of a circular SLL */
void deleteAtEnd()
{
    if (head == NULL)
        return;

    node *temp = head;
    node *current = head;

    while (current->next != head)
    {
        temp = current;
        current = current->next;
    } 

    temp->next = head; 
    tail = temp;
    free(current);
}

/* Delete a node at position in the circular singly linked list */
void deleteAtPosition(int position)
{
    if (head == NULL)
        return;

    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }

    node *current = head;
    node *temp;
    int count = 0;

    do
    {
        count++;
        temp = current;
        current = current->next;
    } while (current->next != head && count < position - 1);

    if (count == position - 1)
    {
        if (current == tail)
        {
            deleteAtEnd();
            return;
        }

        temp->next = current->next;
        free(current);
        return;
    } 
}

/* Print all node's data of a circular singly linked list */
void printList()
{
    if (head == NULL)
        return;

    node *current = head;

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

}

/* Determine the data of nodes in circular singly linked list */
int listLength()
{
    if (head == NULL)
        return 0;

    int count = 0;
    node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
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
                printList();
                break;
            case 2:
                printf("\nThe length of the List is: %d", listLength());
                break;
            case 3:
                printf("\nEnter Position to insert and data ");
                scanf("%d %d", &position, &data);
                insertAtPosition(data, position);
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
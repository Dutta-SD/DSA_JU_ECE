# include <stdio.h>
# include <stdlib.h>

struct DLLNode{
    int data;
    struct DLLNode *next, *prev;
};

/* Insert at a position in th DLL.
Double pointer as send reference to the list */
void insert(struct DLLNode **head, int data, int position){
    int count = 1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));

    if(!newNode){
        printf("MEMORY ERROR!\n");
    }

    /* init node */
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(position == 1){
        /* Value of head */
        newNode->next = *head;
        if(*head) (*head) -> prev = newNode;
        *head = newNode;
        return;
    }

    temp = *head;

    while(count < position && temp->next != NULL) {
        temp = temp -> next;
        count++;
    }

    if(count < position - 1){
        printf("INVALID!");
        return;
    }

    newNode ->next = temp->next;
    newNode -> prev = temp;
    if (temp ->next) temp ->next ->prev = newNode;
    temp ->next = newNode;
}

/* Delete at given position of the doubly connected linked list */

void delete(struct DLLNode **head, int position){
    struct DLLNode *temp2, *temp = *head;

    int count = 1;
    if(*head==NULL){
        printf("EMPTY LIST!\n");
        return;
    }

    if(position == 1){
        *head = (*head) -> next;
        if(*head!=NULL)
            (*head) -> prev = NULL;
        free(temp);
        return;
        
    }    

    while(count < position && temp->next != NULL) {
        temp = temp -> next;
        count++;
    }

    if(count < position - 1){
        printf("INVALID!");
        return;
    }

    temp2 = temp -> prev;
    temp2 -> next = temp ->next;
    if(temp -> next) temp->next->prev = temp2;
    free(temp);
}

/*Length of Linked List*/
int get_length(struct DLLNode *head){
    struct DLLNode *curr = head;
    int length = 1;

    if (head == NULL) return 0;
    while(curr = curr -> next) ++length;
    return length;
}

/* Print the list */
void printList(struct DLLNode *head){
    if(head == NULL) return;
    struct DLLNode *curr = head;
    
    while(curr) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
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
    struct DLLNode *head = NULL;
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
                printf("\nThe length of the List is: %d", get_length(head));
                break;
            case 3:
                printf("\nEnter Position to insert and data ");
                scanf("%d %d", &position, &data);
                insert(&head, data, position);
                printf("\nInserted!");
                break;
            case 4:
                printf("\nEnter Position to delete ");
                scanf("%d", &position);
                delete(&head, position);
                printf("\nDeleted!");
                break;
            default:
                exit(0);
                break;        
        }
    }while(1);
    return 0;
}
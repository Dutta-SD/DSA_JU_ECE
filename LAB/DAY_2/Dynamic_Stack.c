# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

/* Dynamic Stack Implementation using Linked List */
/* Node*/
struct SLLNode{
    int data;
    struct SLLNode *next;    
};

/*Length of Linked List*/
int get_length(struct SLLNode *head){
    struct SLLNode *curr = head;
    int length = 1;

    if (head == NULL) return 0;
    while(curr = curr -> next) ++length;
    return length;
}

/* Print the list */
void printList(struct SLLNode *head){
    if(head == NULL) return;
    struct SLLNode *curr = head;
    
    while(curr) {
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

/* Insert in SLL*/
struct SLLNode* push(int data, struct SLLNode* head){
    struct SLLNode *newNode;

    newNode = (struct SLLNode*) malloc(sizeof(struct SLLNode));
    newNode -> data = data;
    if(!newNode) return NULL;
    newNode -> next = head;
    return newNode;
}

/* Pop from SLL */
struct SLLNode* pop(struct SLLNode *head, int *element){
    /* element is used for returning popped value */
    struct SLLNode *p;
    if(head == NULL) {
        printf("UNDERFLOW! VALUE returned is Garbage!\n");
        return head;
    }
    p = head;
    head = head -> next;
    *element = p -> data;
    free(p);
    return head;
}

/*Show menu*/
void show_menu(){
    printf("============================\n");
    printf("[1] Print the Stack\n");
    printf("[2] Push\n");
    printf("[3] Pop\n");
    printf("============================\n");
}

/* Driver Function */
int main(){
    struct SLLNode *head = NULL;
    int choice, data, element;

    show_menu();

    do{
        printf("CHOICE >>> ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nThe Stack is: ");
                printList(head);
                break;
            case 2:
                printf("Enter Data : ");
                scanf("%d", &data);
                head = push(data, head);
                break;
            case 3:
                head = pop(head, &element);
                printf("Popped Element is %d\n", element);
                break;
            default:
                choice = -1;
                break;        
        }
    }while(choice != -1);
    return 0;
}
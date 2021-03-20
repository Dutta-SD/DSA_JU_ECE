# include <stdio.h>
# include <stdlib.h>

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
struct SLLNode* insert_at(int position, int data, struct SLLNode* head){
    int count = 1;
    struct SLLNode *p, *q, *newNode;

    newNode = (struct SLLNode*) malloc(sizeof(struct SLLNode));

    if(!newNode) return NULL;

    newNode -> data = data;

    p = head;

    if(position == 1){
        /*Insert at begin*/
        newNode -> next = p;
        return newNode;
    } else {
        while((p != NULL) && (count < position)) {
            ++count;
            q = p;
            p = p -> next;
        }
        q -> next = newNode;
        newNode -> next = p;
    }
    return head;
}

/* Delete */
struct SLLNode* delete_from(struct SLLNode *head, int position){
    int count = 1;
    struct SLLNode *p, *q;

    if(head == NULL) return head;

    p = head;

    if(position == 1){
        p = head;
        head = head -> next;
        free(p);
    } else {
        while ((p != NULL) && (count < position)){
            count++;
            q = p;
            p = p -> next;
        }

        if (p != NULL) {
            q -> next = p -> next;
            free(p);
        }
    }
    return head;
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
    struct SLLNode *head = NULL;
    int choice, position, data;

    while(1){
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
                head = insert_at(position, data, head);
                printf("\nInserted!");
                break;
            case 4:
                printf("\nEnter Position to delete ");
                scanf("%d", &position);
                head = delete_from(head, position);
                printf("\nDeleted!");
                break;
            default:
                return 0;            
        }
    }
    return 0;
}
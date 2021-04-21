#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Item structure for storing the data and its priority
struct Item
{
    int data;
    int priority;
};

// Creating self referential structure to create the priority queue
struct Node
{
    struct Item item;
    struct Node *next;
    struct Node *prev;
};

// The primitive insert function
void insert(struct Node **front, struct Node **rear, struct Item val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->item = val;

    // Checking if first element is being inserted
    if (*rear == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        *front = temp;
        *rear = temp;
    }

    // Inserting element other than first
    else
    {
        temp->next = NULL;
        temp->prev = *rear;
        (*rear)->next = temp;
        *rear = temp;
    }
}

// Function to check if queue is empty
int isEmpty(struct Node *front, struct Node *rear)
{
    if (front == NULL || rear == NULL)
        return 1;
    return 0;
}

// Function to delete the minimum priority element in a queue, returns the deleted element
int minPriorityDelete(struct Node **front, struct Node **rear)
{

    struct Node *ptr = *front, *temp;
    int max = INT_MIN;

    // Traverses the dynamic priority queue to find and store the minimum priority element
    while (ptr != NULL)
    {
        if ((ptr->item).priority > max)
        {
            max = (ptr->item).priority;
            temp = ptr;
        }
        ptr = ptr->next;
    }
    int x = (temp->item).data;

    // Deleting the minimum priority element
    if (temp == *front)
        *front = temp->next;
    if (temp->prev != NULL)
        (temp->prev)->next = temp->next;
    if (temp->next != NULL)
        (temp->next)->prev = temp->prev;
    free(temp);
    if (*front == NULL)
        *front = *rear = NULL;
    return x;
}

// Function to display contents of queue
void display(struct Node *front, struct Node *rear)
{
    struct Node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", (ptr->item).data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct Node *front, *rear;
    front = rear = NULL;
    int opt;
    char repeat = 13;
    int pos, val, priority;

    // User interface menu created using do-while loop and switch case
    do
    {
        printf("Choose one option (Perform Operations on Minimum Priority queue):\n");
        printf("1. Insert into queue\n");
        printf("2. Delete minimum priority element from queue\n");
        printf("3. Display the queue\n");

        scanf("%d", &opt);
        switch (opt)
        {
        case 1:

            // Taking input from user to store in priority queue
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter priority: ");
            scanf("%d", &priority);
            struct Item item;
            item.data = val;
            item.priority = priority;
            insert(&front, &rear, item);
            break;
        case 2:

            // Checking for queue underflow
            if (isEmpty(front, rear))
                printf("Queue Underflow!!\n");
            else
                printf("The deleted element is: %d\n", minPriorityDelete(&front, &rear));
            break;
        case 3:
            if (isEmpty(front, rear))
                printf("Queue is empty.\n");
            else
            {
                printf("The contents of the queue is: ");
                display(front, rear);
            }
            break;
        default:
            printf("Entered option is invalid! Please enter a valid option.\n");
        }
        printf("Do you want to continue? If yes, press Enter else use Ctrl+C to Abort\n");
        getchar();
        fflush(stdin);
        repeat = getchar();
    } while (1);
    return 0;
}
// BFS and BFS spanning tree
// Sandip Dutta
// Create a graph data structure, then apply bfs on it

// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

/* QUEUE FUNCTIONS */
// We need a queue for BFS
struct queue {
  int items[SIZE];
  int front;
  int rear;
};

//  Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q -> rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
// We will be using a circular queue
void enqueue(struct queue* q, int value) {
  if (q -> rear == SIZE - 1){
    printf("\nQUEUE OVERFLOW!!!");
    exit(EXIT_FAILURE);
  }
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("\nQUEUE OVERFLOW!!!");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("\n[!] Queue is empty. Nothing to Print.");
  } else {
    printf("\nQueue : ");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
    printf("\n");
  }
}

// GRAPH NODE
struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

// Storing in adjacency list format
struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

// Pair for enqueueing 
struct pair{
    int vertex;
    int orderOfEntering;
};

struct pair make_pair(int vertex, int orderOfEntering){
    struct pair p;
    p.vertex = vertex;
    p.orderOfEntering = orderOfEntering;
    return p;
}
// ------------------------------------------------------

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();
  struct pair visitingOrder[graph->numVertices+1];
  int currPos = 0;
  int enteringOrder = 0;

  graph->visited[startVertex] = 1;

  enqueue(q, startVertex);
  visitingOrder[currPos++] = make_pair(startVertex, enteringOrder++);
 

  while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
    printf("NOW VISITING NODE NUM --> %d\n", currentVertex);    

    struct node* temp = graph->adjLists[currentVertex];
    if(temp)  ++enteringOrder;

    while (temp) {

      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        // Entering ORder
        visitingOrder[currPos++] = make_pair(adjVertex, enteringOrder);
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }

  //   Print visiting order of graph
  printf("%d\n", visitingOrder[0].vertex);
  
  for(int i = 1; i < graph->numVertices; ++i){
    
    if(visitingOrder[i].vertex < 0 || visitingOrder[i].vertex >= graph->numVertices) printf("\n");
    
    printf("%d", visitingOrder[i].vertex);
    if(visitingOrder[i].orderOfEntering != visitingOrder[i - 1].orderOfEntering){
        printf("\n");
    } else {
        printf("\t");
    }
  }

}

// Creating a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct Graph* createGraph(int num_vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = num_vertices;

  graph->adjLists = malloc(num_vertices * sizeof(struct node*));
  graph->visited = malloc(num_vertices * sizeof(int));

  int i;
  for (i = 0; i < num_vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

int main() {

  int n, startVertex, numEdges;
  printf("How many nodes to input? ");
  scanf("%d", &n);

  struct Graph* graph = createGraph(n);

  printf("How many Edges to input? ");
  scanf("%d", &numEdges);

  for(int i = 0; i < numEdges; ++i){
      int src, dest;
      printf("Add One Edge. Enter src, dest. [src, dest in 0..%d] ", n - 1);
      scanf("%d %d", &src, &dest);
      addEdge(graph, src, dest);
  }
  printf("Enter the starting vertex : [src, dest in 0..%d] ", n - 1);
  scanf("%d", &startVertex);

  //   Apply BFS 
  bfs(graph, startVertex);
  return 0;
}
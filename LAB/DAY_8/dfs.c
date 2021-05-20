// DFS algorithm in C
// Stack will not be needed as recursion equivalent to Stack
#include <stdio.h>
#include <stdlib.h>

/* GRAPH DATA STRUCTURE */
struct node {
  int vertex;
  struct node* next;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

//Graph 
struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
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

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  printf("\n THE GIVEN GRAPH IS :  \n ");

  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n NODE : %d, NEIGHBOURS : ", v);
    while (temp) {
      printf("%d\t", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}
/* END GRAPH DATA STRUCTURE */

// Depth First Algorithm
void DFS_VISIT(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("\nVISITING NODE :  %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      printf("\nGOING TO NODE : %d", connectedVertex);
      DFS_VISIT(graph, connectedVertex);
    }
    temp = temp->next;
  }
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

  // Print the Graph
  printGraph(graph);

  //  Apply DFS
  DFS_VISIT(graph, startVertex);
  printf("\nDFS COMPLETE !! ");
  return 0;
}
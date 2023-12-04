//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// Joaquim Madeira, Joao Manuel Rodrigues - June 2021, Nov 2023
//
// GraphBFS - QUEUE-based Breadth-First Search
//

#include "GraphBFSWithQueue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersQueue.h"
#include "IntegersStack.h"

struct _GraphBFSWithQueue {
  int* marked;       // To mark vertices when reached for the first time
  int* distance;     // The number of edges on the path from the start vertex
  int* predecessor;  // The predecessor vertex, when a vertex was reached
  Graph* graph;
  unsigned int startVertex;
};

GraphBFSWithQueue* GraphBFSWithQueueExecute(Graph* g,
                                            unsigned int startVertex) {
  assert(g != NULL);
  assert(startVertex < GraphGetNumVertices(g));

  GraphBFSWithQueue* traversal =
      (GraphBFSWithQueue*)malloc(sizeof(struct _GraphBFSWithQueue));
  assert(traversal != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  traversal->marked = (int*)calloc(numVertices, sizeof(unsigned int));
  assert(traversal->marked != NULL);

  traversal->predecessor = (int*)malloc(numVertices * sizeof(int));
  assert(traversal->predecessor != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    traversal->predecessor[i] = -1;
  }

  traversal->distance = (int*)malloc(numVertices * sizeof(int));
  assert(traversal->distance != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    traversal->distance[i] = -1;
  }

  traversal->graph = g;
  traversal->startVertex = startVertex;

  // CARRY OUT THE TRAVERSAL

  Queue* queue = QueueCreate(numVertices);

  QueueEnqueue(queue, startVertex);
  traversal->marked[startVertex] = 1;
  traversal->predecessor[startVertex] = -1;  // No predecessor for start vertex
                                             // Not necessary; already set as -1
  traversal->distance[startVertex] = 0;

  while (QueueIsEmpty(queue) == 0) {
    unsigned int vertex = QueueDequeue(queue);
    unsigned int* neighbors = GraphGetAdjacentsTo(traversal->graph, vertex);

    // neighbors[0] stores the number of neighbors of vertex
    for (unsigned int i = 1; i <= neighbors[0]; i++) {
      unsigned int w = neighbors[i];
      if (traversal->marked[w] == 0) {
        // Reached for the first time
        traversal->marked[w] = 1;
        traversal->predecessor[w] = vertex;
        traversal->distance[w] =
            traversal->distance[vertex] + 1;  // ONE more edge
        QueueEnqueue(queue, w);
      }
    }

    free(neighbors);
  }

  QueueDestroy(&queue);

  return traversal;
}

void GraphBFSWithQueueDestroy(GraphBFSWithQueue** p) {
  assert(*p != NULL);

  GraphBFSWithQueue* aux = *p;

  free(aux->marked);
  free(aux->predecessor);
  free(aux->distance);

  free(*p);
  *p = NULL;
}

// Getting the result

int GraphBFSWithQueueHasPathTo(const GraphBFSWithQueue* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

// NEW
int GraphBFSWithQueueDistanceTo(const GraphBFSWithQueue* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack* GraphBFSWithQueuePathTo(const GraphBFSWithQueue* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->marked[v] == 0) {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current]) {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphBFSWithQueueShowPath(const GraphBFSWithQueue* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = GraphBFSWithQueuePathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);

  if (p->marked[v] == 1) {
    printf(" --- with %d edges", p->distance[v]);
  }
}

void GraphBFSWithQueueDisplay(const GraphBFSWithQueue* p) {
  assert(p != NULL);

  if (GraphIsDigraph(p->graph) == 1) {
    printf("Digraph :\n");
  } else {
    printf("Digraph :\n");
  }
  GraphDisplay(p->graph);

  unsigned int numVertices = GraphGetNumVertices(p->graph);

  printf("Marked[] : ");
  for (unsigned int i = 0; i < numVertices; i++) {
    printf("%3d", p->marked[i]);
  }
  printf("\n");

  printf("Predecessor[] : ");
  for (unsigned int i = 0; i < numVertices; i++) {
    printf("%3d", p->predecessor[i]);
  }
  printf("\n");

  printf("Distance[] : ");
  for (unsigned int i = 0; i < numVertices; i++) {
    printf("%3d", p->distance[i]);
  }
  printf("\n");
}

//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// Joaquim Madeira, Joao Manuel Rodrigues - June 2021, Nov 2023
//
// GraphDFS - STACK-based Depth-First Search
//

#include "GraphDFSWithStack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphDFSWithStack {
  int* marked;       // To mark vertices when reached for the first time
  int* predecessor;  // The predecessor vertex, when a vertex was reached
  Graph* graph;
  unsigned int startVertex;
};

GraphDFSWithStack* GraphDFSWithStackExecute(Graph* g,
                                            unsigned int startVertex) {
  assert(g != NULL);
  assert(startVertex < GraphGetNumVertices(g));

  GraphDFSWithStack* traversal =
      (GraphDFSWithStack*)malloc(sizeof(struct _GraphDFSWithStack));
  assert(traversal != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  traversal->marked = (int*)calloc(numVertices, sizeof(unsigned int));
  assert(traversal->marked != NULL);

  traversal->predecessor = (int*)malloc(numVertices * sizeof(int));
  assert(traversal->predecessor != NULL);
  for (unsigned int i = 0; i < numVertices; i++) {
    traversal->predecessor[i] = -1;
  }

  traversal->graph = g;
  traversal->startVertex = startVertex;

  // CARRY OUT THE TRAVERSAL

  Stack* stack = StackCreate(numVertices);

  StackPush(stack, startVertex);
  traversal->marked[startVertex] = 1;
  traversal->predecessor[startVertex] = -1;  // No predecessor for start vertex
                                             // Not necessary; already set as -1

  while (StackIsEmpty(stack) == 0) {
    unsigned int vertex = StackPop(stack);
    unsigned int* neighbors = GraphGetAdjacentsTo(traversal->graph, vertex);

    // neighbors[0] stores the number of neighbors of vertex
    for (unsigned int i = 1; i <= neighbors[0]; i++) {
      unsigned int w = neighbors[i];
      if (traversal->marked[w] == 0) {
        // Reached for the first time
        traversal->marked[w] = 1;
        traversal->predecessor[w] = vertex;
        StackPush(stack, w);
      }
    }

    free(neighbors);
  }

  StackDestroy(&stack);

  return traversal;
}

void GraphDFSWithStackDestroy(GraphDFSWithStack** p) {
  assert(*p != NULL);

  GraphDFSWithStack* aux = *p;

  free(aux->marked);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

int GraphDFSWithStackHasPathTo(const GraphDFSWithStack* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  return p->marked[v];
}

Stack* GraphDFSWithStackPathTo(const GraphDFSWithStack* p, unsigned int v) {
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

void GraphDFSWithStackShowPath(const GraphDFSWithStack* p, unsigned int v) {
  assert(p != NULL);
  assert(v < GraphGetNumVertices(p->graph));

  Stack* s = GraphDFSWithStackPathTo(p, v);

  while (StackIsEmpty(s) == 0) {
    printf("%d ", StackPop(s));
  }

  StackDestroy(&s);
}

void GraphDFSWithStackDisplay(const GraphDFSWithStack* p) {
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
}

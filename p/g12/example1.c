//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - June 2021, Nov 2023, Nov 2024
//
// Graph EXAMPLE : Creating and displaying graphs
//

#include <assert.h>

#include "Graph.h"

int main(void) {
  // What kind of graph is g01?
  Graph* g01 = GraphCreate(6, 0, 0);
  GraphAddEdge(g01, 1, 2);
  GraphAddEdge(g01, 1, 4);
  GraphAddEdge(g01, 3, 4);
  printf("The first graph:\n");
  GraphDisplay(g01);
  for (int i = 0; i < 6; i++) {
    GraphListAdjacents(g01, i);
  }

  // NEW - Displaying in DOT format
  GraphDisplayDOT(g01);

  // Adding a duplicate edge is an invalid operation
  //assert(GraphAddEdge(g01, 4, 3) == 0);

  printf("Remove edge (1,2)\n");
  GraphRemoveEdge(g01, 1, 2);
  
  GraphDisplay(g01);
  for (int i = 0; i < 6; i++) {
    GraphListAdjacents(g01, i);
  }

  

  Graph* dig01 = GraphCreate(6, 1, 0);
  GraphAddEdge(dig01, 1, 2);
  GraphAddEdge(dig01, 1, 4);
  GraphAddEdge(dig01, 3, 4);
  printf("The second graph:\n");
  GraphDisplay(dig01);

  // NEW - Displaying in DOT format
  GraphDisplayDOT(dig01);

  // Adding a duplicate edge is an invalid operation
  assert(GraphAddEdge(dig01, 1, 4) == 0);

  printf("Remove edge (1,2)\n");
  GraphRemoveEdge(dig01, 1, 2);
  GraphDisplay(dig01);

  Graph* g03 = GraphCreate(6, 0, 1);
  GraphAddWeightedEdge(g03, 1, 2, 3);
  GraphAddWeightedEdge(g03, 1, 4, 5);
  GraphAddWeightedEdge(g03, 3, 4, 10);
  printf("The third graph:\n");
  GraphDisplay(g03);

  // NEW - Displaying in DOT format
  GraphDisplayDOT(g03);

  // Adding a duplicate edge is an invalid operation
  assert(GraphAddWeightedEdge(g03, 3, 4, 5) == 0);

  printf("Remove edge (1,2)\n");
  GraphRemoveEdge(g03, 1, 2);
  GraphDisplay(g03);

  GraphDestroy(&g01);
  GraphDestroy(&dig01);
  GraphDestroy(&g03);

  
  return 0;
}

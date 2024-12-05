//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - May 2020, Nov 2023,  Nov 2024
//
// Graph EXAMPLE : Using the DEPTH-FIRST recursive traversal
//

#include "Graph.h"
#include "GraphDFSRec.h"

int main(void) {
  // Graph
  Graph* g01 = GraphCreate(6, 0, 0);

  GraphAddEdge(g01, 0, 5);
  GraphAddEdge(g01, 2, 4);
  GraphAddEdge(g01, 2, 3);
  GraphAddEdge(g01, 1, 2);
  GraphAddEdge(g01, 0, 1);
  GraphAddEdge(g01, 3, 4);
  GraphAddEdge(g01, 3, 5);
  GraphAddEdge(g01, 0, 2);

  GraphDisplay(g01);

  // NEW - Displaying in DOT format
  GraphDisplayDOT(g01);

  // DFS traversal starting at vertex 0
  GraphDFSRec* traversal_start_0 = GraphDFSRecExecute(g01, 0);

  printf("Path from 0 to 5: ");
  GraphDFSRecShowPath(traversal_start_0, 5);
  printf("\n");

  GraphDFSRecDestroy(&traversal_start_0);

  GraphDestroy(&g01);

  // Digraph
  Graph* dig01 = GraphCreate(6, 1, 0);

  GraphAddEdge(dig01, 0, 5);
  GraphAddEdge(dig01, 2, 4);
  GraphAddEdge(dig01, 2, 3);
  GraphAddEdge(dig01, 1, 2);
  GraphAddEdge(dig01, 0, 1);
  GraphAddEdge(dig01, 3, 4);
  GraphAddEdge(dig01, 3, 5);
  GraphAddEdge(dig01, 0, 2);

  GraphDisplay(dig01);

  // NEW - Displaying in DOT format
  GraphDisplayDOT(dig01);

  // DFS traversal starting at vertex 1
  GraphDFSRec* traversal_start_1 = GraphDFSRecExecute(dig01, 1);

  printf("Path from 1 to 5: ");
  GraphDFSRecShowPath(traversal_start_1, 5);
  printf("\n");

  GraphDFSRecDestroy(&traversal_start_1);

  GraphDestroy(&dig01);

  return 0;
}

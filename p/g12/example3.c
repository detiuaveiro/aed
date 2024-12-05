//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - June 2021, Nov 2023
//
// Graph EXAMPLE : The different traversals
//

#include "Graph.h"
#include "GraphBFSWithQueue.h"
#include "GraphDFSRec.h"
#include "GraphDFSWithStack.h"

int main(void) {
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

  // Recursive DFS traversal

  printf("RECURSIVE DFS traversal\n");
  GraphDFSRec* traversalRec = GraphDFSRecExecute(g01, 0);

  printf("Path from 0 to 5: ");
  GraphDFSRecShowPath(traversalRec, 5);
  printf("\n");

  // Display the paths tree in DOT format
  printf("The paths tree rooted at 0\n");
  GraphDFSRecDisplayDOT(traversalRec);

  GraphDFSRecDestroy(&traversalRec);

  // STACK-based DFS traversal

  /* UNCOMMENT THE CODE AFTER COMPLETING THE TRAVERSAL CODE
  printf("DFS traversal with STACK\n");
  GraphDFSWithStack* traversalWithStack = GraphDFSWithStackExecute(g01, 0);

  printf("Path from 0 to 5: ");
  GraphDFSWithStackShowPath(traversalWithStack, 5);
  printf("\n");

  // Display the paths tree in DOT format
  printf("The paths tree rooted at 0\n");
  GraphDFSWithStackDisplayDOT(traversalRec);

  GraphDFSWithStackDestroy(&traversalWithStack);

  */

  // QUEUE-based BFS traversal

  /* UNCOMMENT THE CODE AFTER COMPLETING THE TRAVERSAL CODE
  printf("BFS traversal with QUEUE\n");
  GraphBFSWithQueue* traversalWithQueue = GraphBFSWithQueueExecute(g01, 0);

  printf("Path from 0 to 5: ");
  GraphBFSWithQueueShowPath(traversalWithQueue, 5);
  printf("\n");

  // Display the paths tree in DOT format
  printf("The paths tree rooted at 0\n");
  GraphBFSWithQueueDisplayDOT(traversalRec);

  GraphBFSWithQueueDestroy(&traversalWithQueue);

  */

  // FREE THE GRAPH
  GraphDestroy(&g01);

  return 0;
}

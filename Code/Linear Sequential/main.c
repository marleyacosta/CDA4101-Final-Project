#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "graph.c"

/*

 Course: CDA4101-U01
 Description: This program does not use multithreading.
 This program converts a graph represented as an adjacency
 list into an adjacency matrix.
 The adjacency matrix is completed sequentially.
 */

struct Graph* graph;
int vertices;
int * adjacencyMatrix;

/*
This methods traverses the adjacency list that represents the graph
sequentially. Each vertex that a head node is adjacent to is set to 1
in the adjacency matrix.
*/
void set2DArrayLinear(struct Graph* graph)
{
  // Allocating memory for the global matrix
  adjacencyMatrix = (int *)malloc( vertices * vertices * sizeof(int));
  memset( adjacencyMatrix, 0, vertices*vertices*sizeof(int) );

    int node_head;
    for (node_head = 0; node_head < vertices; ++node_head)
    {

        struct node* matrix_row = graph->adjLists[node_head];
        printf("\n\n\nAdjacent Nodes of Vertex[%d]\n", node_head);
        while (matrix_row)
        {
            printf("Node: %d\n", matrix_row->vertex);
            *((adjacencyMatrix + node_head*vertices) + matrix_row->vertex) = 1;
            matrix_row = matrix_row->next;
        }
    }

}

/*
This method prints the matrix.
*/
void printMatrix()
{
    int row;
    int column;
    for(row = 0; row < vertices; row++)
    {
        for(column = 0; column < vertices; column++)
        {
            printf(" %d ", *((adjacencyMatrix + row*vertices) + column));
        }
          printf("\n\n");
    }
}

/*
This method does the behind the scenes multithreading and calculates the
time to generate the matrix for a given graph.
*/
void calculateTimeToGenerateMatrix(char * graph_type){
  //----------------------------------------
  clock_t tic = clock();

  set2DArrayLinear(graph);

  clock_t toc = clock();

  printMatrix();

  printf("Elapsed time: %f milliseconds\n", (double)(toc - tic) / (CLOCKS_PER_SEC / 1000));
  //----------------------------------------
}


int main()
{
  //--------------------------------------------------------------------------

  // The 20 vertices Graph with 4 edges per node.

  vertices = 20;
  graph = createGraph(vertices);


  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 4);

  addEdge(graph, 1, 0);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);

  addEdge(graph, 2, 0);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);

  addEdge(graph, 3, 0);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 4);

  addEdge(graph, 4, 0);
  addEdge(graph, 4, 2);
  addEdge(graph, 4, 3);
  addEdge(graph, 4, 4);

  addEdge(graph, 5, 0);
  addEdge(graph, 5, 2);
  addEdge(graph, 5, 3);
  addEdge(graph, 5, 4);

  addEdge(graph, 6, 0);
  addEdge(graph, 6, 2);
  addEdge(graph, 6, 3);
  addEdge(graph, 6, 4);

  addEdge(graph, 7, 0);
  addEdge(graph, 7, 2);
  addEdge(graph, 7, 3);
  addEdge(graph, 7, 4);

  addEdge(graph, 8, 0);
  addEdge(graph, 8, 2);
  addEdge(graph, 8, 3);
  addEdge(graph, 8, 4);

  addEdge(graph, 9, 0);
  addEdge(graph, 9, 2);
  addEdge(graph, 9, 3);
  addEdge(graph, 9, 4);

  addEdge(graph, 10, 0);
  addEdge(graph, 10, 2);
  addEdge(graph, 10, 3);
  addEdge(graph, 10, 4);

  addEdge(graph, 11, 0);
  addEdge(graph, 11, 2);
  addEdge(graph, 11, 3);
  addEdge(graph, 11, 4);

  addEdge(graph, 12, 0);
  addEdge(graph, 12, 2);
  addEdge(graph, 12, 3);
  addEdge(graph, 12, 4);

  addEdge(graph, 13, 0);
  addEdge(graph, 13, 2);
  addEdge(graph, 13, 3);
  addEdge(graph, 13, 4);

  addEdge(graph, 14, 0);
  addEdge(graph, 14, 2);
  addEdge(graph, 14, 3);
  addEdge(graph, 14, 4);

  addEdge(graph, 15, 0);
  addEdge(graph, 15, 2);
  addEdge(graph, 15, 3);
  addEdge(graph, 15, 4);

  addEdge(graph, 16, 0);
  addEdge(graph, 16, 2);
  addEdge(graph, 16, 3);
  addEdge(graph, 16, 4);

  addEdge(graph, 17, 0);
  addEdge(graph, 17, 2);
  addEdge(graph, 17, 3);
  addEdge(graph, 17, 4);

  addEdge(graph, 18, 0);
  addEdge(graph, 18, 2);
  addEdge(graph, 18, 3);
  addEdge(graph, 18, 4);

  addEdge(graph, 19, 0);
  addEdge(graph, 19, 2);
  addEdge(graph, 19, 3);
  addEdge(graph, 19, 4);

  printGraph(graph);

  calculateTimeToGenerateMatrix("The 20 vertices Graph with 4 edges per node.");
  //--------------------------------------------------------------------------
  //--------------------------------------------------------------------------
  // The 4 vertices Graph with 20 edges per node.

  vertices = 4;
  graph = createGraph(vertices);


  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 0);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 0);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 0);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 0);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 0);


  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);

  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);

  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);

  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);

  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 0);


  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 0);

  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 0);

  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 0);

  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 0);

  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 0);





  printGraph(graph);

  calculateTimeToGenerateMatrix("The 4 vertices Graph with 20 edges per node.");
  //--------------------------------------------------------------------------
  //--------------------------------------------------------------------------

  // The 20 vertices Graph with 20 edges per node

  vertices = 20;
  graph = createGraph(vertices);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 4);
  addEdge(graph, 0, 5);
  addEdge(graph, 0, 6);
  addEdge(graph, 0, 7);
  addEdge(graph, 0, 8);
  addEdge(graph, 0, 9);
  addEdge(graph, 0, 10);
  addEdge(graph, 0, 11);
  addEdge(graph, 0, 12);
  addEdge(graph, 0, 13);
  addEdge(graph, 0, 14);
  addEdge(graph, 0, 15);
  addEdge(graph, 0, 16);
  addEdge(graph, 0, 17);
  addEdge(graph, 0, 18);
  addEdge(graph, 0, 19);
  addEdge(graph, 0, 0);

  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 5);
  addEdge(graph, 1, 6);
  addEdge(graph, 1, 7);
  addEdge(graph, 1, 8);
  addEdge(graph, 1, 9);
  addEdge(graph, 1, 10);
  addEdge(graph, 1, 11);
  addEdge(graph, 1, 12);
  addEdge(graph, 1, 13);
  addEdge(graph, 1, 14);
  addEdge(graph, 1, 15);
  addEdge(graph, 1, 16);
  addEdge(graph, 1, 17);
  addEdge(graph, 1, 18);
  addEdge(graph, 1, 19);
  addEdge(graph, 1, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 6);
  addEdge(graph, 2, 7);
  addEdge(graph, 2, 8);
  addEdge(graph, 2, 9);
  addEdge(graph, 2, 10);
  addEdge(graph, 2, 11);
  addEdge(graph, 2, 12);
  addEdge(graph, 2, 13);
  addEdge(graph, 2, 14);
  addEdge(graph, 2, 15);
  addEdge(graph, 2, 16);
  addEdge(graph, 2, 17);
  addEdge(graph, 2, 18);
  addEdge(graph, 2, 19);
  addEdge(graph, 2, 0);

  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 3, 6);
  addEdge(graph, 3, 7);
  addEdge(graph, 3, 8);
  addEdge(graph, 3, 9);
  addEdge(graph, 3, 10);
  addEdge(graph, 3, 11);
  addEdge(graph, 3, 12);
  addEdge(graph, 3, 13);
  addEdge(graph, 3, 14);
  addEdge(graph, 3, 15);
  addEdge(graph, 3, 16);
  addEdge(graph, 3, 17);
  addEdge(graph, 3, 18);
  addEdge(graph, 3, 19);
  addEdge(graph, 3, 0);

  addEdge(graph, 4, 1);
  addEdge(graph, 4, 2);
  addEdge(graph, 4, 3);
  addEdge(graph, 4, 4);
  addEdge(graph, 4, 5);
  addEdge(graph, 4, 6);
  addEdge(graph, 4, 7);
  addEdge(graph, 4, 8);
  addEdge(graph, 4, 9);
  addEdge(graph, 4, 10);
  addEdge(graph, 4, 11);
  addEdge(graph, 4, 12);
  addEdge(graph, 4, 13);
  addEdge(graph, 4, 14);
  addEdge(graph, 4, 15);
  addEdge(graph, 4, 16);
  addEdge(graph, 4, 17);
  addEdge(graph, 4, 18);
  addEdge(graph, 4, 19);
  addEdge(graph, 4, 0);

  addEdge(graph, 5, 1);
  addEdge(graph, 5, 2);
  addEdge(graph, 5, 3);
  addEdge(graph, 5, 4);
  addEdge(graph, 5, 5);
  addEdge(graph, 5, 6);
  addEdge(graph, 5, 7);
  addEdge(graph, 5, 8);
  addEdge(graph, 5, 9);
  addEdge(graph, 5, 10);
  addEdge(graph, 5, 11);
  addEdge(graph, 5, 12);
  addEdge(graph, 5, 13);
  addEdge(graph, 5, 14);
  addEdge(graph, 5, 15);
  addEdge(graph, 5, 16);
  addEdge(graph, 5, 17);
  addEdge(graph, 5, 18);
  addEdge(graph, 5, 19);
  addEdge(graph, 5, 0);

  addEdge(graph, 6, 1);
  addEdge(graph, 6, 2);
  addEdge(graph, 6, 3);
  addEdge(graph, 6, 4);
  addEdge(graph, 6, 5);
  addEdge(graph, 6, 6);
  addEdge(graph, 6, 7);
  addEdge(graph, 6, 8);
  addEdge(graph, 6, 9);
  addEdge(graph, 6, 10);
  addEdge(graph, 6, 11);
  addEdge(graph, 6, 12);
  addEdge(graph, 6, 13);
  addEdge(graph, 6, 14);
  addEdge(graph, 6, 15);
  addEdge(graph, 6, 16);
  addEdge(graph, 6, 17);
  addEdge(graph, 6, 18);
  addEdge(graph, 6, 19);
  addEdge(graph, 6, 0);

  addEdge(graph, 7, 1);
  addEdge(graph, 7, 2);
  addEdge(graph, 7, 3);
  addEdge(graph, 7, 4);
  addEdge(graph, 7, 5);
  addEdge(graph, 7, 6);
  addEdge(graph, 7, 7);
  addEdge(graph, 7, 8);
  addEdge(graph, 7, 9);
  addEdge(graph, 7, 10);
  addEdge(graph, 7, 11);
  addEdge(graph, 7, 12);
  addEdge(graph, 7, 13);
  addEdge(graph, 7, 14);
  addEdge(graph, 7, 15);
  addEdge(graph, 7, 16);
  addEdge(graph, 7, 17);
  addEdge(graph, 7, 18);
  addEdge(graph, 7, 19);
  addEdge(graph, 7, 0);

  addEdge(graph, 8, 1);
  addEdge(graph, 8, 2);
  addEdge(graph, 8, 3);
  addEdge(graph, 8, 4);
  addEdge(graph, 8, 5);
  addEdge(graph, 8, 6);
  addEdge(graph, 8, 7);
  addEdge(graph, 8, 8);
  addEdge(graph, 8, 9);
  addEdge(graph, 8, 10);
  addEdge(graph, 8, 11);
  addEdge(graph, 8, 12);
  addEdge(graph, 8, 13);
  addEdge(graph, 8, 14);
  addEdge(graph, 8, 15);
  addEdge(graph, 8, 16);
  addEdge(graph, 8, 17);
  addEdge(graph, 8, 18);
  addEdge(graph, 8, 19);
  addEdge(graph, 8, 0);

  addEdge(graph, 9, 1);
  addEdge(graph, 9, 2);
  addEdge(graph, 9, 3);
  addEdge(graph, 9, 4);
  addEdge(graph, 9, 5);
  addEdge(graph, 9, 6);
  addEdge(graph, 9, 7);
  addEdge(graph, 9, 8);
  addEdge(graph, 9, 9);
  addEdge(graph, 9, 10);
  addEdge(graph, 9, 11);
  addEdge(graph, 9, 12);
  addEdge(graph, 9, 13);
  addEdge(graph, 9, 14);
  addEdge(graph, 9, 15);
  addEdge(graph, 9, 16);
  addEdge(graph, 9, 17);
  addEdge(graph, 9, 18);
  addEdge(graph, 9, 19);
  addEdge(graph, 9, 0);

  addEdge(graph, 10, 1);
  addEdge(graph, 10, 2);
  addEdge(graph, 10, 3);
  addEdge(graph, 10, 4);
  addEdge(graph, 10, 5);
  addEdge(graph, 10, 6);
  addEdge(graph, 10, 7);
  addEdge(graph, 10, 8);
  addEdge(graph, 10, 9);
  addEdge(graph, 10, 10);
  addEdge(graph, 10, 11);
  addEdge(graph, 10, 12);
  addEdge(graph, 10, 13);
  addEdge(graph, 10, 14);
  addEdge(graph, 10, 15);
  addEdge(graph, 10, 16);
  addEdge(graph, 10, 17);
  addEdge(graph, 10, 18);
  addEdge(graph, 10, 19);
  addEdge(graph, 10, 0);

  addEdge(graph, 11, 1);
  addEdge(graph, 11, 2);
  addEdge(graph, 11, 3);
  addEdge(graph, 11, 4);
  addEdge(graph, 11, 5);
  addEdge(graph, 11, 6);
  addEdge(graph, 11, 7);
  addEdge(graph, 11, 8);
  addEdge(graph, 11, 9);
  addEdge(graph, 11, 10);
  addEdge(graph, 11, 11);
  addEdge(graph, 11, 12);
  addEdge(graph, 11, 13);
  addEdge(graph, 11, 14);
  addEdge(graph, 11, 15);
  addEdge(graph, 11, 16);
  addEdge(graph, 11, 17);
  addEdge(graph, 11, 18);
  addEdge(graph, 11, 19);
  addEdge(graph, 11, 0);

  addEdge(graph, 12, 1);
  addEdge(graph, 12, 2);
  addEdge(graph, 12, 3);
  addEdge(graph, 12, 4);
  addEdge(graph, 12, 5);
  addEdge(graph, 12, 6);
  addEdge(graph, 12, 7);
  addEdge(graph, 12, 8);
  addEdge(graph, 12, 9);
  addEdge(graph, 12, 10);
  addEdge(graph, 12, 11);
  addEdge(graph, 12, 12);
  addEdge(graph, 12, 13);
  addEdge(graph, 12, 14);
  addEdge(graph, 12, 15);
  addEdge(graph, 12, 16);
  addEdge(graph, 12, 17);
  addEdge(graph, 12, 18);
  addEdge(graph, 12, 19);
  addEdge(graph, 12, 0);

  addEdge(graph, 13, 1);
  addEdge(graph, 13, 2);
  addEdge(graph, 13, 3);
  addEdge(graph, 13, 4);
  addEdge(graph, 13, 5);
  addEdge(graph, 13, 6);
  addEdge(graph, 13, 7);
  addEdge(graph, 13, 8);
  addEdge(graph, 13, 9);
  addEdge(graph, 13, 10);
  addEdge(graph, 13, 11);
  addEdge(graph, 13, 12);
  addEdge(graph, 13, 13);
  addEdge(graph, 13, 14);
  addEdge(graph, 13, 15);
  addEdge(graph, 13, 16);
  addEdge(graph, 13, 17);
  addEdge(graph, 13, 18);
  addEdge(graph, 13, 19);
  addEdge(graph, 13, 0);

  addEdge(graph, 14, 1);
  addEdge(graph, 14, 2);
  addEdge(graph, 14, 3);
  addEdge(graph, 14, 4);
  addEdge(graph, 14, 5);
  addEdge(graph, 14, 6);
  addEdge(graph, 14, 7);
  addEdge(graph, 14, 8);
  addEdge(graph, 14, 9);
  addEdge(graph, 14, 10);
  addEdge(graph, 14, 11);
  addEdge(graph, 14, 12);
  addEdge(graph, 14, 13);
  addEdge(graph, 14, 14);
  addEdge(graph, 14, 15);
  addEdge(graph, 14, 16);
  addEdge(graph, 14, 17);
  addEdge(graph, 14, 18);
  addEdge(graph, 14, 19);
  addEdge(graph, 14, 0);

  addEdge(graph, 15, 1);
  addEdge(graph, 15, 2);
  addEdge(graph, 15, 3);
  addEdge(graph, 15, 4);
  addEdge(graph, 15, 5);
  addEdge(graph, 15, 6);
  addEdge(graph, 15, 7);
  addEdge(graph, 15, 8);
  addEdge(graph, 15, 9);
  addEdge(graph, 15, 10);
  addEdge(graph, 15, 11);
  addEdge(graph, 15, 12);
  addEdge(graph, 15, 13);
  addEdge(graph, 15, 14);
  addEdge(graph, 15, 15);
  addEdge(graph, 15, 16);
  addEdge(graph, 15, 17);
  addEdge(graph, 15, 18);
  addEdge(graph, 15, 19);
  addEdge(graph, 15, 0);

  addEdge(graph, 16, 1);
  addEdge(graph, 16, 2);
  addEdge(graph, 16, 3);
  addEdge(graph, 16, 4);
  addEdge(graph, 16, 5);
  addEdge(graph, 16, 6);
  addEdge(graph, 16, 7);
  addEdge(graph, 16, 8);
  addEdge(graph, 16, 9);
  addEdge(graph, 16, 10);
  addEdge(graph, 16, 11);
  addEdge(graph, 16, 12);
  addEdge(graph, 16, 13);
  addEdge(graph, 16, 14);
  addEdge(graph, 16, 15);
  addEdge(graph, 16, 16);
  addEdge(graph, 16, 17);
  addEdge(graph, 16, 18);
  addEdge(graph, 16, 19);
  addEdge(graph, 16, 0);

  addEdge(graph, 17, 1);
  addEdge(graph, 17, 2);
  addEdge(graph, 17, 3);
  addEdge(graph, 17, 4);
  addEdge(graph, 17, 5);
  addEdge(graph, 17, 6);
  addEdge(graph, 17, 7);
  addEdge(graph, 17, 8);
  addEdge(graph, 17, 9);
  addEdge(graph, 17, 10);
  addEdge(graph, 17, 11);
  addEdge(graph, 17, 12);
  addEdge(graph, 17, 13);
  addEdge(graph, 17, 14);
  addEdge(graph, 17, 15);
  addEdge(graph, 17, 16);
  addEdge(graph, 17, 17);
  addEdge(graph, 17, 18);
  addEdge(graph, 17, 19);
  addEdge(graph, 17, 0);

  addEdge(graph, 18, 1);
  addEdge(graph, 18, 2);
  addEdge(graph, 18, 3);
  addEdge(graph, 18, 4);
  addEdge(graph, 18, 5);
  addEdge(graph, 18, 6);
  addEdge(graph, 18, 7);
  addEdge(graph, 18, 8);
  addEdge(graph, 18, 9);
  addEdge(graph, 18, 10);
  addEdge(graph, 18, 11);
  addEdge(graph, 18, 12);
  addEdge(graph, 18, 13);
  addEdge(graph, 18, 14);
  addEdge(graph, 18, 15);
  addEdge(graph, 18, 16);
  addEdge(graph, 18, 17);
  addEdge(graph, 18, 18);
  addEdge(graph, 18, 19);
  addEdge(graph, 18, 0);

  addEdge(graph, 19, 1);
  addEdge(graph, 19, 2);
  addEdge(graph, 19, 3);
  addEdge(graph, 19, 4);
  addEdge(graph, 19, 5);
  addEdge(graph, 19, 6);
  addEdge(graph, 19, 7);
  addEdge(graph, 19, 8);
  addEdge(graph, 19, 9);
  addEdge(graph, 19, 10);
  addEdge(graph, 19, 11);
  addEdge(graph, 19, 12);
  addEdge(graph, 19, 13);
  addEdge(graph, 19, 14);
  addEdge(graph, 19, 15);
  addEdge(graph, 19, 16);
  addEdge(graph, 19, 17);
  addEdge(graph, 19, 18);
  addEdge(graph, 19, 19);
  addEdge(graph, 19, 0);

  printGraph(graph);

  calculateTimeToGenerateMatrix("The 20 vertices Graph with 20 edges per node");
  //--------------------------------------------------------------------------
  // The 4 vertices Graph

  vertices = 4;
  graph = createGraph(vertices);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 0, 0);

  addEdge(graph, 1, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 0);

  addEdge(graph, 2, 1);
  addEdge(graph, 2, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 0);

  addEdge(graph, 3, 1);
  addEdge(graph, 3, 2);
  addEdge(graph, 3, 3);
  addEdge(graph, 3, 0);

  printGraph(graph);

  calculateTimeToGenerateMatrix("The 4 vertices Graph with 4 edges per node");


    return 0;
}

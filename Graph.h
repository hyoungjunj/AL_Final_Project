#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "LinkedList.h"

typedef struct _graph{
    List *rout; //adjList
    int *visitInfo;
}Graph;

void GraphInit(Graph *pg, int nv);

void AddEdge(Graph *pg, City fromV, City toV);

void ShowGraphEdgeInfo(Graph *pg);

#endif
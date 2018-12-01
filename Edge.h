#ifndef __EDGE_H__
#define __EDGE_H__

#include "Graph.h"


typedef struct _edge{
    int city1;
    int city2;
    int distance;
}Edge;

void EdgeInit(Graph *pg, Edge *pedge);

void ShowEdgeInfo(Edge *pedge);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Graph.h"



void GraphInit(Graph *pg, int nv){
    pg->rout = (List*)malloc(sizeof(List)*nv);
    pg->visitInfo= (int *)malloc(sizeof(int) * nv);
    memset(pg->visitInfo, 0, sizeof(int) * nv);

    for(int i=0; i<nv; i++) ListInit(&(pg->rout[i]));
}

void AddEdge(Graph *pg, City fromV, City toV){
    LInsert(&(pg->rout[fromV.city_code]), toV);
    LInsert(&(pg->rout[toV.city_code]), fromV);
}

void ShowGraphEdgeInfo(Graph *pg){
    int adjV;
    for(int i=0; i<MAXCITY; i++)    {
        printf("%d와 연결된 vertix: ", i);
        if(LFirst(&(pg->rout[i]), &adjV))        {
            printf("%d ", adjV);
            while(LNext(&(pg->rout[i]), &adjV)) printf("%d ", adjV);
        }
        printf("\n");
    }
}
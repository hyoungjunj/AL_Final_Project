#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Graph.h"
//#include "Edge.h"

typedef int BUDGET;

typedef struct _edge{
    int city1;
    int city2;
    int distance;
}Edge;

typedef struct _budget{
    int total; //total budget
    int trans; //transportation budget
    int hotel; //hotel budget
}Budget;

typedef struct _hotel{
    int price; // 50, 55, 60, ... , 495, 500
    int level; // 1~5
    int hotel_code;
}Hotel;

typedef struct _customer{
    char name[100];
    TIME time;
    char start_time[100];
    char end_time[100];
    BUDGET budget;
    
    City dest_city[100];
    City rout_city[1000];
    Hotel hotel[100];
}Customer;


int main(){
    Graph graph;
    City city[100];
    Edge edge[300];
    int i;
    int j, x, y, d;

    srand(time(NULL));

    //init cities
    for(i=0; i<100; i++){
        city[i].city_code = i;
        city[i].tour_time = ((rand()%4)+1)*24; //24, 48, 72, 96
    }

    //init graph
    GraphInit(&graph, 100);

    //init edges & add edges on graph
    i=0;
    while(1){
        x = rand()%100; //from city[x]
        y = rand()%100; //to city[y]
        d = (rand()%10+1); //distance 범위 뭐였지???????????????????????????
       
        if(x!=y){
            for(j=0;j<i;j++){ //find duplicated edges
                if(edge[j].city1 == x && edge[j].city2 == y) break;
                if(edge[j].city1 == y && edge[j].city2 == x) break;
            }

            if(j == i){
                edge[i].city1 = x; //input new edge
                edge[i].city2 = y;
                edge[i].distance = d;

                AddEdge(&graph, city[x], city[y]); //add the edge on graph

                i++;
                if(i==300) break;
            }
        }
    }

    /*
    //init edges
    EdgeInit(&graph, &edge);
    //add edges on graph
    for(i=0;i<300;i++)
    	AddEdge(&graph, city[edge[i].city1], city[edge[i].city2]); */

    //print graph
    ShowGraphEdgeInfo(&graph);
    printf("\n");
    //print edges
    for(i=0;i<300;i++)
        printf("from site_%d to site_%d: %d\n", edge[i].city1, edge[i].city2, edge[i].distance);
    //ShowEdgeInfo(&edge);



}
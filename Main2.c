
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Graph.h"
#include "Dijkstra.h"
//#include "Edge.h"

/*
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
    char name[MAXCITY];
    TIME time;
    char start_time[MAXCITY];
    char end_time[MAXCITY];
    BUDGET budget;
    
    City dest_city[MAXCITY];
    City rout_city[MAXCITY];
	
	
    Hotel hotel[MAXCITY];
}Customer;*/

void Dijkstra(int c1, int c2, Graph *pg, Customer *p, Edge *edge);

int main(){
    Graph graph;
    City city[MAXCITY];
    Edge edge[MAXEDGE];
	Customer mg;

    int i;
    int j, x, y, d;

    srand(time(NULL));

    //init cities
    for(i=0; i<MAXCITY; i++){
        city[i].city_code = i;
        city[i].tour_time = ((rand()%4)+1)*24; //24, 48, 72, 96
    }

    //init graph
    GraphInit(&graph, 100);

    //init edges & add edges on graph
    i=0;
    while(1){
        x = rand()%MAXCITY; //from city[x]
        y = rand()%MAXCITY; //to city[y]
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
                if(i==MAXEDGE) break;
            }
        }
    }

    /*
    //init edges
    EdgeInit(&graph, &edge);
    //add edges on graph
    for(i=0;i<300;i++)
    	AddEdge(&graph, city[edge[i].city1], city[edge[i].city2]); 
		*/
    //print graph
	
	ShowGraphEdgeInfo(&graph);
    printf("\n");
    //print edges
    for(i=0;i<MAXEDGE;i++)
        printf("from site_%d to site_%d: %d\n", edge[i].city1, edge[i].city2, edge[i].distance);
    //ShowEdgeInfo(&edge);
	

	Dijkstra(1, 2, &graph, &mg, edge);
	
	i = 0;
	
	while (mg.rout_city[i].city_code != inf) {
	
		printf("%d,", mg.rout_city[i].city_code);
		i++;
	}
}

/*
void Dijkstra(int c1, int c2, Graph *pg, Customer *p, Edge *edge) {

	int flag[MAXCITY];//create vertex set Q
	
	int i;
	int dist[MAXCITY];
	int prev[MAXCITY];
	

	dist[c1] = 0;

	for (i = 0;i < MAXCITY;i++) {
		
		if (i != c1) 
			dist[i] = inf;
		
		prev[i] = inf;//NULL
		
		flag[i] = 0;//add v	to Q or with priority(dist[v])
	}

	
	while (1/*Q*///) { // 큐에 있는 꼭지점 중에서

		//배열의 원소가 전부 1이면 break
/*		int i;
		int flag2 = 0;

		for (i = 0; i < MAXCITY; i++) {
			if (flag[i] == 0)
				flag2 = 1;
		}

		if (flag2 == 0)
			break;

		
		int min_idx;
		int min = inf;

		// choose and remove vertex in Q with min dist[u] // 큐의 루트를 제거하고 반환한다
		for (i = 0; i < MAXCITY; i++) { 
			if (flag[i] == 0) {
				if (dist[i] <= min){
					min = dist[i];
					min_idx = i;
				}
			}
		}


		if (min_idx == c2)
			break;

		flag[min_idx] = 1;

		
		//min_idx가 큐에 있는 최소 꼭지점. vertex j의 이웃 꼭지점 찾기

		int n_idx;
		
		if (LFirst(&(pg->rout[min_idx]), &n_idx)) {

			//length from j to n_idx
			
			int alt;
			int len;
			
			for (i = 0; i < MAXEDGE /*edge 배열 길이*/ //; i++) {
/*				if ((edge[i].city1 == min_idx && edge[i].city2 == n_idx) || (edge[i].city1 == n_idx && edge[i].city2 == min_idx))
					len = edge[i].distance;
			}

			//a에 대해서 더 짧은 경로가 있는지 확인.
			alt = dist[min_idx] + len;

			if (alt < dist[n_idx]) {
				dist[n_idx] = alt;
				prev[n_idx] = min_idx;
			}

			while (LNext(&(pg->rout[min_idx]), &n_idx)) {

				for (i = 0; i < MAXEDGE; i++) {
					if ((edge[i].city1 == min_idx && edge[i].city2 == n_idx) || (edge[i].city1 == n_idx && edge[i].city2 == min_idx))
						len = edge[i].distance;
				}

				alt = dist[min_idx] + len;

				if (alt < dist[n_idx]) {
					dist[n_idx] = alt;
					prev[n_idx] = min_idx;
				}
			}
		}
	}

	//최소 경비를 찾았고 이제 경로를 저장한다. //역순으로 저장
	int rout = c2;
	p->rout_city[0].city_code = rout;
	
	i = 1;

	while (rout != inf) { //NULL
		
		rout = prev[rout];
		p->rout_city[i].city_code = rout;
		
		i++;
	}
	
} */
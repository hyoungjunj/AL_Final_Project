#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Graph.h"
#include "Dijkstra.h"

#define inf 2147483647		// 추가


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

	
	while (1/*Q*/) { // 큐에 있는 꼭지점 중에서

		//배열의 원소가 전부 1이면 break
		int i;
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
			
			for (i = 0; i < MAXEDGE /*edge 배열 길이*/; i++) {
				if ((edge[i].city1 == min_idx && edge[i].city2 == n_idx) || (edge[i].city1 == n_idx && edge[i].city2 == min_idx))
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
	
}
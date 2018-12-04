#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

#define MAXCITY 100
#define MAXEDGE 50
#define inf 2147483647		// 추가

typedef int TIME;

typedef struct _city{
    TIME tour_time;
    int city_code;
}City;

typedef struct _node{
    City data;
    struct _node *next;
} Node;

typedef struct _linkedList{
    Node *head;
    Node *cur;
    Node *before;
    int numOfData; //??????????????필요할까??
}List;

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

typedef struct _customer{ //temporary
    char name[MAXCITY];
    TIME time;
    char start_time[MAXCITY];
    char end_time[MAXCITY];
    BUDGET budget;
    
    City dest_city[MAXCITY];
    City rout_city[MAXCITY];
	
	
    Hotel hotel[MAXCITY];
}Customer;

void ListInit(List *plist);
void LInsert(List *plist, City data);

int LFirst(List *plist, int *pdata);
int LNext(List *plist, int *pdata);

#endif
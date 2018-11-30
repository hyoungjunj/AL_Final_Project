#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

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

void ListInit(List *plist);
void LInsert(List *plist, City data);

int LFirst(List *plist, int *pdata);
int LNext(List *plist, int *pdata);

#endif
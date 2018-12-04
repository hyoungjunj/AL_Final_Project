#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

// typedef int LData;

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

typedef struct _linkedList
{
    Node * head;
    Node * cur;
    Node * before;
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, int data);

int LFirst(List * plist, int * pdata);
int LNext(List * plist, int * pdata);

int LRemove(List * plist);

#endif
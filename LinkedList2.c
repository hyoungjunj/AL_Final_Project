#include <stdio.h>
#include <stdlib.h>
#include "LinkedList2.h"

void ListInit(List * plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
}

void LInsert(List * plist, int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->head->next;
    plist->head->next = newNode;
}

int LFirst(List * plist, int * pdata)
{
    if(plist->head->next == NULL)
        return FALSE;
    
    plist->before = plist->head;
    plist->cur = plist->head->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List * plist, int * pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

int LRemove(List * plist)
{
    Node * rpos = plist->cur;
    int rdata = rpos->data;
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    return rdata;
}
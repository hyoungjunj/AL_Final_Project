#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List *plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->numOfData = 0;
    plist->head->next = NULL;
}


void LInsert(List *plist, City data){
    Node *newN = (Node*)malloc(sizeof(Node));
    (plist->numOfData)++;
    newN->data = data;
    newN->next = plist->head->next;
    plist->head->next = newN;
}

int LFirst(List *plist, int *pdata){
    if(plist->head->next == NULL) return FALSE;
    else{
        plist->cur = plist->head->next;
        plist->before = plist->head;
        *pdata = plist->cur->data.city_code;
        return TRUE;
    }
}

int LNext(List *plist, int *pdata){
    if(plist->cur->next == NULL) return FALSE;
    else{
        plist->cur = plist->cur->next;
        plist->before = plist->cur;
        *pdata = plist->cur->data.city_code;
        return TRUE;
    }
}
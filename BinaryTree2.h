#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int DATA;

typedef struct _NODE
{
    DATA data;
    char color;
    struct _NODE * left;
    struct _NODE * right;
    struct _NODE * parent;
} NODE;

NODE * makeNODE(DATA data);

void LinkRight(NODE *parent, NODE *rightchild);
void LinkLeft(NODE *parent, NODE *leftchild);
void LinkParent(NODE *parent, NODE *child);
void InorderTraverse(NODE * bt);
void InorderTraversePrint(NODE * bt);

void Print_BST(NODE *root, int space);

#endif
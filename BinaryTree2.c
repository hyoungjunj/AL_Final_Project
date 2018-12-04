#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

NODE * makeNODE(DATA data)
{
	NODE *node = (NODE*)malloc(sizeof(NODE));

	node->left = NULL;
	node->right = NULL;
    node->parent = NULL;
    node->data = data;
    
    return node;
}

void LinkRight(NODE *parent, NODE *rightchild){
    parent->right = rightchild;
}

void LinkLeft(NODE *parent, NODE *leftchild){
    parent->left = leftchild;
}

void LinkParent(NODE *parent, NODE *child){
    child->parent = parent;
}

void InorderTraverse(NODE * bt)
{
    NODE *Leaf = (NODE*)malloc(sizeof(NODE));
    //printf("Print\n");
	if(bt == NULL)
    return;

	InorderTraverse(bt->left);
    if(bt->left == NULL && bt->right == NULL) bt->left = Leaf;
	InorderTraverse(bt->right);
}

void InorderTraversePrint(NODE * bt){
    printf("InorderTraverse Print BST\n");
    InorderTraverse(bt);
    printf("\n");
}

void Print_BST(NODE *root, int space)
{
    if (root == NULL)
        return;
    
    space += 10;
    
    Print_BST(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d(%d)\n", root->data, root->color);
    
    Print_BST(root->left, space);
}

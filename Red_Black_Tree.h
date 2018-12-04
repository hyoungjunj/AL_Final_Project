//
//  Red_Black_Tree.h
//  Report2
//
//  Created by John Collins on 02/11/2018.
//  Copyright © 2018 전형준John. All rights reserved.
//

#ifndef Red_Black_Tree_h
#define Red_Black_Tree_h
#include "BinaryTree2.h"
#include "BST.h"

void rotate_l(NODE **root, NODE *node);
void rotate_r(NODE **root, NODE *node);
NODE * uncle(NODE *node);
void Initializer_RBT(NODE **root);
int Color(NODE * node);
void Insert_RBT(NODE **root, DATA data);

#endif /* Red_Black_Tree_h */

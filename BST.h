//
//  BST.h
//  Project
//
//  Created by John Collins on 28/10/2018.
//  Copyright © 2018 전형준John. All rights reserved.
//
#ifndef BST_h
#define BST_h
#include <stdlib.h>
#include "BinaryTree2.h"
#include "BST.h"
#include <stdio.h>

void Initializer_BST(NODE **root);

void Insert_BST(NODE **root, DATA data);

NODE * Search_BST(NODE **root, DATA data);
NODE * Search_BST_(NODE **root, DATA data);
NODE * Search_BST_prime(NODE **root, DATA data);

NODE * Successor_BST(NODE **root, DATA data);

NODE * Predessecor_BST(NODE **root, DATA data);

NODE * min_BST(NODE **root);

NODE * max_BST(NODE **root);

NODE * Delete_BST(NODE **root, DATA data);

DATA NEAREST_NEIGHBOR(NODE **root, DATA data);
#endif /* BST_h */

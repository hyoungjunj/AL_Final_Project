//  Red_Black_Tree.c
//  Report2
//
//  Created by John Collins on 02/11/2018.
//  Copyright © 2018 전형준John. All rights reserved.
//

#include "Red_Black_Tree.h"
#include "BinaryTree2.h"
#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

void rotate_l(NODE **root, NODE *node){
    
    NODE * A = node->left;
    NODE * B = node->right->left;
    NODE * C = node->right->right;
    
    DATA temp;
    
    NODE * X = node;
    NODE * Y = node->right;

    temp = Y->data;
    Y->data = X->data;
    X->data = temp;
    temp = Y->color;
    Y->color = X->color;
    X->color = temp;
    
    X->left = Y;
    X->right = C;
    Y->left = A;
    Y->right = B;
    
    if(A!=NULL)
        A->parent = Y;
    if(B!=NULL)
        B->parent = Y;
    if(C!=NULL)
        C->parent = X;
}

void rotate_r(NODE **root, NODE *node){
    NODE * A = node->left->left;
    NODE * B = node->left->right;
    NODE * C = node->right;
    
    DATA temp;
    
    NODE * X = node;
    NODE * Y = node->left;
    
    temp = Y->data;
    Y->data = X->data;
    X->data = temp;
    temp = Y->color;
    Y->color = X->color;
    X->color = temp;
    
    X->left = A;
    X->right = Y;
    Y->left = B;
    Y->right = C;
    
    if(A!=NULL)
        A->parent = X;
    if(B!=NULL)
        B->parent = Y;
    if(C!=NULL)
        C->parent = Y;
}

NODE * uncle(NODE *node){
    
    NODE *uncle;
    
    if(node->parent == NULL)
        return NULL;
    if(node->parent->parent == NULL)
        return NULL;
    else{
        if(node->parent->parent->left == node->parent)
            uncle = node->parent->parent->right;
        else
            uncle = node->parent->parent->left;
        return uncle;
    }
}

void Initializer_RBT(NODE **root){
    *root = NULL;
}

int Color(NODE * node){
    if(node == NULL) return 1;
    else return node->color;
}
void Insert_RBT(NODE **root, DATA data){
    NODE *ptr;
    NODE *target;
    
    Insert_BST(root, data);
    
    ptr = *root;
    
    target = Search_BST(root, data);
    
    if(target->parent != NULL){
        if(target->parent->parent != NULL){
            while(Color(target->parent) == 0){
                if(target->parent == target->parent->parent->left){
                    if(Color(uncle(target)) == 0){
                       // printf("case1\n");
                        target->parent->parent->color = 0;
                        target->parent->color = 1;
                        uncle(target)->color = 1;
                        target = target->parent->parent;
                    }
                    else if((Color(uncle(target)) == 1) && target == target->parent->right){
                      //  printf("case2\n");
                        target = target->parent;
                        rotate_l(root, target);
                        target= target->left;
                        
                        target->parent->parent->color = 0;
                        target->parent->color = 1;
                        rotate_r(root, target->parent->parent);
                        
                        break;
                    }
                    else if(Color(uncle(target)) == 1 && target == target->parent->left){
                      //  printf("case3\n");
                        target->parent->parent->color = 0;
                        target->parent->color = 1;
                        rotate_r(root, target->parent->parent);
                        
                        break;
                    }
                    
                }
                else{
                    if(Color(uncle(target)) == 0){
                       // printf("case1\n");
                        target->parent->parent->color = 0;
                        target->parent->color = 1;
                        uncle(target)->color = 1;
                        target = target->parent->parent;
                    }
                    else if(Color(uncle(target)) == 1 && target == target->parent->left){
                       // printf("case2\n");
                        target = target->parent;
                        rotate_r(root, target);
                        target = target->right;
                        
                        target->parent->parent->color = 0;
                        target->parent->color = 1;
                        rotate_l(root, target->parent->parent);
                        
                        break;
                        
                    }
                    else if(Color(uncle(target)) == 1 && target == target->parent->right){
                       // printf("case3\n");
                        target->parent->parent->color = 0;
                        target->parent->color = 1;
                        rotate_l(root, target->parent->parent);
                        
                        break;
                    }
                    
                }
                
            }
        }
    }
    
    ptr->color = 1;
}

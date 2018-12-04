//
//  BST.c
//  Project
//
//  Created by John Collins on 28/10/2018.
//  Copyright © 2018 전형준John. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"
#include "BST.h"

void Initializer_BST(NODE **root){
    *root = NULL;
}

void Insert_BST(NODE **root, DATA data){ //duplicate is not allowed..
    NODE *ptr = *root;
    NODE *new_node = makeNODE(data);
    
    if(ptr == NULL){
        *root = new_node;
    }
    else{
        while(1){
            if(new_node->data > ptr->data){
                if(ptr->right == NULL){
                    LinkRight(ptr, new_node);
                    LinkParent(ptr, new_node);
                    break;
                }
                else ptr = ptr->right;
            }
            else if(new_node->data < ptr->data){
                if(ptr->left == NULL){
                    LinkLeft(ptr, new_node);
                    LinkParent(ptr, new_node);
                    break;
                }
                else ptr = ptr->left;
            }
            else if(new_node->data == ptr->data){
                printf("\nYou cannot insert this value!\n");
                break;
            }
        }
    }
}

NODE * Search_BST_prime(NODE **root, DATA data){ //search nearest values
    NODE *ptr = *root;
    while(1){
        if(data == ptr->data) return ptr;
        else if(data > ptr->data){
            if(ptr->right == NULL){
                return ptr;
                break;
            }
            else ptr = ptr->right;
        }
        else if(data < ptr->data){
            if(ptr->left == NULL){
                return ptr;
                break;
            }
            else ptr = ptr->left;
        }
    }
    //return ptr;
}

NODE * Search_BST_(NODE **root, DATA data){
    NODE *ptr = *root;
    while(1){
        printf("\nSearching... visited [%d] \n",ptr->data);
        if(data == ptr->data) return ptr;
        else if(data > ptr->data){
            if(ptr->right == NULL){
                return NULL;
                break;
            }
            else ptr = ptr->right;
        }
        else if(data < ptr->data){
            if(ptr->left == NULL){
                return NULL;
                break;
            }
            else ptr = ptr->left;
        }
    }
    printf("\n");
    //return ptr;
}

NODE * Search_BST(NODE **root, DATA data){
    NODE *ptr = *root;
    while(1){
        if(data == ptr->data) return ptr;
        else if(data > ptr->data){
            if(ptr->right == NULL){
                return NULL;
                break;
            }
            else ptr = ptr->right;
        }
        else if(data < ptr->data){
            if(ptr->left == NULL){
                return NULL;
                break;
            }
            else ptr = ptr->left;
        }
    }
    //return ptr;
}

NODE * Successor_BST(NODE **root, DATA data){
    NODE *node = Search_BST(root, data);
    NODE *p = node->parent; NODE *cur = node; NODE *ret;
    if(node->right != NULL) ret = min_BST(&(node->right));
    else if(node->parent != NULL){
        if(node->parent->left == node){
            ret = node->parent;
        }
        else if(node->parent->right == node){
            while(p->left != cur && p->parent != NULL){
                p = p->parent;
                cur = cur->parent;
            }
            if(p->left != cur && p->parent == NULL) ret = node;
            else ret = p;
        }
    }
    else if(node->parent == NULL){
        ret = node;
    }
    return ret;
}

NODE * Predessecor_BST(NODE **root, DATA data){
    NODE *node = Search_BST(root, data);
    NODE *p = node->parent; NODE *cur = node; NODE *ret;
    if(node->left != NULL) ret = max_BST(&(node->left));
    else if(node->parent != NULL){
        if(node->parent->right == node){
            ret = node->parent;
        }
        else if(node->parent->left == node){
            while(p->right != cur && p->parent != NULL){
                p = p->parent;
                cur = cur->parent;
            }
            if(p->right != cur && p->parent == NULL) ret = node;
            else ret = p;
        }
    }
    else if(node->parent == NULL){
        ret = node;
    }
    return ret;
}

NODE * min_BST(NODE **root){
    NODE *ptr = *root;
    while(ptr->left !=NULL){
        ptr = ptr->left;
    }
    return ptr;
}

NODE * max_BST(NODE **root){
    NODE *ptr = *root;
    while(ptr->right !=NULL){
        ptr = ptr->right;
    }
    return ptr;
}

NODE* Delete_BST(NODE **root, DATA data){
    
    NODE *target = Search_BST(root, data);
    NODE * ret;
    
    if(target == NULL) ret = NULL;
    else{
    //case 1_leaf node
    if(target->left==NULL && target->right==NULL){
        //printf("case1\n");
        if(target == *root) {}
        else if(target->parent->left==target) target->parent->left = NULL;
        else if(target->parent->right==target) target->parent->right= NULL;
        ret = NULL;
        //free(target);
    }
    //case 2
    else if((target->left==NULL || target->right==NULL) && target != *root){
        //printf("case2\n");
        if(target->parent->left == target){
            if(target->left != NULL){
                target->parent->left = target->left;
                target->left->parent = target->parent;
            }
            else{
                target->parent->left = target->right;
                target->right->parent = target->parent;
            }
        }
        else if(target->parent->right == target){
            if(target->left != NULL){
                target->parent->right = target->left;
                target->left->parent = target->right;
            }
            else{
                target->parent->right = target->right;
                target->right->parent = target->parent;
            }
        }
        
        if(target->left == NULL && target->right == NULL) ret = NULL;
        else if(target->left != NULL && target->right == NULL) ret = target->left;
        else if(target->left == NULL && target->right != NULL) ret = target->right;
        
        //free(target);
    }
    //fucking case
    else if((target->left!=NULL && target->right!=NULL) || target == *root){
       // printf("fucking case\n");
        NODE * delNode = Successor_BST(root, target->data);
        if(delNode->data == target->data){
            delNode = Predessecor_BST(root, target->data);
        }
        DATA delNode_data = delNode->data;
        Delete_BST(root,delNode->data);
        target->data = delNode_data;
        //free(target);
    }
        //free(target);
    }
    
    return ret;
}

DATA NEAREST_NEIGHBOR(NODE **root, DATA data){
    NODE * target = Search_BST_prime(root, data);
    DATA suc, pred, search_prime;
    DATA num1, num2, num3, ret;

    suc = Successor_BST(root, target->data)->data;
    pred = Predessecor_BST(root, target->data)->data;
    search_prime = target->data;
    
    num1 = data - suc;
    num2 = data - pred;
    num3 = data - search_prime;
    if(num1<0) num1 = -num1;
    if(num2<0) num1 = -num2;
    if(num3<0) num1 = -num3;
    
    ret = num1;
    if(num2<num1) ret = num2;
    if(num3<ret) ret = num3;
    
    if(num1 == ret) ret = suc;
    else if(num2 == ret) ret = pred;
    else if(num3 == ret) ret = search_prime;
    
    return ret;
}

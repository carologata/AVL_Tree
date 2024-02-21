#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree_node {
    int data;
    int height;
    struct s_tree_node* right;
    struct s_tree_node* left;
} t_tree_node;

t_tree_node* createNode(int data);
int maxDepth(t_tree_node* n);
void printTree(t_tree_node* n);
void	insert_tree_node(t_tree_node **root, int data);


#endif
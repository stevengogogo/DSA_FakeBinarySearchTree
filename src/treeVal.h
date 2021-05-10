#ifndef TREEVAL_H
#define TREEVAL_H


#include <stdio.h> //NULL
#include <stdlib.h> //malloc
#include "utils.h"

#define INT_MIN -2147483647
#define INT_MAX 2147483647

typedef struct Node{
    int key;
    struct Node* leaf[2];
} Node;

typedef struct {
    Node* nodes;
    int n;
} problem;


problem init_problem(int N_nodes);
void kill_problem(problem);

void CreateNodes(problem, int ID, int key, int IDleft, int IDright);


void valid_tree_walk(Node* node, int* n, int min, int max);

void interface(void);

#endif
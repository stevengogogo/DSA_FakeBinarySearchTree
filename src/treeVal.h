#ifndef TREEVAL_H
#define TREEVAL_H


#include <stdio.h> //NULL
#include <stdlib.h> //malloc
#include "utils.h"

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


int valid_tree_walk(Node* node);

void interface(void);

#endif
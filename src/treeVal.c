#include "treeVal.h"


problem init_problem(int N_nodes){
    problem prob;
    prob.n = N_nodes;
    prob.nodes = (Node*)malloc(MAX_N*sizeof(Node));
    return prob;
}

void kill_problem(problem prob){
    free(prob.nodes);
}

void CreateNodes(problem prob, int ID, int key, int IDleft, int IDright){
    Node* node = &prob.nodes[ID];
    node->key = key;


    if (IDleft!=-1)
        node->leaf[0] = &prob.nodes[IDleft];
    else
        node->leaf[0] = NULL;

    if(IDright!=-1)
        node->leaf[1] = &prob.nodes[IDright];
    else 
        node->leaf[1] = NULL;
}


void valid_tree_walk(Node* node, int* n, int min, int max){

    Node* l = node->leaf[0];
    Node* r = node->leaf[1];
    int key = node->key;

    if(node!=NULL)
        *n += 1;

    if (l!=NULL){
        if(key > l->key && l->key > min)
            valid_tree_walk(l, n, min,key);
    }

    if (r!=NULL){
        if(key < r->key && r->key < max)
            valid_tree_walk(r, n, key, max);
    }

    return;
}


void interface(void){
    int N_nodes;
    int key, IDleft, IDright;
    int N_reach;

    scanf("%d", &N_nodes);

    problem prob = init_problem(N_nodes);

    for(int i=1; i<=N_nodes;i++){
        scanf("%d", &key);
        scanf("%d", &IDleft);
        scanf("%d", &IDright);

        CreateNodes(prob, i, key, IDleft, IDright);
    }

    N_reach=0;
    valid_tree_walk(&prob.nodes[1], &N_reach, INT_MIN, INT_MAX);

    printf("%d", N_reach);

    kill_problem(prob);
}
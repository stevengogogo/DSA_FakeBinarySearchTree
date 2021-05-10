#include "treeVal.h"


problem init_problem(int N_nodes){
    problem prob;
    prob.n = N_nodes;
    prob.nodes = (Node*)malloc((N_nodes+1)*sizeof(Node));
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

    if(node!=NULL)
        *n += 1;

    if (node->leaf[0]!=NULL){
        if(node->key >node->leaf[0]->key && node->leaf[0]->key > min)
            valid_tree_walk(node->leaf[0], n, min,node->key);
    }

    if (node->leaf[1]!=NULL){
        if(node->key < node->leaf[1]->key && node->leaf[1]->key < max)
            valid_tree_walk(node->leaf[1], n, node->key, max);
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
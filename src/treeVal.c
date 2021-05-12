#include "treeVal.h"


problem init_problem(int N_nodes){
    problem prob;
    prob.n = N_nodes;
    int N = N_nodes+30;
    prob.nodes = (Node*)malloc(N*sizeof(Node));

    //Initialize node
    for(int i=0;i<N;i++){
        prob.nodes[i].parent = NULL;
        prob.nodes[i].leaf[0] = NULL;
        prob.nodes[i].leaf[1] = NULL;
        prob.nodes[i].visited = 0;
    }

    return prob;
}

void kill_problem(problem prob){
    free(prob.nodes);
}

void CreateNodes(problem prob, int ID, int key, int IDleft, int IDright){
    Node* node = &prob.nodes[ID];
    node->key = key;
    node->visited=0;

    if (IDleft!=-1){
        node->leaf[0] = &prob.nodes[IDleft];
        prob.nodes[IDleft].parent = node;
    }
    else
        node->leaf[0] = NULL;

    if(IDright!=-1){
        node->leaf[1] = &prob.nodes[IDright];
        prob.nodes[IDleft].parent = node;
    }
    else 
        node->leaf[1] = NULL;
}


int findOrigin(Node* node){
    if(node->parent == NULL){
        return -1;
    }
    else if(node->parent->leaf[0] == node){
        return 0;
    }
    else if(node->parent->leaf[1] == node){
        return 1;
    }
    else{
        return -1;
    }
}


int valid_tree_walk(Node* node){

    Node* l = node->leaf[0];
    Node* r = node->leaf[1];
    Node* p = node->parent;
    int dir = findOrigin(node);
    int key = node->key;
    int n = 0;
    int valid=0;
    node->visited = 1;

    
    //check validity
    if (node->parent != NULL){
        if (dir==0){
            if(node->parent->key > node->key)
                valid = 1;
        }
        if(dir ==1){ // comes from right
            if(node->parent->key < node->key)
                valid = 1;
         }
    }

    if(dir==-1 && node->parent==NULL){
        valid=1;
    }

    //include if vlid
    if(valid==1){
        n = 1;
    }




    if (r!=NULL){
       if( dir==0 && valid==0 ){
            //Do nothing
        } 
        else{
            n+=valid_tree_walk(r);
        }
    }

    if (l!=NULL){
        if( dir==1 && valid==0 ){
            //Do nothing
        } 
        else{
            n+=valid_tree_walk(l);
        }
    }

    return n;
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

    if(&prob.nodes[1]==NULL){
        N_reach = 0;
    }
    else{
        N_reach = valid_tree_walk(&prob.nodes[1]);
    }

    printf("%d", N_reach);

    kill_problem(prob);
}

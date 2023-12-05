#include "albero_binario.h"
#include <fstream>

int main(int argc, char ** argv){
    albero tree;
    albero_init(tree);
    fstream input;
    input.open(argv[1],ios::in);
    int n;

    while(!input.eof()){
        input >> n;
        node *nuovo_nodo = new node{n,NULL,NULL};
        albero_insert_rec(tree,nuovo_nodo);
        // albero_insert(tree,n);
    }
    stampaAlbero(tree);

    albero_dealloca(tree);
    input.close();
    return 0;
}
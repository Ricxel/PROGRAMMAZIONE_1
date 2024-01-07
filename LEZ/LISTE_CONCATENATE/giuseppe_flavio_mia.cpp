#include <iostream>
#include <cstdlib>
using namespace std;

struct list{
    int info;
    list *next;
};

void stampa_lista(list * root){
    if(root != NULL){
        cout << root->info << " ";
        stampa_lista(root->next);
    }
}
int main(int argc, char **argv){
    //0) Salvare N
    if(argc != 3){
        cout << "Parametri errati" << endl;
        return -1;
    }
    const int N = atoi(argv[1]);
    const int M = atoi(argv[2]);
    //1) Creare la list concatenata circolare
    //inserisco il primo nodo
    list * root = new list{1, NULL};
    list * p = root;

    //metto gli altri
    for(int i = 2; i <= N; i++){
        p->next = new list{i, NULL};
        p = p->next;
    }
    //metto nel next dell'ultimo elemento il primo
    p->next = root;

    //2) inizio a eliminare
    p = root;
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < M-1; j++){
            p = p->next;
        }
        //devo cancellare p->next
        list *canc = p->next;
        p->next = canc->next;
        delete canc;
        p = p->next;
    }
    const int ris = p->info;
    delete p;
    cout << "Il vincitore è: " << ris << endl;
    return 0;
}
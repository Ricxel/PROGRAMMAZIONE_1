#include <iostream>
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
void inizializza_lista_aux(list * &l, int i, int N){
    if(i <= N){  
        if(l == NULL){
            l = new list{i,NULL};
        }
        else l->next = new list{i, NULL};
        inizializza_lista_aux(l->next, i+1, N);
    }
}
list * fine(list *l){
    if(l != NULL && l->next != NULL){
        return fine(l->next);
    }
    else return l;
}
void inizializza_lista(list * &l, int i, int N){
    inizializza_lista_aux(l, i, N);
    list *p = fine(l);
    p->next = l;

}
//fa la conta per rimuovere l'M-esimo nodo
list * rimuovi_nodo(list * l, int M){
    if(M > 1){
        return rimuovi_nodo(l->next, M-1);
    }
    else{
        //devo rimuovre l->next e ricollegare al nodo successinvo
        list *canc = l->next;
        l->next = canc->next;
        delete canc;
        return l->next;
    }
}
// caso particolare M = 0 non gestito
int trova_vincitore(list * l, int M){
    if(l == NULL){
        return -1;
    }
    if(l != l->next){
        l = rimuovi_nodo(l, M);
        cout << l->info << " ";
        return trova_vincitore(l, M);
    }
    else{
        int vinc = l->info;
        delete l;
        return vinc;
    }

}
int main(int argc, char **argv){
    if(argc != 3){
        cout << "Parametri non corretti" << endl;
        return -1;
    }
    //inizializzazione della lista
    const int N = atoi(argv[1]);
    const int M = atoi(argv[2]);

    list *root = NULL;
    inizializza_lista(root, 1, N);

    //rimozione
    int vincitore = trova_vincitore(root,M);
    cout << "Vincitore: " << vincitore << endl;

    return 0;
}
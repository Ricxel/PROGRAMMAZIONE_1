using namespace std;
#include <iostream>
#include <fstream>

struct nodo{
    int valore;
    nodo * next;
};
bool init(nodo * &, char *);
void stampa_lista(nodo *);
void distruggi_lista(nodo * &);
void stampaListaInvertita(nodo *);
int main(int argc, char ** argv){

    if(argc != 2){
        cout << "Parametri non corretti" << endl;
        return -1;
    }
    nodo * lista = new nodo;
    init(lista,argv[1]);

    // cout << lista->valore << endl;
    // cout << lista->next->valore << endl;

    stampa_lista(lista);
    cout << "----INVERTITA----" << endl;
    stampaListaInvertita(lista);
    distruggi_lista(lista);
    return 0;
}
bool init(nodo * &list, char * filename){
    fstream in;
    in.open(filename,ios::in);
    if(in.fail()){
        return false;
    }

    nodo * n = list;
    while(!in.eof() && !in.fail()){
        char val[30];
        in >> val;
        n->valore = atoi(val);
        if(in.eof()){
            n->next == NULL;
            break;
        }
        else{
            n->next = new nodo;
            n = n->next;
        }
    }
    in.close();
    return true;
}
void stampa_lista(nodo *n){
    while(n != NULL){
        cout << n->valore << endl;
        n = n->next;
    }
}
void distruggi_lista(nodo * &lista){
    //controllo se la lista è vuota
    if(lista == NULL){
        return;
    }
    //creo un nodo per scorrere la lista
    nodo *n = lista;
    int i = 0; //indice per vedere se la lista ha più di un elemento
    do
    {
        n = lista;
        nodo * penultimo;
        i = 0; //per controllare quando non ci sono più elementi

        while(n->next != NULL){ //ciclo per trovare ultimo e penultimo
            if(n->next->next == NULL){
                penultimo = n;
            }
            n = n->next;
            i++;
        }
        penultimo->next = NULL; //assegno null al next del penultimo nodo
        delete n; //cancello l'ultimo nodo
    } while (i > 0);
}
void stampa_inv_rec(nodo *n){
    if(n->next == NULL){
        cout << n->valore << endl;
        return;
    }
    stampa_inv_rec(n->next);
    cout << n->valore << endl;
}
void stampaListaInvertita(nodo *lista){
    if(lista == NULL){
        cout << "La lista è vuota" << endl;
        return;
    }
    stampa_inv_rec(lista);
}
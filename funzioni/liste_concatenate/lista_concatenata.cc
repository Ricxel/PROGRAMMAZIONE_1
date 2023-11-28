#include "lista_concatenata.h"

nodo * crea_lista(char * inputFile) {

    fstream input;
    nodo * listaDiNumeri = NULL;
    input.open(inputFile, ios::in);

    if (input.fail()) {
        cout << "Errore in lettura" << endl;
    }
    else {
        int numero;
        input >> numero;
        listaDiNumeri = new nodo{numero, NULL};
        nodo* nodoCorrente = listaDiNumeri;

        while(input >> numero) {
            nodo* nuovoNodo = new nodo{numero, NULL};
            nodoCorrente->next = nuovoNodo;
            nodoCorrente = nuovoNodo;
        }
    }

    input.close();

    return listaDiNumeri;
}
void crea_lista_rec(nodo * lista){

}

int len(nodo *lista){
    int cont = 0;
    while(lista != NULL){
        cont++;
        lista = lista->next;
    }
    return cont;
}
int len_rec(nodo *lista){
    if(lista == NULL){
        return 0;
    }
    return 1+len(lista->next);
}


void stampa_lista(nodo * listaDiNumeri) {
    while (listaDiNumeri != NULL) {
        cout << listaDiNumeri->value << " ";
        listaDiNumeri = listaDiNumeri->next;
    }
    cout << endl;
}
void stampa_lista_rec(nodo * lista){
    if(lista == NULL){
        return;
    }
    cout << lista->value << " ";
    stampa_lista(lista->next);
}


void distruggi_lista(nodo * lista) {
    nodo* prossimoNodo;
    while (prossimoNodo != NULL) {
        prossimoNodo = lista->next;
        delete lista;
        lista = prossimoNodo;
    }
}
void distruggi_lista_rec(nodo * lista){
    if(lista == NULL){
        return;
    }
    nodo *prossimo_nodo = lista->next;
    delete lista;
    distruggi_lista_rec(prossimo_nodo);
}

void inserisci_testa(nodo * &lista, int numero){
    nodo *n = new nodo{numero, NULL};
    n->next = lista;
    lista = n;
}

void inserisci_coda(nodo * &lista, int numero){
    nodo *n = new nodo{numero,NULL};
    if(lista == NULL){
        lista = n;
    }
    else{
        nodo *l = lista;
        while(l->next != NULL)
            l = l->next;
        l->next = n;
    }
}
void aggiungi_nodo(nodo *lista, nodo *nuovo_nodo){
    if(lista->next == NULL){
        lista->next = nuovo_nodo;
        return;
    }
    aggiungi_nodo(lista->next, nuovo_nodo);
}
void inserisci_coda_rec(nodo * &lista, int numero){
    nodo *n = new nodo{numero, NULL};
    if(lista == NULL){
        lista = n;
    }
    else{
        aggiungi_nodo(lista,n);
    }
}

void rimuovi(nodo * &primo_nodo, int numero){
    if(primo_nodo == NULL)
        return;
    nodo *nodo_da_cancellare;

    //controllo il primo elemento
    if(primo_nodo->value == numero){
        nodo_da_cancellare = primo_nodo;
        primo_nodo = primo_nodo->next;
        delete nodo_da_cancellare;
        return;
    }

    nodo *lista = primo_nodo; 
    while(lista->next != NULL && lista->next->value != numero){
        lista = lista->next;
    }
    nodo_da_cancellare = lista->next;

    if(nodo_da_cancellare != NULL){
        if(nodo_da_cancellare->next != NULL){
            lista->next = nodo_da_cancellare->next;
            delete nodo_da_cancellare;
        }
        else {
            delete nodo_da_cancellare;
            lista->next = NULL;
        }
    }
    //else l'elemento non esiste

}
nodo * trova_nodo(nodo *lista, int target){
    if(lista->next == NULL || lista->next->value == target){
        return lista;
    }
    return trova_nodo(lista->next, target);
}
void rimuovi_rec(nodo * &primo_nodo, int numero){
    if(primo_nodo == NULL){
        return;
    }
    nodo *nodo_da_cancellare;
    if(primo_nodo->value == numero){
        nodo_da_cancellare = primo_nodo;
        primo_nodo = primo_nodo->next;
        delete nodo_da_cancellare;
        return;
    }
    //trovo il nodo prima di quello che ha il valore da trovare
    nodo *lista = trova_nodo(primo_nodo, numero);
    nodo_da_cancellare = lista->next; //assegno a una variabile il nodo da eliminare

    //se non è null (e quindi il valore è stato trovato)
    if(nodo_da_cancellare != NULL){
        //se NON è l'ultimo della lista
        if(nodo_da_cancellare->next != NULL){
            lista->next = nodo_da_cancellare->next; //al next del nodo precedente assegno il nodo successivo
            delete nodo_da_cancellare; // e poi cancello il nodo da cancellare
        }
        else {
            //altrimenti, il nodo da cancellare è l'ultimo, quindi assegno al penultimo next il valore null e poi elimino il nodo
            delete nodo_da_cancellare; 
            lista->next = NULL;
        }
    }
}

void remove_first(nodo * &lista){
    if(lista == NULL){
        //lista vuota
        return;
    }
    nodo *nodo_da_cancellare = lista;
    lista = lista->next;
    delete nodo_da_cancellare;
}

void remove_last(nodo * &first){
    if(first == NULL){
        return; //lista vuota
    }
    if(first->next == NULL){
        delete first;
        first = NULL;
    }
    else{
        nodo *lista = first;
        nodo *prev = lista;
        while(lista->next != NULL){
            prev = lista;
            lista = lista->next;
        }
        prev->next = NULL;
        delete lista;
    }
}
void scorri(nodo * &lista, nodo * &prev){
    if(lista->next == NULL){
        return;
    }
    prev = lista;
    lista = lista->next;
    scorri(lista,prev);
}
void remove_last_rec(nodo * &first){
    if(first == NULL){
        return; //lista vuota
    }
    if(first->next == NULL){
        delete first;
        first = NULL;
    }
    else{
        nodo *lista = first;
        nodo *prev = lista;
        scorri(lista,prev);
        prev->next = NULL;
        delete lista;
    }
}

void insert_at(nodo * &primo, int numero, int indice){
    nodo *nuovo_nodo = new nodo{numero, NULL};
    if(primo == NULL){
        primo = nuovo_nodo;
        return;
    }
    if(indice == 0){
        nuovo_nodo->next = primo;
        primo = nuovo_nodo;
        return;
    }
    nodo *lista = primo;
    nodo *prev = lista;
    int i = 0;
    while(i < indice && lista->next != NULL){
        prev = lista;
        lista = lista->next;
        i++;
    }
    prev->next = nuovo_nodo;
    nuovo_nodo->next = lista;
}
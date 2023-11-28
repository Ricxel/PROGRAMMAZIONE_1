using namespace std;
#include <fstream>
#include <iostream>

struct nodo{
    int value;
    nodo *next;
};

nodo * crea_lista(char *);
nodo * crea_lista_rec(char *);

int len(nodo *);
int len_rec(nodo *);

void stampa_lista(nodo *);
void stampa_lista_rec(nodo *);

void distruggi_lista(nodo *lista);
void distruggi_lista_rec(nodo *lista);

void inserisci_testa(nodo * &, int);

void inserisci_coda(nodo * &, int);
void inserisci_coda_rec(nodo * &, int);

void rimuovi(nodo * &, int);
void rimuovi_rec(nodo * &, int);

void remove_first(nodo * &);

void remove_last(nodo * &);
void remove_last_rec(nodo * &);

void insert_at(nodo * &, int, int);
#include <iostream>
#include "coda/coda.h"
using namespace std;
struct node;
typedef node * albero;
struct node{
    int value;
    albero left;
    albero right;
};

void albero_init(albero &);
void albero_insert(albero & tree, int n);
void albero_stampa_crescente(albero tree);
void albero_ricerca(albero tree, int target);
// si invoca "stampaAlbero(radice);"
void stampaAlbero(albero radice, int spazio=0);

void albero_insert_rec(albero & tree, node *);
node* albero_ricerca_rec(albero & radice, int target);
void albero_dealloca(albero radice);

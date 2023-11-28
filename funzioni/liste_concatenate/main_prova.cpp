#include "lista_concatenata.h"
using namespace std;

int main(int argc, char ** argv){
    nodo *lista;
    lista = crea_lista(argv[1]);
    //lista = NULL;
    stampa_lista_rec(lista);
    int leng = len_rec(lista);
    cout << "Lunghezza: " << leng << endl; 

    // rimuovi_rec(lista,atoi(argv[2]));
    insert_at(lista, 678, 0);
    stampa_lista_rec(lista);

    distruggi_lista(lista);
    return 0;
}
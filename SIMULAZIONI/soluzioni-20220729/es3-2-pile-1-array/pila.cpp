#include "pila_1.h"
#include <iostream>
using namespace std;
// inizializza P1 e P2 con un'array o una lista 
// doppiamente concatenata con dimensione massima 
// 'dim'. Di conseguenza, la somma del numero di 
// elementi in P1 e P2 può essere al massimo uguale 
// a 'dim';
static const int DIM = 10;
static int s[DIM];
static int indiceS1;
static int indiceS2;
void init(int dim){
    indiceS1 = -1;
    indiceS2 = DIM;
}

// inserisci l'elemento 'valore' in P1
bool pushP1(int valore){
    int dimS1 = indiceS1 + 1;
    int dimS2 = DIM - indiceS2;
    bool ris = false;

    if(dimS1 + dimS2 != DIM){
        indiceS1++;
        s[indiceS1] = valore;
        ris = true;
    }
    return ris;
}

// inserisci l'elemento 'valore' in P2
bool pushP2(int valore){
    int dimS1 = indiceS1 + 1;
    int dimS2 = DIM - indiceS2;
    bool ris = false;

    if(dimS1 + dimS2 != DIM){
        indiceS2--;
        s[indiceS2] = valore;
        ris = true;
    }
    return ris;
}

// assegna al parametro il valore del primo 
// elemento di P1, se presente
bool topP1(int &value){
    bool ris = false;
    if(indiceS1 != -1){
        value = s[indiceS1];
        ris = true;
    }
    return ris;
}

// assegna al parametro il valore del primo 
// elemento di P2, se presente
bool topP2(int &value){
    bool ris = false;
    if(indiceS2 != DIM){
        value = s[indiceS2];
        ris = true;
    }
    return ris;
}

// rimuovi il primo elemento di P1, se presente
bool popP1(){
    bool ris = false;
    if(indiceS1 != -1){
        indiceS1--;
        ris = true;
    }
    return ris;
}

// rimuovi il primo elemento di P2, se presente
bool popP2(){
    bool ris = false;
    if(indiceS2 != DIM){
        indiceS2++;
        ris = true;
    }
    return ris;
}

// de-inizializza la pila e dealloca la memoria dinamica
void deinit(){
    return;
}

// stampa a video gli elementi di P1 e P2
void print(){
    cout << "S1: ";
    for(int i = indiceS1; i >= 0; i--){
        cout << s[i] << ' ';
    }
    cout << endl;

    cout << "S2: ";
    for(int i = indiceS2; i < DIM; i++){
        cout << s[i] << ' ';
    }
    cout << endl;
}

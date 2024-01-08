// Inserisci qui il codice implementazione delle funzioni in coda.h
#include "coda.h"
#include <iostream>
using namespace std;

static const int DIM = 11;
static int *c;
static int indiceS1;
static int indiceS2;

void init(){
    c = new int[DIM];
    indiceS1 = -1;
    indiceS2 = DIM;
}

bool enqueue(int code){
    int dimS1 = indiceS1 + 1;
    int dimS2 = DIM - indiceS2;
    if(dimS1 + dimS2 == DIM){
        return false;
    }
    if(dimS1 <= dimS2){
        indiceS1++;
        c[indiceS1] = code;
    }
    else{
        indiceS2--;
        c[indiceS2] = code;
    }
    return true;
}
bool firstS1(int &n){
    if(indiceS1 != -1){
        n = c[0];
        return true;
    }
    else{
        n = -1;
        return false;
    }
}
bool firstS2(int &n){
    if(indiceS2 != DIM){
        n = c[DIM-1];
        return true;
    }
    else{
        n = -1;
        return false;
    }
}
bool dequeueS1(){
    if(indiceS1 == -1){
        return false;
    }
    for(int i = 0; i < indiceS1; i++){
        c[i] = c[i+1];
    }
    indiceS1--;
    return true;
}
bool dequeueS2(){
    if(indiceS2 == DIM){
        return false;
    }
    for(int i = DIM-1; i > indiceS2; i--){
        c[i] = c[i-1];
    }
    indiceS2++;
    return true;
}
void deinit(){
    return;
}
void print(){
    cout << "S1: ";
    if(indiceS1 == -1)
        cout << "Vuota";
    else
        for(int i = 0; i <= indiceS1; i++)
            cout << c[i] << " ";
    cout << endl;
    cout << "S2: ";
    if(indiceS2 == DIM)
        cout << "Vuota";
    else   
        for(int i = DIM-1; i >= indiceS2; i--)
            cout << c[i] << " ";
    cout << endl;
}
// Inserisci qui il codice implementazione delle funzioni in coda.h
#include "coda.h"
#include <iostream>
using namespace std;

static const int DIM = 11;
static int v[DIM];
static int indiceS1;
static int indiceS2;

void init(){
    indiceS1 = -1;
    indiceS2 = DIM;
}
bool enqueue(int n){
    int dimS1 = indiceS1 + 1;
    int dimS2 = DIM - indiceS2;

    if(dimS1 + dimS2 == DIM)
        return false;
    if(dimS1 < dimS2){
        //inserisco in S1
        indiceS1++;
        v[indiceS1] = n;
    }
    else{
        indiceS2--;
        v[indiceS2] = n;
    }
    return true;
}
bool firstS1(int &n){
    if(indiceS1 + 1 > 0){
        n = v[0];
        return true;
    }
    return false;
}
bool firstS2(int &n){
    if(DIM - indiceS2 > 0){
        n = v[DIM-1];
        return true;
    }
    return false;
}
bool dequeueS1(){
    if(indiceS1 + 1 > 0){
        for(int i = 0; i < indiceS1; i++){
            v[i] = v[i+1];
        } 
        indiceS1--;
        return true;
    }
    return false;
}
bool dequeueS2(){
    if(DIM - indiceS2 > 0){
        for(int i = DIM-1; i > indiceS2; i--){
            v[i] = v[i-1];
        }
        indiceS2++;
        return true;
    }
    return false;
}
void deinit(){
    return;
}
void print(){
    cout << "S1: ";
    if(indiceS1 != -1){
        for(int i = 0; i <= indiceS1; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else cout << "Vuota" << endl;
   
    
    cout << "S2: ";
    if(indiceS2 != DIM){
        for(int i = DIM-1; i >= indiceS2; i--){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else cout << "Vuota" << endl;
}
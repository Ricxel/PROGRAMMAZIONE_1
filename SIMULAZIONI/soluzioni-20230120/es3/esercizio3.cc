#include <iostream>
#include "pila.h"

using namespace std;

int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti);

int main() {
    
    // Potete modificare l'array di asteroidi (e la sua
    // dimensione) per testare la vostra soluzione
    int asteroidi [] = {-6, 10, 5, 8, -9,5,-9,-3,9,-2,5};
    int numeroAsteroidi = 11;


    int numeroAsteroidiRimasti;
    int * asteroidiRimasti = collidiAsteroidi(asteroidi, numeroAsteroidi, numeroAsteroidiRimasti);


    // La stampa dell'array dinamico degli
    // asteroidi rimasti avviene nel main
    cout << "Risultato: ";
    for (int i = 0; i < numeroAsteroidiRimasti ; i++) {
        cout << asteroidiRimasti[i] << " ";
    }
    cout << endl;

    // La deallocazione dell'array dinamico 
    // degli asteroidi rimasti avviene nel main
    delete[] asteroidiRimasti;
}


// Implementare la funzione sottostante come da consegna:
// - ritornare un'array di interi allocato dinamicamente che 
//   contenga lo stato degli asteroidi dopo tutte le collisioni
// - assegnare a 'numeroAsteroidiRimasti' il numero di elementi 
//   nell'array ritornato
int * collidiAsteroidi(int asteroidi[], int numeroAsteroidi, int & numeroAsteroidiRimasti) {
    init();
    int a,b;
    bool cambiamento = true;
    numeroAsteroidiRimasti = numeroAsteroidi;
    int *v = new int[numeroAsteroidi];
    
    for(int i = 0; i < numeroAsteroidi; i++){
        v[i] = asteroidi[i];
    }


    while(cambiamento){
        cout << "GIROOO" << endl;
        cout << "-------"<<endl;
        for(int i = 0; i < numeroAsteroidiRimasti; i++){
            cout << v[i] << " ";
        }
        cout << endl << "---------" << endl;
        cambiamento = false;
        int lim = numeroAsteroidiRimasti;
        for(int i = 0; i < lim; i++){
            if(vuota()){
                push(v[i]);
            }
            else{
                top(a);
                b = v[i];

                cout << "a: " << a << endl << "b: " << b << endl;
                if(b < 0 && a > 0){
                    if(b*-1 > a){
                        pop();numeroAsteroidiRimasti--;
                        push(b);
                    }
                    else if(b*-1 == a){
                        pop();
                        numeroAsteroidiRimasti -= 2;
                    }
                    else{
                        numeroAsteroidiRimasti--;
                    }
                    cambiamento = true;
                }
                else{
                    cout << "pusho " << b << endl;
                    push(b);
                }

            }
        }
        delete[] v;
        v = new int[numeroAsteroidiRimasti];
        for(int i = numeroAsteroidiRimasti-1; i >= 0; i--){
            top(a);
            pop();
            v[i] = a;
        }
    }
    //riempio l'array
    
    deinit();
    return v;
}

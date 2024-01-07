#include <iostream>
#include <cstdlib>
#include "coda.h"

using namespace std;

int trovaIlVincitore(int n, int k);

int main(int argc, char * argv[]) {

    if (argc != 3) {
        cerr << "Usage: a./out <numeroDiAmici> <numeroDiSalti>" << endl;
        exit(0);
    }

    cout << "Il vincitore e' l'amico numero " << trovaIlVincitore(atoi(argv[1]), atoi(argv[2])) << endl;
}


// Implementare la funzione sottostante come da consegna:
// - 'numeroDiAmici' è il numero di amici, o anche chiamato 'n'
// - 'numeroDiSalti' è il numero di salti, o anche chiamato 'k' 
int trovaIlVincitore(int numeroDiAmici, int numeroDiSalti) {
    init();
    for(int i = 1; i <= numeroDiAmici; i++){
        enqueue(i);
    }
    // print();
    int n;
    //ripeto per amici-1 volte cosi ne rimane solo uno
    for(int i = 0; i < numeroDiAmici-1; i++){
        //faccio i salti
        for(int i = 0; i < numeroDiSalti; i++){
            first(n);
            dequeue();
            enqueue(n);
        }
        //elimino quello a cui sono arrivato
        dequeue();
        // cout << "---" << endl;
        // print();
    }
    int ris;
    first(ris);
    deinit();
    return ris;
}

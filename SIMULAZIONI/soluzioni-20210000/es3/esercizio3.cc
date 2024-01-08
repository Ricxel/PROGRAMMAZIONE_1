#include <iostream>
#include "pila.h"

using namespace std;

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta);

int main() { 

    int dimensioneMassima = 100;
    char espressioneBooleana [dimensioneMassima];
    bool corretta = true;
    char risultatoEspressione;

    cout << "Inserisci l'espressione: ";
    cin >> espressioneBooleana;

    risultatoEspressione = parseEspressioneBooleanaPrefissa(espressioneBooleana, corretta);

    if (corretta) {
        cout << "Risultato: " << risultatoEspressione << endl;
    }
    else {
        cout << "Espressione malformata" << endl;
    }
    
    return 0;
}

char fn_aux(char *espressione, bool & corretta){
    if(*espressione == '&'){
        char a,b;
        top(a);
        pop();
        top(b);
        
    }
}

char parseEspressioneBooleanaPrefissa(char espressione [], bool & corretta) {
    init();
    carica_in_pila(espressione);


    deinit();
}
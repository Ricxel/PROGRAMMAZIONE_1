#include <iostream>
#include "2-estrai.h"

using namespace std;

int main () {

    char stringa[MAX_DIM];
    char * risultato;
    
    cout << "Inserisci una stringa: " << endl;
    cin >> stringa;
    risultato = estrai_stringa(stringa);
    cout << "Il risultato è: " << risultato << endl;
    
    delete[] risultato;

    return 0;
}

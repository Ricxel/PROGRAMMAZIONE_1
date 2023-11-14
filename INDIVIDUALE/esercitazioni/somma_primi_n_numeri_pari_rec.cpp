using namespace std;
#include <iostream>

int somma_n_pari(int);

int main(){
    int n;
    cout << "n?";
    cin >> n;

    int ris = somma_n_pari(n);
    cout << endl << "Risultato: " <<  ris << endl;
}

int somma_n_pari(int n){
    cout << n << "+";
    int ris;
    if(n == 2)
        ris = n;
    else{
        ris = n + somma_n_pari(n-2);
    }
    return ris;
}
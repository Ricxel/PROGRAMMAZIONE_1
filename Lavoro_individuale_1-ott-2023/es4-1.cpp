using namespace std;
#include <iostream>

double potenza(double, int);

int main(){
    double n;
    double ris = 0;
    cout << "Inserisci un valore N> ";

    cin >> n;

    for(int i = 0; i <= n; i++){
        ris += 1/potenza(2,i);
    }
    cout << "Il risultato della successione è: " << ris << endl;

}

double potenza(double a, int n){
    double ris = 1;
    for(int i = 1; i <= n; i++){
        ris *= a;
    }
    return ris;
}

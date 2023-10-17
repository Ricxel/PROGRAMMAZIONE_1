using namespace std;
#include <iostream>

int fattoriale_rec(int n);

int main(){
    int n;

    cout << "n> ";
    cin >> n;

    int ris = fattoriale_rec(n);
    cout << "Il risultato è: " << ris << endl;
}

int fattoriale_rec(int n){
    int ris;
    if(n <= 1)
        ris = 1;
    else
        ris = n*fattoriale_rec(n-1);
    return ris;
}
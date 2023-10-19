using namespace std;
#include <iostream>

void stampa_caratteri_rec(char, char, int = 0);

int main(){
    char a,b;
    cout << "Inserisci due caratteri> ";
    cin >> a >> b;

    stampa_caratteri_rec(a,b);
}

void stampa_caratteri_rec(char inizio, char fine, int cont){
    if(fine - cont < inizio)
        return;
    cout << char(inizio + cont) << endl;
    stampa_caratteri_rec(inizio, fine, cont+1);
}
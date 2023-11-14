using namespace std;
#include <iostream>
#include <cmath>
#define DIM 31

int punteggio(char []);
int main(){
    char s[DIM];
    cout << "Inserisci una stringa> ";
    cin >> s;

    int risultato = punteggio(s);
    cout << "Il punteggio è: " << risultato << endl;

    return 0;
}
int punteggio(char s[]){
    //verifica
    bool ok = true;
    for(int i = 0; i < DIM && s[i] != '\0' && ok; i++){
        if(s[i] < 'a' || s[i] > 'z')
            ok = false;
    }
    if(!ok)
        return -1;
    //calcolo
    int somma = 0;
    for(int i=0; i < DIM-1 && s[i+1] != '\0';i++){
        somma += abs(s[i]-s[i+1]);
    }
    return somma;
}
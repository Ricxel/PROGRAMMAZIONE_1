using namespace std;
#include <iostream>

enum mesi{
    gennaio,
    febbraio,
    marzo,
    aprile,
    maggio,
    giugno,
    luglio,
    agosto,
    settembre,
    ottobre,
    novembre,
    dicembre
};

int main(){
    int x;
    mesi mese; 
    cout << "Inserisci un numero> ";

    cin >> x;
    mese = (mesi)x;
    cout << "Il giorno corrispondente è: " << mese << endl;
}
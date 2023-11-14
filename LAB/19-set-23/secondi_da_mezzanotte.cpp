using namespace std;
#include <iostream>
#include <cstring>

int conta_occorrenze(string,char);

int main(){
    int ore, minuti, secondi;
    string s = "";
    char* prova = strtok(,":");
    cout << "Ore> ";
    cin >> ore;
    cout << "Minuti> ";
    cin >> minuti;
    cout << "Secondi> ";
    cin >> secondi;

    int ris = ore*60*60 + minuti*60 + secondi;

    cout << "I secondi passati da mezzanotte sono: " << ris << endl;
}
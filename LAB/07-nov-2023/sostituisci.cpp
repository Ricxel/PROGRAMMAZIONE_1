using namespace std;
#include <iostream>
#include <fstream>

int main(int argc, char ** argv){
    if(argc != 2){
        cout << "Parametri errati" << endl;
        return -1;
    }
    fstream in;
    in.open(argv[1],ios::in);
    if(in.fail()){
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }
    //lettura del carattere
    char target;
    cout << "Inserisci un carattere da sostituire> ";
    cin >> target;
    char c;
    while(!in.eof() && !in.fail()){
        in.get(c);
        if(c == target){
            cout << '?';
        }
        else cout << c;
    }
    return 0;
}
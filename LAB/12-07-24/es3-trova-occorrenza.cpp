using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri non validi" << endl;
        return -1;
    }
    fstream in;
    in.open(argv[2],ios::in);
    if(in.fail()){
        cout << "Errore nell'apertura file" << endl;
        return -2;
    }
    char buffer[128];
    bool trovato = false;
    while(in >> buffer && !trovato){
        if(strstr(buffer, argv[1]) != NULL){
            trovato = true;
        }
    }
    
    if(trovato){
        cout << "Esiste almeno un occorenza della stringa speicificata" << endl;
    }
    else cout << "Non esiste nessuna occorrenza della stringa specificata" << endl;

    in.close();
    return 0;
}
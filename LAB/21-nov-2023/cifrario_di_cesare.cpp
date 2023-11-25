using namespace std;
#include <iostream>
#include <fstream>
#include "cifrario_functions.h"

int main(int argc, char ** argv){

    if(argc != 4){
        cout << "Parametri errati..." << endl;
        return -1;
    }
    fstream input,output;
    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);
    int chiave = atoi(argv[3]);

    char parola[DIM];

    if(input.fail()){
        cout << "Errore nell'apertura dei file..." << endl;
        return -1;
    }

    while(!input.eof() && !input.fail()){
        input >> parola;
        crypt(parola,chiave);
        output << parola;
    }

    input.close();
    output.close();
    return 0;
}
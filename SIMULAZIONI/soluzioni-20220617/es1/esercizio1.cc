// Inserisci qui il codice
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

const int DIM = 100;
int main(int argc, char **argv){
    if(argc != 4){
        cout << "Parametri errati" << endl;
        return -1;
    }
    fstream stringhe, numeri, out;
    
    stringhe.open(argv[1], ios::in);
    numeri.open(argv[2], ios::in);
    out.open(argv[3], ios::out);
    
    if(stringhe.fail() || numeri.fail() || out.fail()){
        cout << "Errore nell'apertura dei file" << endl;
        exit(-2);
    }

    int dim_stringhe;
    char buffer[DIM];
    stringhe >> buffer;
    dim_stringhe = atoi(buffer);

    //alloco la matrice di caratteri
    char **mat = new char*[dim_stringhe];
    for(int i = 0; i < dim_stringhe; i++){
        mat[i] = new char[DIM];
    }
    //riempio l'array con le stringhe
    int i = 0;
    while(stringhe >> buffer){
        strcpy(mat[i++], buffer);
    }
    //scorro i numeri  
    while(numeri >> buffer){
        int index = atoi(buffer);
        if(index >= dim_stringhe || index < 0){
            out << "MISSING ";
        }
        else{
            out << mat[index] << " ";
        }
    }
    out << endl;
    stringhe.close();
    numeri.close();
    out.close();
    // dealloco la matrice
    for(int i = 0; i < dim_stringhe; i++){
        delete[] mat[i];
    }
    delete[] mat;
    return 0;
}
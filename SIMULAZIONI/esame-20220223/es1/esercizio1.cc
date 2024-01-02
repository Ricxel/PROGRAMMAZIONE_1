// Inserisci qui il codice
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
bool controlla_validita(char *);
int is_presente(char *s, char v[][100], int dim_v);

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri non validi" << endl;
        return -1;
    }
    fstream in,out;
    in.open(argv[1],ios::in);
    out.open(argv[2],ios::out);

    if(in.fail() || out.fail()){
        cout << "Errore nell'apertura del file" << endl;
        exit(-1);
    }
    const int DIM = 100;
    //array di stringhe che conterrà tutte le parole
    char v[DIM][DIM];
    int dim_v = 0;
    int n;

    int occorrenze[DIM];
    for(int i = 0; i < DIM; i++){
        occorrenze[i] = 1;
    }
    char buffer[DIM];

    while(in >> buffer){
        if(controlla_validita(buffer)){
            cout << buffer << "---" << endl;
            n = is_presente(buffer, v, dim_v);
            if(n == -1){
                strcpy(v[dim_v], buffer);
                dim_v++;
            }
            else{
                cout << v[n] << " aumentato a " << occorrenze[n]+1 << endl;
                occorrenze[n]++;
            }
        }
    }
    for(int i = 0; i < dim_v; i++){
        out << v[i] << ": " << occorrenze[i] << endl;
    }
    in.close();
    out.close();
    return 0;
}
bool controlla_validita(char *s){
    bool valida = true;
    for(int i = 0; s[i] != '\0' && valida; i++){
        if(s[i] < 'a' || s[i] > 'z')
            valida = false;
    }
    return valida;
}
int is_presente(char *s, char v[][100], int dim_v){
    for(int i = 0; i < dim_v; i++){
        if(strcmp(v[i], s) == 0)
            return i;
    }
    return -1;
}
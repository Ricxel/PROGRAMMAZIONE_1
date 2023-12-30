// Inserire qui il codice
#include <iostream>
#include <fstream>

using namespace std;

const int DIM = 255;

void strcopy(char *s, char *s2){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        s2[i] = s[i];
    }
    s2[i+1] = '\0';
}
int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri non validi" << endl;
        return -1;
    }

    fstream in,out;
    in.open(argv[1], ios::in);
    out.open(argv[2], ios::out);
    if(in.fail() || out.fail()){
        cout << "Errore nell'apertura del file" << endl;
        exit(-2);
    }
    char c;
    int cont = 0;
    int max = -1;
    char stringa_max[DIM];
    char s[DIM];

    while(in.get(c)){
        if(c != '\n'){
            s[cont++] = c;
        }
        else{
            s[cont] = '\0';
            if(cont > max){
                max = cont;
                strcopy(s, stringa_max);
            }
            out << cont << endl;
            cont = 0;
        }
    }
    out << stringa_max << endl;

    in.close();
    out.close();
    return 0;
}
// Inserire qui il codice
using namespace std;
#include <iostream>
#include <fstream>

int strlen(char *);
void strcpy(char *, char *);

const int DIM = 256;
int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri errati" << endl;
        return -1;
    }  
    fstream in,out;
    in.open(argv[1],ios::in);
    out.open(argv[2],ios::out);

    if(in.fail() || out.fail()){
        cout << "Errore nell'apertura dei file" << endl;
        exit(-2);
    }

    char buffer[DIM];
    char linea_lunga[DIM];
    int len;
    int max = -1;

    while(in.getline(buffer, DIM)){
        len = strlen(buffer);
        if(len > max){
            max = len;
            strcpy(linea_lunga, buffer);
        }
        out << len << '\n';
    }
    out << linea_lunga << '\n';
    
    in.close();
    out.close();
    return 0;
}

int strlen(char *s){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}
void strcpy(char *s, char *source){
    int i = 0;
    while(source[i] != '\0'){
        s[i] = source[i];
        i++;
    }
    s[i] = '\0'; 
}
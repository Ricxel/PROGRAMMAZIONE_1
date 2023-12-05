using namespace std;
#include <iostream>
#include <fstream>

const int DIM = 10;

int conta_asterischi(char *);
int main(int argc, char ** argv){
    if(argc != 2){
        cout << "Parametri invalidi" << endl;
        return -1;
    }
    char buffer[DIM];
    int somma = 0, cont = 0;
    fstream in, out;
    in.open(argv[1],ios::in);

    while(in >> buffer){
        somma += conta_asterischi(buffer);
        cont++;
    }
    int media = somma/cont;
    
    in.close();
    out.open(argv[1],ios::app);
    for(int i = 0; i < media; i++){
        out << '*';
    }
    out << endl;
    out.close();

    return 0;   
}
int conta_asterischi(char *s){
    int cont = 0;
    for(int i = 0; i < DIM && s[i] != '\0'; i++){
        cont++;
    }
    return cont;
}
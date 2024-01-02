// Inserire tutto quello che serve qui
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

const int NCIFRE = 10;
int converti(char *);
int operazione(int,int,char);

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri non validi" << endl;
        return -1;
    }

    fstream in,out;
    in.open(argv[1], ios::in);
    out.open(argv[2],ios::out);

    if(in.fail() || out.fail()) {
        cout << "Errore nell'apertura del file" << endl;
        exit(-2);
    }
    
    char n1[NCIFRE];
    char n2[NCIFRE];
    char op;
    bool ok = true;
    int m1, m2;
    while(!in.eof()){
        in >> n1;
        in >> op;
        ok = !in.eof();
        in >> n2;
        if(ok){
            cout << n1 << ' ' << op << ' ' << n2 << endl;
            m1 = converti(n1);
            m2 = converti(n2);
            int ris = operazione(m1,m2,op);
            out << ris << endl;
        }
    }
    
    in.close();
    out.close();
    return 0;
}
int converti(char *s){
    int ris = 0;
    int esp = 0;
    const int OFFSET = '0';
    for(int i = strlen(s) - 1; i >= 0; i--){
        char c = s[i];
        if(c >= 'A' && c <= 'Z'){
            c = c - 'A' + 10;
        }
        else c -= OFFSET; 
        ris += c*pow(17, esp++);
    }
    return ris;
}
int operazione(int n1, int n2, char op){
    int ris = 0;
    switch(op){
        case '+':
            ris = n1 + n2;
            break;
        case '*':
            ris = n1 * n2;
            break;
        case '^':
            ris = pow(n1,n2);
            break;
        default:
            break;
    }
    return ris;
}
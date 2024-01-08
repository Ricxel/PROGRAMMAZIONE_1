#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstring>
using namespace std;
const int DIM = 256;
int converti_a_dec(char *s, int base);
void converti_da_dec(int n, int base, char *ris);

double pow(double a, int n);

int main(int argc, char **argv){
    if(argc != 3){
        cout << "Parametri errati" << endl;
        return -1;
    }
    int base = atoi(argv[2]);
    // int n = atoi(argv[1]);
    int n = converti_a_dec(argv[1], base);
    // char s[DIM];
    // converti_da_dec(n,base,s);

    cout << "Il numero convertito è: " << n << endl;
    return 0;
}

int converti_a_dec(char *s, int base){
    int cifra;
    int ris = 0;
    int len = strlen(s);
    int esp = 0;
    for(int i = len-1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9')
            cifra = s[i] - '0';
        else if(s[i] >= 'A' && s[i] <= 'Z')
            cifra = s[i] - 'A' + 10;
        else if(s[i] >= 'a' && s[i] <= 'z')
            cifra = s[i] - 'a' + 10;
        ris += pow(base, esp++) * cifra;
    }
    return ris;
}
double pow(double a, int n){
    double ris = 1;
    for(int i = 1; i <= n; i++){
        ris *= a;
    }
    return ris;
}
void converti_da_dec(int n, int base, char *ris){
    char s[DIM];
    int i = 0;
    for(i = 0; n > 0 && i < DIM - 1; i++){
        int cifra = n%base;
        //controllo cifra:
        if(cifra >= 10)
            cifra = cifra - 10 + 'A';
        else cifra += '0';

        //inserimento
        s[i] = cifra;
        n /= base;
    }
    s[i] = '\0';
    //copio stringa al contrario;
    int j = 0;
    i--;
    for(j = 0; i >= 0 && j < DIM; j++){
        ris[j] = s[i--];
    }
    ris[j] = '\0';
}

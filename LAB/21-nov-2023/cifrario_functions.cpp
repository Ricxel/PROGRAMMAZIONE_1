#include "cifrario_functions.h"

void crypt(char parola [], int chiave){
    int i = 0;
    for(; i < DIM && parola[i] != '\0'; i++){
        char c = parola[i] += chiave;
        if(c > 'z'){
            c = c - 'z' + 'a' - 1;
        }
        parola[i] = c;
    }
}
void decrypt(char parola [], int chiave);
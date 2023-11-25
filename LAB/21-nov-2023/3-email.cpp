#include "3-email.h"
static int len(char *s){
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}
bool email(char *s){
    char utente[MAX_DIM];
    char dominio[MAX_DIM];
    bool trovato = false, valido = true;
    int u = 0,d = 0;

    for(int i = 0; s[i] != '\0' && i < MAX_DIM && valido; i++){
        if(s[i] == '@'){
            trovato = true;
            i++;
        }        
        if(!trovato){
            if ((s[i] >= 'a' && s[i] <= 'z') || 
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9') ||
                s[i] == '.' || 
                s[i] == '_'
                )
                utente[u++] = s[i];
            else valido = false;
        }
        else{
            if ((s[i] >= 'a' && s[i] <= 'z') || 
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9') ||
                s[i] == '.' || 
                s[i] == '_'
                )
                dominio[d++] = s[i];
            else valido = false;
        }
    }
    utente[u] = '\0';
    dominio[d] = '\0';
    //cout << "utente " << utente << endl;
    //cout << "dominio " << dominio << endl;
    int len_u = len(utente);
    int len_d = len(dominio);

    cout << "len_u: " << len_u << endl;
    cout << "len_d: " << len_d << endl;

    if(utente[0] == '.' || utente[len_u-1] == '.' || len_u == 0)
        valido = false;
    if(dominio[0] == '.' || dominio[len_d-1] == '.' || len_d == 0)
        valido = false;

    return valido;

} 
#include "2-estrai.h"
void estrai_lettera(char *stringa, int i, char *risultato, int j){
    if(stringa[i] == '\0' || i >= MAX_DIM || j >= MAX_DIM){
        risultato[j] = '\0';
    }
    if(stringa[i] >= 'A' && stringa[i] <= 'Z'){
        risultato[j] = stringa[i];
        j++;
    }
    estrai_lettera(stringa,i+1,risultato,j);

}
char * estrai_stringa(char *stringa){
    char *risultato = new char[MAX_DIM];
    estrai_lettera(stringa,0,risultato,0);
    return risultato;
}
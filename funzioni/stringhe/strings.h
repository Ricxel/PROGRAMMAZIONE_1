#ifndef STRINGS_H
#define STRING_H
const int DIM = 256;
//restituisce la lunghezza di s
int strlen(char *s);
//restituisce l'indice della prima occorrenza di c in s, NULL se non trova il carattere
int  index_of(char *s, char c, int i = 0);
//come sopra ma l'ultima occorrenza
int last_index_of(char *s, char c, int len);
// estrae da s una sottostringa da index per n caratteri
void substring(char *s, char *buffer, int index, int n);
//restituisce l'indice della prima occorrenza della sottostringa t in s
int last_index_of_pattern(char *s, char *t, int i = 0);
//copia t in s e restituisce s
char * strcpy(char *s, char *t, int i = 0);
//copia i primi n caratteri di t in s e restituisce s
char * stradd(char *s, char *t, int n);
//
int strcmp(char *s, char *t);

#endif
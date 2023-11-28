#include "./../../liste_concatenate/lista_concatenata.h"
// operazioni:
// -init
// -deinit
// -push
// -pop
// -top
typedef nodo * stack;

//restitusce true se lo stack è stato inizializzato, false altrimenti
void init(stack &);
//inserisce un elemento sopra la pila
void push(stack &, int);
//rimuove il primo elemento dalla pila
void pop(stack &);
//restituisce il primo elemento della pila
int top(stack);
//dealloca lo stack
void deinit(stack);
//stampa stack
void print_stack(stack);
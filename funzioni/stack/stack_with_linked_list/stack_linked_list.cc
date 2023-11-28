#include "stack_linked_list.h"

void init(stack & st){
    st = NULL;
}
void push(stack & st, int n){
    nodo *nuovo_nodo = new nodo{n,st};
    st = nuovo_nodo;
}
void pop(stack & st){
    if(st == NULL){
        return;
    }
    nodo *nodo_elim = st;
    st = st->next;
    delete nodo_elim;
}
int top(stack st){
    return st->value;
}
void deinit(stack st){
    if(st == NULL){
        return;
    }
    if(st->next != NULL){
        deinit(st->next);
    }
    else delete st;
}
void print_stack(stack st){
    stampa_lista(st);
}
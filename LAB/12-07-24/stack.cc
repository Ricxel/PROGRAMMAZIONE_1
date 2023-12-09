#include "stack.h"
void init(stack &s){
    s = NULL;
}
void deinit(stack s){
    if(s == NULL)
        return;
    deinit(s->next);
    delete s;
}
bool nempty(stack s){
    if(s == NULL){
        return false;
    }
    else return true;
}
void add(stack &s, double val){
    node *nuovo_nodo = new node{val,s};
    s = nuovo_nodo;
}
bool shrink(stack &s){   
    if(s == NULL)
        return false;
    node *prossimo = s->next;
    delete s;
    s = prossimo;
    return true;
}
bool fist(stack s, double &val){
    if(s == NULL){
        return false;
    }
    val = s->value;
    return true;
} 
void print(stack s){
    cout << s->value << " ";
    print(s->next);
}
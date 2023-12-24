#include "coda_array.h"
void coda_init(){
    c->h = c->t = 0;
    c->v = new int[DIM];
}
void coda_enqueue(int n){
    c->v[c->t] = n;
    c->t = (c->t + 1)%DIM;
}
void coda_dequeue(){
    c->h = (c->h + 1)%DIM;
}
int coda_first(){
    return c->v[c->h];
}
void coda_deinit(){
    delete[] c->v;
}
bool coda_is_empty(){
    if(c->t == c->h){
        return true;
    }
    return false;
}
bool coda_is_full(){
    if((c->t + 1 % DIM) == c->h){
        return true;
    }
    return false;
}
int coda_n_elementi(){
    return c->t >= c->h ? c->t - c->h : c->t - c->h + DIM;
}
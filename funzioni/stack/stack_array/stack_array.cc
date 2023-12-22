#include "stack_array.h"
void stack_init(stack *s){
    s->v = new int[DIM];
    s->h = 0;
}
bool stack_push(stack *s, int n){
    if(s->h < DIM){
        s->v[s->h++] = n;
        return true;
    }
    else return false;
}
bool stack_pop(stack *s){
    if(s->h > 0){
        s->h--;
        return true;
    }
    else return false;
}
int stack_top(stack *s){
    return s->v[s->h - 1];
}
void deinit(stack *s){
    delete[] s->v;
}
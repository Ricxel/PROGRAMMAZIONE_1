#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
using namespace std;

const int DIM = 1024;
struct stack{
    int *v;
    int h;
};
void stack_init(stack *s);
bool stack_push(stack *s, int n);
bool stack_pop(stack *s);
int stack_top(stack *s);




#endif
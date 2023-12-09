#ifndef STACK_H
#define STACK_H
using namespace std;
#include <iostream>
struct node{
    double value;
    node *next; 
};
typedef node * stack;

void init(stack &);
void deinit(stack);
bool nempty(stack);
void add(stack, double val);
bool shrink(stack);
bool first(stack, double &);
void print(stack);
#endif
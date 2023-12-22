#include <iostream>
#include "stack_array.h"
using namespace std;

int main(){
    stack *s = new stack;
    stack_init(s);
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);

    for(int i = 0; i < 3; i++){
        int n = stack_top(s);
        stack_pop(s);
        cout << i << " estratto: " << n << endl;
    }

}
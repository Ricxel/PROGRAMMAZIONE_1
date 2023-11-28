#include "stack_linked_list.h"
#include <iostream>
#include <fstream>

int main(int argc, char ** argv){
    stack st;
    init(st);
    int x;
    fstream in;
    in.open(argv[1],ios::in);
    if(in.fail()){
        cout << "Impossibile leggere il file" << endl;
        return -1;
    }
    while(!in.eof()){
        in >> x;
        push(st,x);
    }
    cout << "---STACK---" << endl;
    print_stack(st);
    cout << "------------" << endl;

    //srotolamento:
    cout << "------Srotolato-----" << endl;
    while(st != NULL){
        x = top(st);
        pop(st);
        cout << x << " ";
    }
    cout << endl << "--------------------" << endl;

    in.close();
    deinit(st);
}
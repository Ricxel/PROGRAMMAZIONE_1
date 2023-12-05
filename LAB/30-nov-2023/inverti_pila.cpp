#include "coda/coda.h"
#include "pila/pila.h"

void inverti_pila();

int main(int argc, char ** argv){
    pila_init();
    pila_push(1);
    pila_push(2);
    pila_push(3);

    pila_print();
    pila_deinit();
    return 0;
}
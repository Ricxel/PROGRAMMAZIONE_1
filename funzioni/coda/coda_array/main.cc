
#include <iostream>
#include "coda_array.h"

int main(){
    coda_init();
    coda_enqueue(1);
    coda_enqueue(2);
    coda_enqueue(3);

    // for(int i = 0; i < 3; i++){
    //     int n = coda_first();
    //     coda_dequeue();
    //     cout << n << ' ';
    // }
    int len = coda_n_elementi();
    cout << "Numero elementi: " << len << endl;
    coda_deinit();
    return 0;

}
using namespace std;
#include <iostream>

void dim(int v[]){
    cout << "Dimensione funzione: " << sizeof(v)/sizeof(int) << endl;
}

int main(){
    int v[10];
    cout << "Dimensione: " << sizeof(v)/sizeof(int) << endl;
    dim(v);
}
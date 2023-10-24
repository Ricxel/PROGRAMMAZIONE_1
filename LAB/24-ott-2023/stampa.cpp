using namespace std;
#include <iostream>

void stampa(int v[], int len){
    for(int i=0; i < len; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    const int DIM = 10;
    int v[DIM];
    srand(time(NULL));

    for(int i = 0; i < DIM; i++){
        v[i] = rand() % 10;
    }

    for(int n : v){
        cout << n << ' ';
    }
    cout << endl;

    stampa(v,DIM);

    return 0;
}
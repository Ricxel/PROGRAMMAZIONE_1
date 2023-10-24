using namespace std;
#include <iostream>
#define DIM 10

void inizializza(int, int [], int);
void stampa(int [], int);
void swap(int &, int &);
void inverti(int [], int);

int main(){
    srand(time(NULL));  
    int v[DIM];

    inizializza(10, v, DIM);
    stampa(v,DIM);

    inverti(v,DIM);
    stampa(v,DIM);
}

void inizializza(int max, int v[], int len){
    for(int i = 0; i < len; i++)
        v[i] = rand() % max + 1;
}
void stampa(int v[], int len){
    for(int i=0; i < len; i++)
        cout << v[i] << " ";
    cout << endl;
}
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void inverti(int v[], int len){
    int j = len - 1;
    for(int i = 0; i < len/2; i++){
        swap(v[i],v[j]);
        j--;
    }
}
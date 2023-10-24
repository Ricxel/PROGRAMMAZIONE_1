using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM 10

void inizializza(int, int [], int);
void stampa(int [], int);
int conta_duplicati(int [], int [], int);

int main(){
    int max,ris;
    srand(time(NULL));
    cout << "Max: ";
    cin >> max;

    int a[DIM];
    int b[DIM];

    inizializza(max,a,DIM);
    inizializza(max,b,DIM);

    stampa(a,DIM);
    stampa(b,DIM);

    ris = conta_duplicati(a,b,DIM);

    cout << "Il numero di duplicati è: " << ris << endl;
    return 0;
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
int conta_duplicati(int a[], int b[], int len){
    int cont = 0;
    for(int i = 0; i < len; i++){
        if(a[i] == b[i])
            cont++;
    }
    return cont;
}


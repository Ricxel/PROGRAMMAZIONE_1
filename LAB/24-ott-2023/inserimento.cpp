using namespace std;
#include <iostream>
#define DIM 10

void inizializza(int, int [], int);
void stampa(int [], int);
void inserisci(int [], int, int, int);

int main(){
    int a[10];
    int n,indice;
    srand(time(NULL));
    inizializza(10,a,DIM);
    stampa(a,DIM);

    cout << "Inserisci valore> ";
    cin >> n;
    cout << "Indice> ";
    cin >> indice;

    inserisci(a,DIM,indice,n);
    stampa(a,DIM);
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
void inserisci(int v[], int len, int indice, int n){
    for(int i = len - 1; i >= indice; i--){
        v[i] = v[i-1];
    }
    v[indice] = n;
}
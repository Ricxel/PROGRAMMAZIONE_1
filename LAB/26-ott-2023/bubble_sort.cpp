using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM 20
void inizializza_vettore(int [], int);
void stampa_vettore(int [], int);
int bubble_sort(int [], int);
bool confronta_rec(int [], int, bool = true, int = 0);
int bubble_sort_rec(int [], int, int = 0);


int main(){
    srand(time(NULL));
    int v[DIM];
    int iterazioni;
    inizializza_vettore(v,DIM);
    stampa_vettore(v,DIM);
    iterazioni = bubble_sort_rec(v,DIM);
    stampa_vettore(v,DIM);
    cout << "Numero di iterazioni: " << iterazioni << endl;

    return 0;
}

void inizializza_vettore(int v[], int len){
    for(int i = 0; i < len; i++){
        v[i] = rand() % 100 + 1;
    }
}
void stampa_vettore(int v[], int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int bubble_sort(int v[], int len){
    bool ok;
    int i = 0;
    do{
        ok = true;
        for(int i = 0; i < len -1; i++){
            if(v[i] > v[i + 1]){
                swap(v[i], v[i + 1]);
                ok = false;
            }
        }
        i++;
    }while(!ok);
    return i;
}
bool confronta_rec(int v[], int len, bool ok, int i){
    if(i >= len - 1)
        return ok;
    if(v[i] > v[i + 1]){
        swap(v[i],v[i+1]);
        ok = false;
    }
    return confronta_rec(v,len, ok, i+1);
}
int bubble_sort_rec(int v[], int len, int i){
    bool ok = confronta_rec(v,len);
    if(ok){
        return i;
    }
    return bubble_sort_rec(v,len-1,i+1);
}

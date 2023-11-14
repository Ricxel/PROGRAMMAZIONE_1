#include "array_function.h"
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
static bool confronta_rec(int v[], int len, bool ok = true, int i = 0){
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

using namespace std;
#include <iostream>

void genera_esagonali(int n, int *buffer, int i = 0);
void stampa_vettore(int *, int);

int main(){
    int n;
    cout << "n? ";
    cin >> n;

    int *numeri_esagonali = new int[n];
    
    genera_esagonali(n, numeri_esagonali);
    stampa_vettore(numeri_esagonali, n);

    delete[] numeri_esagonali;
    return 0;
}
void genera_esagonali(int n, int *buffer, int i){
    if(i >= n){
        return;
    }
    buffer[i] = i*(2*i - 1);
    genera_esagonali(n, buffer, i+1);
}
void stampa_vettore(int *v, int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
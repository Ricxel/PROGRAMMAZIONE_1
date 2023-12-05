using namespace std;
#include <iostream>

bool is_palindromo(int *, int, int, int);
void stampa_vettore(int *, int);

int main(int argc, char ** argv){
    int len, n;
    cout << "len? ";
    cin >> len;

    if(len > 100){
        cout << "La lunghezza può essere al massimo di 100" << endl;
        return 0;
    }
    int v[len];
    for(int i = 0; i < len; i++){
        cout << "n? ";
        cin >> n;
        v[i] = n;
    }
    stampa_vettore(v,len);
    //verifica palindroma
    bool ris = is_palindromo(v,len, 0, len-1);
    cout << "E' palindromo:  " << ris << endl;
    return 0;
}

void stampa_vettore(int *v, int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
// bool is_palindromo(int *v, int len, int i, int j){
//     if(i >= j){
//         return true;
//     }
//     if(v[i] != v[j]){
//         return false;
//     }
//     return is_palindromo(v,len,i+1,j-1);
// }
bool is_palindromo(int *v, int len, int i, int j){
    bool ris = true;
    if(i < j){
        if(v[i] != v[j])
            ris = false;
        else ris = is_palindromo(v,len,i+1,j-1);
    }
    return ris;
}
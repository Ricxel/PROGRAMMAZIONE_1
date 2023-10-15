using namespace std;
#include <iostream>
#include <cmath>

int invertiNumero(int);
int contaCifre(int);

int main(){
    int n;
    cout << "Inserisci un numero> ";

    cin >> n;
    if(cin.fail()){
        cout << "Inserito carattere non valido! " << endl;
        return 1;
    }
    int n_inv = invertiNumero(n);
    cout << "Il numero invertito è: " << n_inv << endl;
}
int contaCifre(int n){
    int count = 0;
    do
    {
        n /= 10;
        count++;
    } while (n > 0);
    return count;
    
}
int invertiNumero(int n){
    //cout << "Conta cifre: " << contaCifre(n) << endl;
    int n_inv = 0;
    for(int i = contaCifre(n) - 1; i >= 0; i--){
        n_inv += (n%10)*pow(10,i);
        n /= 10;
    }
    
    return n_inv;
}
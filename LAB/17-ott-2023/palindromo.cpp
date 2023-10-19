using namespace std;
#include <iostream>
#include <cmath>

int inverso_rec(int,int = 0);
bool palindromo(int);

int main(){
    int n;
    cout << "n> ";
    cin >> n;

    if(palindromo(n))
        cout << "Il numero è palindromo" << endl;
    else cout << "Il numero non è palindromo" << endl;

}

int inverso_rec(int n,int n2){
    if(n == 0){
        return n2;
    }
    int cifra = n % 10;
    n2 = n2*10 + cifra;

    cout << n2 << endl;

    return inverso_rec(n/10,n2);
}
bool palindromo(int n){
    if(n == inverso_rec(n))
        return true;
    else return false;
}
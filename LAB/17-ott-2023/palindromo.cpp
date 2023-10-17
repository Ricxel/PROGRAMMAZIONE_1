using namespace std;
#include <iostream>
#include <cmath>

int palindromo_rec(int,int = 0,int = 1);

int main(){
    int n;
    cout << "n> ";
    cin >> n;

    bool ris = palindromo_rec(n);

    cout << endl << "Ris: "<< ris << endl;;

}

int palindromo_rec(int n,int n2, int p){
    int ris = n % 10;

    int somma = ris * (int)pow(10,p-1);

    n2 += somma;
    cout << "Ris: " << n << "%" <<10 << " = " << ris << endl;
    cout << "Somma: " << somma << endl;
    if(ris == n){
        return false;
    }
    
    palindromo_rec(n/10,n2,p+1);
    
    cout << "n2: " << n2 << endl;
    if(n2 == n)
        return true;
    else return false;
}
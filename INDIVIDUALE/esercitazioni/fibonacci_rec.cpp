using namespace std;
#include <iostream>

long fib(int);

int main(){
    int n;
    cout << "Inserisci un numero> ";
    cin >> n;

    long ris = fib(n);

    cout << "Il risultato è: " << ris << endl;
}

long fib(int n){
    long ris;
    cout << "n: " << n << endl;
    if(n == 0 || n == 1)
        ris = 1;
    else
        ris = fib(n-1) + fib(n-2);
    return ris;
}
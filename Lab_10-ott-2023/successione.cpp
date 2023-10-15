using namespace std;
#include <iostream>
int main(){
    long n;
    cout << "n>";

    cin >> n;
    int a=0,b;
    double ris;

    for(int i = 1; i <= n; i++){
        a+=i;
    }
    b = n*n;
    ris = (double)a/(double)b;

    cout << "Risultato: " << ris << endl;

}
using namespace std;
#include <iostream>

int sommaCifre(int n);

int main(){
    int n;
    cout << "n> ";
    cin >> n;
    int ris;

    ris = sommaCifre(n);
    cout << "Risultato: " << ris << endl;
}

int sommaCifre(int n){
    if(n == 0){
        return 0;
    }
    return n%10 + sommaCifre(n/10);
}
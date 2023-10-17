using namespace std;
#include <iostream>

int div_rec(int, int, int = 0);

int main(){
    int a,b;
    cout << "n> ";
    cin >> a >> b;

    int ris = div_rec(a,b);
    cout << "Risultato: " << ris << endl;
}

int div_rec(int a, int b, int ris){
    if(a >= b){
        ris++;
        ris = div_rec(a-b, b, ris);
    }
    return ris;
}
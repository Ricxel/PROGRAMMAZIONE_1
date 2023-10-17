using namespace std;
#include <iostream>

int div_rec(int, int, int, int &);
int div_wrapper(int,int,int &);

int main(){
    int a,b,resto;
    cout << "n> ";
    cin >> a >> b;

    int ris = div_wrapper(a,b,resto);
    cout << "Risultato: " << ris << " con resto di " << resto << endl;
}

int div_rec(int a, int b, int ris, int &resto){
    if(a >= b){
        ris++;
        ris = div_rec(a-b, b, ris, resto);
    }
    else{
        resto = a;
    }
    return ris;
}
int div_wrapper(int a, int b, int &resto){
    return div_rec(a, b, 0, resto);
}
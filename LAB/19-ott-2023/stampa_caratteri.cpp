using namespace std;
#include <iostream>

void stampa(char,char);

int main(){
    cout << "Inserisci> ";
    char a,b;

    cin >> a >> b;
    stampa(a,b);
    cout << endl;
}

void stampa(char a, char b){
    if(a <= b){
        cout << a << " ";
        stampa(a+1, b);
    }
}
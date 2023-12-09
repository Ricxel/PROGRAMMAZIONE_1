#include <iostream>

using namespace std;

int calcola_it(int x,
               int y);
int calcola_ric(int x,
                int y);

int main() {
    int a, b, risultato_it, risultato_ric;

    cout << "Inserisci due numeri interi a e b: ";
    cin >> a >> b;

    if ((a == 0) || (b == 0)) {
        cout << "Inserire interi maggiori di zero." << endl;
        return 1;
    }

    risultato_it  = calcola_it(a, b);
    risultato_ric = calcola_ric(a, b);

    cout << "Risultato iterativo: " << risultato_it << endl;
    cout << "Risultato ricorsivo: " << risultato_ric << endl;

    return 0;
}

int calcola_it(int x, int y) {
    int result = 0;

    while (x >= y) {
        x = x - y;
        ++result;
    }
    return result;
}
int calcola_ric(int x, int y){
    if(x < y){
        return 0;
    }
    else return 1 + calcola_ric(x-y,y);
}
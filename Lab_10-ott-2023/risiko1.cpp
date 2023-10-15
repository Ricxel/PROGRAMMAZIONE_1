using namespace std;
#include <iostream>

void tiraDadi(int &, int &);

int main(){
    int dado_1, dado_2;

    tiraDadi(dado_1,dado_2);

    cout << "Dado 1: " << dado_1 << endl
         << "Dado 2: " << dado_2 << endl;

    if(dado_1 > dado_2)
        cout << "Ha vinto l'attaccante!" << endl;
    else cout << "Ha vinto il difensore!" << endl;

}

void tiraDadi(int &d_1, int &d_2){
    srand(time(NULL));
    d_1 = rand()%6+1;
    d_2 = rand()%6+1;
}
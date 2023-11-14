using namespace std;
#include <iostream>
#include <algorithm>

void inizializzaRandom();
void tiraDadi(int &, int &);

int main(){
    int dado_1_A, dado_2_A;
    int dado_1_D, dado_2_D;
    int n_vinti_A = 0,n_vinti_D = 0;

    inizializzaRandom();
    //tiri per attaccante
    tiraDadi(dado_1_A,dado_2_A);

    cout << "Dado 1: " << dado_1_A << endl
         << "Dado 2: " << dado_2_A << endl;

    //tiri per difensore
    tiraDadi(dado_1_D,dado_2_D);
    cout << "Dado 1: " << dado_1_D << endl
         << "Dado 2: " << dado_2_D << endl;
    
    //confronto massimi:
    int max_A,max_D;
    max_A = max(dado_1_A,dado_2_A);
    max_D = max(dado_1_D,dado_2_D);

    if(max_A > max_D)
        n_vinti_A++;
    else n_vinti_D++;

    //confronto minimi:
    int min_A,min_D;
    min_A = min(dado_1_A,dado_2_A);
    min_D = min(dado_1_D,dado_2_D);

    if(min_A > min_D)
        n_vinti_A++;
    else n_vinti_D++;

    cout << "Scontri vinti dall'attaccante: " << n_vinti_A << endl
         << "Scontri vinti dal difensore: " << n_vinti_D << endl;

}
void inizializzaRandom(){
    srand(time(NULL));
}
void tiraDadi(int &d_1, int &d_2){
    d_1 = rand()%6+1;
    d_2 = rand()%6+1;
}
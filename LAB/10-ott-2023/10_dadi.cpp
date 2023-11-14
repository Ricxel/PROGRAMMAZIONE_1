using namespace std;
#include <iostream>
#include <cstdlib>

// Ritorna il numero di volte che è uscito 1
int lanciaDadi(int);
int main(){
    int n_1 = lanciaDadi(6);
    int risposta;
    cout << "Quante volte è uscito 1? " << endl;
    cin >> risposta;
    if(risposta == n_1)
        cout << "Hai vinto!" << endl;
    else cout << "Hai perso!" << endl;
}
int lanciaDadi(int n_dadi){
    int count = 0;
    int random_number;
    srand(time(NULL));
    for(int i = 0; i < n_dadi; i++){
        random_number = rand()%6+1;
        if(random_number == 1)
            count++;
    }
    return count;
}
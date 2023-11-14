using namespace std;
#include <iostream>

int * generate_numbers(int N);

int main(){
    srand(time(NULL));
    int n;
    cout << "Inserisci un numero> ";
    cin >> n;
    int *v = generate_numbers(n);
    //stampa
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
    delete[] v;
    return 0;
}

int * generate_numbers(int N){
    int *v = new int[N];
    for(int i = 0; i < N; i++){
        *(v+i) = rand() % 100;
    }
    return v;
}
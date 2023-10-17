using namespace std;
#include <iostream>

void decToBin(int);

int main(){
    int n;
    cout << "n> ";
    cin >> n;

    decToBin(n);
    cout << endl;
}

void decToBin(int n){
    int ris = n/2;
    if(ris == 0)
        cout << n%2;
    else{
        decToBin(ris);
        cout << n%2;
    }
    
}
using namespace std;
#include <iostream>

int main(){
    int n;
    bool primo;
    cout << "Inserisci un numero> ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        primo = true;
        for(int j = 2; j <= i/2 && primo; j++){
            if(i%j == 0)
                primo = false;
        }   
        if(primo)
            cout << i << endl;
    }
}
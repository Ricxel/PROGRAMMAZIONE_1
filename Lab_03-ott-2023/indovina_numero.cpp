using namespace std;
#include <iostream>
#include <cstdlib>

int main(){
    int n;
    srand(time(NULL));
    int r = rand()%10+1;
    bool indovinato = false;

    do
    {
        cout << "inserisci un numero> ";
        cin >> n;
        if(n == r)
            indovinato = true;
    } while (!indovinato);
    cout << "Hai indovinato!" << endl;
    
}
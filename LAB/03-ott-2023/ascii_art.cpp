using namespace std;
#include <iostream>

int main(){
    int h,n_spazi,n_asterischi = 1;
    cout << "Inserisci l'altezza del triangolo> ";
    cin >> h;
    n_spazi = (h*2-1)/2;

    for(int i = 1; i <= h; i++){
        //scrittura spazi
        for(int s = 0; s < n_spazi; s++)
            cout << " ";
        n_spazi -= 1;
        //scrittura asterischi
        for(int a = 0; a < n_asterischi; a++)
            cout << "*";
        n_asterischi += 2;
        cout << endl;
    }

}
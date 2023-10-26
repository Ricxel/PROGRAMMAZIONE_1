using namespace std;
#include <iostream>


void converti(int n, int b, int ris[]);
int main(){
    int n,base;
    bool ok = true;
    int ris[8];
    do{
        if(cin.fail()){
            cout << "Input non valido" << endl;
            cin.clear();
            char c[100];
            cin >> c;
            ok = true;
        }
        if(!ok){
            cout << "I numeri inseriti non sono rappresentabili!" << endl;
        }
        cout << "Inserisci un numero decimale> ";
        cin >> n;
        cout << "Base: ";
        cin >> base;
        if((base == 2 && n > 255) || (base == 8 && n > 16777215) || (base != 8 && base != 2))
            ok = false;
    }while(cin.fail() || !ok);
    converti(n,base,ris);
    for(int n : ris){
        cout << n << " ";
    }
    cout << endl;

}

void converti(int n, int b, int ris[]){
    for(int i = 7; i >= 0; i--){
        ris[i] = n%b;
        n = n/b;
    }
}
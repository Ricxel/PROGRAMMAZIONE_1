using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstring>

int main(){
    int v[10];
    char s[] = "prova di stringa";
    for(int i = 0; i < sizeof(v)/sizeof(v[0]); i++){
        v[i] = i;
    }

    for(int n : v){
        cout << n << ' ';
    }
    cout << endl;
    cout << "Dimensione: " << sizeof(v)/sizeof(v[0]) << endl;
    for(char c : s){
        cout << c;
    }
    cout << endl;

    //lettura interi
    /*
    int n;
    do
    {
        if(cin.fail()){
            char s[100];
            cout << "Errore!" << endl;
            cin.clear();
            cin >> s; //consuma l'input anomalo
        }
        cin >> n;
    } while (cin.fail()); */
    char s2[100];

    cin.getline(s2,100);

    cout << "Dimensione: " << sizeof(s2) << endl;

    cout << s2 << endl << "Lunghezza: " << strlen(s2) << endl;

    
}
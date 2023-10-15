using namespace std;
#include <iostream>

int main(){
    int a,b;
    cout << "Inserisci a e b> ";
    cin >> a >> b;
    if(a > b || a < 0 || b > 127 || cin.fail()){
        cout << "E' stato inserito un carattere non valido." << endl;
        return 1;
    }
    for(int i = a; i <= b; i++){
        cout << (char)i << ' ';
    }
    cout << endl; 
 
}

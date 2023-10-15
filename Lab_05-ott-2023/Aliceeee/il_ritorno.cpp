using namespace std;

#include <iostream>

int main(){
    char a, b;

    cout << "Inserire 2 caratteri per l'intervallo: ";
    cin >> a >> b;
    if(a > b || a < 0 || b > 127)
    {
        cout << "Sei un coglione" << endl;
    }
    else{
        for(int i=a; i<=b; i++){
            cout << (char)i << " ";
        }
        cout << endl;
    }  
    
    return 0;
}
using namespace std;
#include <iostream>
int fattoriale(int n){
    if(n != 1){
        return n*fattoriale(n-1);
    }
    return n;
}
int main(){
	int n;
    do{
		cin.clear();
    	cout << "Inserisci un numero> ";
    	cin >> n;
    }while(n < 0 || cin.fail());
}

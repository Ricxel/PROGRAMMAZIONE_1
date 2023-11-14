using namespace std;
#include <iostream>
int fattoriale(int n){
    if(n != 1){
        return n*fattoriale(n-1);
    }
    return n;
}
int main(){
	int v[4] = {1,2,3,4};

	cout << v[100] << endl;
}

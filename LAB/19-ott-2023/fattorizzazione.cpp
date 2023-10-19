using namespace std;
#include <iostream>

bool is_prime(int n, int i = 2){
    if(n % i == 0 && n != 2)
        return false;
    else{
        if(i <= n/2){
            return is_prime(n,i+1);
        }        
        else return true;
    } 
    
}
void fattorizzazione(int n, int i = 2){
    if(n == 1)
        return;
    if(n % i == 0 && is_prime(i)){
        cout << i << endl;
        fattorizzazione(n/i); 
    }
    else{
        fattorizzazione(n,i+1);
    }
}
int main(){
    int n;
    cout << "n>";
    cin >> n;
    fattorizzazione(n);
}
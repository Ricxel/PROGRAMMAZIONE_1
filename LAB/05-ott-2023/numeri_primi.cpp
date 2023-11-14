using namespace std;
#include <iostream>
bool is_prime(int);
int main(){
    int n,add_1,add_2,tmp;
    bool possibile = false;
    cout << "Inserisci un numero> ";
    cin >> n;

    //calcolo
    for(int i = 1; i <= n/2; i++ ){
        if(is_prime(i)){
            tmp = n - i;
            if(is_prime(tmp)){
                add_1 = tmp;
                add_2 = i;
                cout << "Il numero può essere espresso come: " << add_1 << " + " << add_2 << endl;
                if(possibile == false) 
                    possibile = true;
            }
        }
    }
    
    if(!possibile){
        cout << "Il numero non può essere espresso dalla somma di due numeri primi" << endl;
    }

}
bool is_prime(int n){
    bool primo = true;
    for(int i = 2; i <= n/2 && primo; i++){
        if(n%i == 0)
            primo = false;
    }
    return primo;
}
using namespace std;

#include <iostream>
#include <cmath>

bool primo(int n);

int main(){

    int n, a, b;
    bool found = false;
    cout << "Inserire un valore: ";
    cin >> n;
    cout << primo(n) << endl;
    for(int i=n-1; i>0 && !found; i--)
    {
        if(primo(i)){
            for(int j=1; i+j<=n && !found; j++){
                if(primo(j) && i+j == n)
                {
                    found = true;
                    a = i;
                    b = j;
                }
                
            }
        }
    }

    cout << a << "+" << b << " = " << n << endl;



    return 0;
}

bool primo(int n){
    bool check = true;
    for(int i=2; i<sqrt(n) && check == true; i++)
    {
        if(n%i == 0)
            check = false;
    }

    return check;
}
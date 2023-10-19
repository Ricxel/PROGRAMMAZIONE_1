using namespace std;
#include <iostream>

int massimo_comun_divisore(int,int);
void swap(int &, int &);
int main(){
    int a,b;

    cout << "Inserisci i numeri> ";
    cin >> a >> b;

    int MCD = massimo_comun_divisore(a,b);
    cout << "MCD: " << MCD << endl;
}

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int massimo_comun_divisore(int a, int b){
    if(a < b)
        swap(a,b);
    int dif = a - b;
    if(dif == 0)
        return a;
    else return massimo_comun_divisore(dif,b);
}
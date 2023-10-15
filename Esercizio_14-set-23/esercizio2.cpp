using namespace std;
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath> 
int main(){
    float r;
    cout << "Inserisci il raggio del cerchio> ";
    cin >> r;

    float cir = 2 * M_PI * r;
    float a = pow(r,2)*M_PI;

    cout << "La circonferenza è di: " << cir << endl;
    cout << "L'area è di: " << a << endl;
}
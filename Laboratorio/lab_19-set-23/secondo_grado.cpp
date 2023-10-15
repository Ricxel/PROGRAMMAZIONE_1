using namespace std;
#include <iostream>
#include <cmath>

int main(){
    double a,b,c,delta,x1,x2;
    cout << "a> ";
    cin >> a;
    cout << "b> ";
    cin >> b;
    cout << "c> ";
    cin >> c;

    delta = pow(b,2) - 4*a*c;
    x1 = (-1*b + sqrt(delta))/2*a;
    x2 = (-1*b - sqrt(delta))/2*a;

    cout << "x1: "<< x1 << endl << "x2: " << x2 << endl;



}
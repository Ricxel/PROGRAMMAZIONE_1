using namespace std;
#include <iostream>

int main(){
    int n = 5;
    int n2 = 10;

    cout << "&n: " << &n << endl;
    cout << "&n2: " << &n2 << endl;
    int *p = &n;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    p += 1; //L;/:)
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;

    
}

using namespace std;
#include <iostream>

void provaFun(int v[]);

int main(){
    int *v = new int [20];
    cout << "Main: " << sizeof(v) << endl;
    provaFun(v);
    delete v;
    return 0;
}

void provaFun(int v[]){
    cout << "Fun: " << sizeof(v) << endl;
}
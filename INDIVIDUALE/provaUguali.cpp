using namespace std;
#include <iostream>

int main(){
    int a = 7;
    int b = 5;

    int temp = a-b;
    int max = (a+b)/2 + temp;
    int min = (a+b)/2 - temp;

    cout << max << " " << min << endl;
    /*
    bool uguali = (bool)(a-b);
    bool prova = false;

    cout << uguali << endl;*/
}
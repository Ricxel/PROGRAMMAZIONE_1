using namespace std;
#include <iostream>
#include <cmath>

int binToDec(string);

int main(){
    string bin;
    int dec = binToDec("111011");

    cout << "La conversione è: " << dec << endl;
}

int binToDec(string bin){
    int dec = 0,i;
    int len = bin.size();
    int p = len - 1;
    for(int i = 0; i < len; i++){
        dec += (bin[i]-'0')*pow(2,p);
        p--;
    }
    return dec;
}
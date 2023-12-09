using namespace std;
#include <iostream>
#include "strings.h"

int main(){
    char s[DIM],s2[DIM];
    cout << "Stringa: ";
    cin >> s;
    substring(s,s2,2,3);
    cout << "Ris: " << s2 << endl;

    return 0;
}

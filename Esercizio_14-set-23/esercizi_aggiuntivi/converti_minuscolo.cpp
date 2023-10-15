using namespace std;
#include <iostream>
int main(int argc, char** argv)
{
    cout << "Inserisci un carattere> ";
    char c;
    cin >> c;

    if(c >= 'a' && c <= 'z')
        cout << "Il carattere MAIUSCOLO e': " << (char)(c - 32) << endl;
    else cout << "Il carattere inserito non e' valido" << endl;
}
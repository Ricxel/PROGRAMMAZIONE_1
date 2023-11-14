using namespace std;
#include <iostream>

char convertiMaiusc(char);
bool controllaCarattere(char);

int main(){
    char c;
    do
    {
        cout << "Inserisci un carattere> ";
        cin >> c;
    } while (!controllaCarattere(c));
    char c_maiusc = convertiMaiusc(c);

    cout << "Il carattere in maiuscolo è: " << c_maiusc << endl;
    
}
char convertiMaiusc(char c){
    return c - 32;
}
bool controllaCarattere(char c){
    bool check = true;
    if(c < 'a' || c > 'z')
        check = false;
    return check;
}
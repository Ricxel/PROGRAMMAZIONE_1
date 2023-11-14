using namespace std;
#include <iostream>

void convertiMaiusc(char &);
void convertiMaiusc(char *);
bool controllaCarattere(char);

int main(){
    char c;
    do
    {
        cout << "Inserisci un carattere> ";
        cin >> c;
    } while (!controllaCarattere(c));
    convertiMaiusc(&c);

    cout << "Il carattere in maiuscolo è: " << c << endl;
    
}
void convertiMaiusc(char &c){
    c-=32;
}
void convertiMaiusc(char *c){
    *c-=32;
}
bool controllaCarattere(char c){
    bool check = true;
    if(c < 'a' || c > 'z')
        check = false;
    return check;
}
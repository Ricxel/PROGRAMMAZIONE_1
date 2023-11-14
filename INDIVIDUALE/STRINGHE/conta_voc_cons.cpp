using namespace std;
#include <iostream>
#define DIM 100

int main(){
    char s[DIM];
    cout << "Inserisci una stringa> ";
    cin.getline(s,DIM);

    int contVoc = 0;
    int contCon = 0;

    for(int i = 0; s[i] != '\0'; i++){
        switch(s[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                contVoc++;
                break;
            default: 
                contCon++;
                break;
        }
    }
    cout << "Vocali: " << contVoc << endl
         << "Consonanti: " << contCon << endl;
    return 0;
}
using namespace std;
#include <iostream>

int calcolaQuoz(int, int, int *);

int main(int argc, char** argv)
{
    int n1,n2;

    cout << "Inserisci il primo numero> ";
    cin >> n1;
    cout << "Inserisci il secondo numer> ";
    cin >> n2;

    //int quoz = n1/n2;
    //int resto = n1%n2;

    int resto;
    int quoz = calcolaQuoz(n1,n2,&resto);
    cout << "Il risultato dell'operazione e' " << quoz << " con resto di " << resto << endl;
}

int calcolaQuoz(int n1,int n2, int *resto)
{
    int ris = 0;
    do
    {
        n1 -= n2;
        ris++;
    } while (n1 >= n2);
    
    *resto = n1;
    return ris;
    
}
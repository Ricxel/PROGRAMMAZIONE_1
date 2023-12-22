#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "funzione"
int funzione(int);
// Scrivere qui sopra la dichiarazione e definizione della funzione "funzione"

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function("<< n << ") = " << funzione(n) << std::endl;
}

int pow(int n, int esp){
    if(esp <= 0){
        return 1;
    }
    else return n * pow(n,esp-1);
}
int funzione_aux(int n, int prec){
    if(n > 0){
        int cifra = n%10;
        int somma = 0;
        if(cifra == prec){
            somma = 1;
        }
        return somma + funzione_aux(n/10, cifra);
    }
    return 0;
}

int funzione(int n){
    if(n < 0){
        return 0;
    }
    return funzione_aux(n, -1);
}

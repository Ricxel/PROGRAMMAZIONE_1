#include <iostream>
#include <fstream>
#include "3-email.h"

using namespace std;

int main(int argc, char* argv [])
{

  if (argc != 2)
  {
    cout << "Usage: ./a.out <input_file>" << endl;
    exit(0);
  }

  fstream input;
  input.open(argv[1], ios::in);
  if (input.fail())
  {
    cout << "Il file " << argv[1] << " non esiste!" << endl;
    exit(1);
  }
  
  char parola[256];
  while (input >> parola) {
      if (email(parola)) {
        cout << "Indirizzo: " << parola << endl;
      }
  };

  
    return 0;
}

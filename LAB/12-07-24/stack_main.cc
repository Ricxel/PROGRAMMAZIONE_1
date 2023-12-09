#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    char   scelta;
    stack  s;
    double val;

    init(s);

    do
    {
        cout << "Operazioni possibili: \n"
             << "u : add\n"
             << "o : shrink\n"
             << "t : first\n"
             << "p : print\n"
             << "e : esci\n"
             << "Che operazione vuoi eseguire? ";
        cin >> scelta;

        switch (scelta) {
          case 'u':
              cout << "Valore da inserire? ";
              cin >> val;
              add(s, val);
              break;
          case 'o':

              if (!shrink(s)) {
                  cout << "Stack vuoto! \n";
              }
              else cout << "Shrink ok! \n"; break;
          case 't':

              if (!first(s, val)) {
                  cout << "Stack vuoto! \n";
              }
              else cout << "First: " << val << endl;
              break;
          case 'p':
              cout << "Contenuto dello stack: " << endl;
              print(s);
              break;
          default:

              if (scelta != 'e') {
                  cout << "Operazione non valida: " << scelta << endl;
              }
        }
    } while (scelta != 'e');
    deinit(s);
    return 0;
}

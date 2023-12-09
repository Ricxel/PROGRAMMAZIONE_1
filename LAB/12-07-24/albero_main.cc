#include <iostream>
#include "albero.h"
using namespace std;

int main()
{
    char res;
    Tree tree;
    char val;

    init(tree);

    do {
        cout << "\nperazioni possibili: \n"
             << " Inserimento (i) \n"
             << " Ricerca (r)\n"
             << " Stampa ordinata (s) \n"
             << " Fine (f)\n";
        cout << "Operazione selezionata: ";
        cin >> res;

        switch (res) {
          case 'i':
              cout << "Valore : ";
              cin >> val;

              if (insert(tree, val) == FALSE) {
                  cout << "Valore gia' presente!" << endl;
              }
              break;
          case 'r':
              cout << "Valore: ";
              cin >> val;

              if (search(tree, val) == TRUE) {
                  cout << "Valore presente: " << val << endl;
              } else {
                  cout << "Valore non presente" << endl;
              }
              break;
          case 's':

              if (empty(tree) == TRUE) {
                  cout << "Albero vuoto!" << endl;
              } else {
                  print(tree);
              }
              break;
          case 'f':
              break;
          default:
              cout << "Opzione errata\n";
        }
    } while (res != 'f');
    return 0;
}

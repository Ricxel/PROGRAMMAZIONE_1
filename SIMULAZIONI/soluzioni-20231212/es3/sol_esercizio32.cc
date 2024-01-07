#include <iostream>
#include "pila.h"


using namespace std;


void risolviLabirinto(int [][6], int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
    int labirinto[6][6] = {
        { 1, 0, 1, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0 },
    };

    // E' possibile modificare la cella di arrivo per effettuare dei test (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 2);
   
    return 0;
}


void risolviLabirinto(int labirinto[][6], int x, int y) {
    init();

    cella partenza;
    partenza.indiceRiga = 0;
    partenza.indiceColonna = 0;
    push(partenza);

    
    bool visitata[6][6] = {
        { false, false, false, false, false, false },
        { false, false, false, false, false, false },
        { false, false, false, false, false, false },
        { false, false, false, false, false, false },
        { false, false, false, false, false, false },
        { false, false, false, false, false, false }
    };
    visitata[0][0] = true;
    
 
    while (!vuota()) {

        cella temp;
        top(temp);
        int coordinataX = temp.indiceRiga;
        int coordinataY = temp.indiceColonna;

        if (coordinataX == x && coordinataY == y) {
            while (!vuota()) {
                top(temp);
                cout << "[" << temp.indiceRiga << "," << temp.indiceColonna << "], ";
                pop();
            }
            cout << endl;
        } else {
            if (coordinataX - 1 >= 0 && !visitata[coordinataX-1][coordinataY] && labirinto[coordinataX - 1][coordinataY] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataX-1;
                nuovaCella.indiceColonna = coordinataY;
                push(nuovaCella);
                visitata[coordinataX-1][coordinataY] = true;
            } else if (coordinataX + 1 < 6 && !visitata[coordinataX+1][coordinataY] && labirinto[coordinataX + 1][coordinataY] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataX+1;
                nuovaCella.indiceColonna = coordinataY;
                push(nuovaCella);
                visitata[coordinataX+1][coordinataY] = true;
            } else if (coordinataY - 1 >= 0 && !visitata[coordinataX][coordinataY-1] && labirinto[coordinataX][coordinataY-1] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataX;
                nuovaCella.indiceColonna = coordinataY - 1;
                push(nuovaCella);
                visitata[coordinataX][coordinataY-1] = true;
            } else if (coordinataY + 1 < 6 && !visitata[coordinataX][coordinataY+1] && labirinto[coordinataX][coordinataY+1] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataX;
                nuovaCella.indiceColonna = coordinataY + 1;
                push(nuovaCella);
                visitata[coordinataX][coordinataY+1] = true;
            } 
            else {
                pop();
            }
        }
    }
    deinit();
}
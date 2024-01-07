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


void risolviLabirinto(int labirinto[][6], int j, int k) {
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
        int coordinataJ = temp.indiceRiga;
        int coordinataK = temp.indiceColonna;

        if (coordinataJ == j && coordinataK == k) {
            while (!vuota()) {
                top(temp);
                cout << "[" << temp.indiceRiga << "," << temp.indiceColonna << "], ";
                pop();
            }
            cout << endl;
        } else {
            if (coordinataJ - 1 >= 0 && !visitata[coordinataJ-1][coordinataK] && labirinto[coordinataJ - 1][coordinataK] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ-1;
                nuovaCella.indiceColonna = coordinataK;
                push(nuovaCella);
                visitata[coordinataJ-1][coordinataK] = true;
            } else if (coordinataJ + 1 < 6 && !visitata[coordinataJ+1][coordinataK] && labirinto[coordinataJ + 1][coordinataK] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ+1;
                nuovaCella.indiceColonna = coordinataK;
                push(nuovaCella);
                visitata[coordinataJ+1][coordinataK] = true;
            } else if (coordinataK - 1 >= 0 && !visitata[coordinataJ][coordinataK-1] && labirinto[coordinataJ][coordinataK-1] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ;
                nuovaCella.indiceColonna = coordinataK - 1;
                push(nuovaCella);
                visitata[coordinataJ][coordinataK-1] = true;
            } else if (coordinataK + 1 < 6 && !visitata[coordinataJ][coordinataK+1] && labirinto[coordinataJ][coordinataK+1] == 1) {
                cella nuovaCella;
                nuovaCella.indiceRiga = coordinataJ;
                nuovaCella.indiceColonna = coordinataK + 1;
                push(nuovaCella);
                visitata[coordinataJ][coordinataK+1] = true;
            } 
            else {
                pop();
            }
        }
    }
    deinit();
}
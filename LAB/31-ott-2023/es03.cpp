using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM_R 2
#define DIM_C 2

void inizializza(int mat[DIM_R][DIM_C]);
void stampa_matrice(int mat[DIM_R][DIM_C]);
int somma_triangolo(int mat[DIM_R][DIM_C]);

int main(){
    srand(time(NULL));
    int mat[DIM_R][DIM_C];
    inizializza(mat);
    stampa_matrice(mat);
    int somma = somma_triangolo(mat);
    cout << "Il risultato è: " << somma << endl;
    return 0;
}

void inizializza(int mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++)
        for(int j = 0; j < DIM_C; j++)
            mat[i][j] = rand() % 30 + 1;
}
void stampa_matrice(int mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++){
        for(int j = 0; j < DIM_C; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}
int somma_triangolo(int mat[DIM_R][DIM_C]){
    int somma = 0;
    for(int r = 0; r < DIM_R; r++){
        for(int c = 0; c < DIM_C; c++){
            if(c >= r)
                somma += mat[r][c];
        }
    }
    return somma;
}
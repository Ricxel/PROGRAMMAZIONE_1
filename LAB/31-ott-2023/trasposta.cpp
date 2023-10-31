using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM_R 2
#define DIM_C 4

void inizializza(int mat[DIM_R][DIM_C]);
void stampa_matrice(int mat[DIM_R][DIM_C]);
void stampa_trasposta(int mat[DIM_C][DIM_R]);
void calcola_trasposta(int mat[DIM_R][DIM_C]);

int main(){
    srand(time(NULL));
    int mat[DIM_R][DIM_C];
    inizializza(mat);
    cout << "------MATRICE BASE-----" << endl;
    stampa_matrice(mat);
    calcola_trasposta(mat);
    return 0;
}

void inizializza(int mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++)
        for(int j = 0; j < DIM_C; j++)
            mat[i][j] = rand() % 30 + 1;
}
void stampa_trasposta(int mat[DIM_C][DIM_R]){
    for(int i = 0; i < DIM_C; i++){
        for(int j = 0; j < DIM_R; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}
void stampa_matrice(int mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++){
        for(int j = 0; j < DIM_C; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}
void calcola_trasposta(int mat[DIM_R][DIM_C]){
    int t[DIM_C][DIM_R];
    for(int r = 0; r < DIM_R; r++){
        for(int c = 0; c < DIM_C; c++){
            t[c][r] = mat[r][c];
        }
    }
    cout << "-----MATRICE TRASPOSTA-----" << endl;
    stampa_trasposta(t);
}
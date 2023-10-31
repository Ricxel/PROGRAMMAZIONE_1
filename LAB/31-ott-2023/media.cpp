using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM_R 3
#define DIM_C 3

void inizializza(int mat[DIM_R][DIM_C]);
void stampa_matrice(int mat[DIM_R][DIM_C]);
void filtro_medio(int A[DIM_R][DIM_C], int B[DIM_R][DIM_C]);
int main(){
    srand(time(NULL));
    int A[DIM_R][DIM_C];
    int B[DIM_R][DIM_C];
    for(int i = 0; i < DIM_R; i++){
        for(int j = 0; j < DIM_C; j++){
            B[i][j] = 0;
        }
    }
    inizializza(A);
    stampa_matrice(A);
    filtro_medio(A,B);

    cout << "-----MATRICE FILTRO-----" << endl;
    stampa_matrice(B);
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
void filtro_medio(int A[DIM_R][DIM_C], int B[DIM_R][DIM_C]){
    int somma = 0;
    int media = 0;
    for(int r = 0; r < DIM_R; r++){
        for(int c = 0; c < DIM_C; c++){
            somma = 0;
            if(r >= 1 && r < DIM_R -1 && c >= 1 && c < DIM_C-1){
                somma = A[r-1][c] + A[r][c + 1] + A[r][c - 1] + A[r+1][c];
                media = somma/4;
                B[r][c] = media;
            }
        }
    }
}
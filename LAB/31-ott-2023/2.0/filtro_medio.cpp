using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM_C 3
#define DIM_R 3

void inizializza(int [DIM_R][DIM_C]);
void stampa_matrice(int mat[DIM_R][DIM_C]);
void stampa_matrice(double mat[DIM_R][DIM_C]);
void filtro_medio(int [][DIM_C],double [][DIM_C]);
int main(){
    srand(time(NULL));
    int A[DIM_R][DIM_C];
    double B[DIM_R][DIM_C];
    inizializza(A);
    cout << "-----Matrice A-----" << endl;
    stampa_matrice(A);
    filtro_medio(A,B);
    cout << "-----Matrice B-----" << endl;
    stampa_matrice(B);
    return 0;
}
void inizializza(int mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++)
        for(int j = 0; j < DIM_C; j++)
            mat[i][j] = rand() % 10;
}
void stampa_matrice(int mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++){
        for(int j = 0; j < DIM_C; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}
void stampa_matrice(double mat[DIM_R][DIM_C]){
    for(int i = 0; i < DIM_R; i++){
        for(int j = 0; j < DIM_C; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}
void filtro_medio(int A[][DIM_C],double B[][DIM_C]){
    double somma;
    int cont;
    for(int r = 0; r < DIM_R; r++){
        for(int c = 0; c < DIM_C; c++){
            somma = 0;
            cont = 0;
            if(r >= 1){
                somma += (double)A[r-1][c];
                cont++;
            }
            if(c >= 1){
                somma += (double)A[r][c-1];
                cont++;
            }
            if(r < DIM_R-1){
                somma += (double)A[r+1][c];
                cont++;
            }
            if(c < DIM_C - 1){
                somma += (double)A[r][c+1];
                cont++;
            }
            B[r][c] = (double)somma/cont;
        }
    }
}

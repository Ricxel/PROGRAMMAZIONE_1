using namespace std;
#include <iostream>
#include <cstdlib>
#define DIM_R 10
#define DIM_C 10

void inizializza(int mat[DIM_R][DIM_C]);
void stampa_matrice(int mat[DIM_R][DIM_C]);

int main(){
    srand(time(NULL));
    int mat[10][10];
    inizializza(mat);
    stampa_matrice(mat);
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
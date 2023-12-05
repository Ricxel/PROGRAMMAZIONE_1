using namespace std;
#include <iostream>
#include <cstdlib>

int ** dichiara_matrice(int n_rig, int n_col);
void stampa_matrice(int **m, int n_rig, int n_col);
int ** sotto_matrice(int ** mat, int n_rig, int n_col, int x, int y, int r, int c);
void dealloca_matrice(int ** mat, int n_rig);

int main(int argc, char ** argv){
    if(argc != 3)
    {
        cout << "Parametri non validi" << endl;
        return -1;
    }
    // trovo i valori in input:
    srand(time(NULL));
    int n_righe, n_colonne;
    n_righe = atoi(argv[1]);
    n_colonne = atoi(argv[2]);

    int **mat = dichiara_matrice(n_righe, n_colonne);
    stampa_matrice(mat,n_righe,n_colonne);

    int x,y,r,c;
    cout << "Inserisci le coordinate del punto e le dimensioni della sottomatrice " << endl;
    cin >> x >> y >> r >> c;
    int **sotto_mat = sotto_matrice(mat,n_righe,n_colonne,x,y,r,c);
    stampa_matrice(sotto_mat, r, c);
    
    dealloca_matrice(mat, n_righe);
    dealloca_matrice(sotto_mat, r);

    return 0;
}
int ** dichiara_matrice(int n_rig, int n_col){
    int ** m = new int*[n_rig];
    for(int i = 0; i < n_rig; i++){
        m[i] = new int[n_col];
    }
    for(int r = 0; r < n_rig; r++){
        for(int c = 0; c < n_col; c++){
            m[r][c] = rand() % 10 + 1;
        }
    }
    return m;
}
int ** sotto_matrice(int ** mat, int n_rig, int n_col, int x, int y, int r, int c){
    int ** m_sott = new int*[r];
    for(int i = 0; i < n_rig; i++){
        m_sott[i] = new int[c];
    }
    int k = 0, g = 0;
    for(int i = x; i < n_rig && k < r; i++){
        for(int j = y; j < n_col && g < c; j++){
            m_sott[k][g++] = mat[i][j];
        }
        g = 0;
        k++;
    }
    return m_sott;
}
void stampa_matrice(int **m, int n_rig, int n_col){
    for(int r = 0; r < n_rig; r++){
        for(int c = 0; c < n_col; c++){
            cout << m[r][c] << "\t";
        }
        cout << endl;
    }
}
void dealloca_matrice(int ** mat, int n_rig){
    for(int i = 0; i < n_rig; i++){
        delete[] mat[i];
    }
    delete[] mat;
}
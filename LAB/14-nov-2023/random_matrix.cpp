using namespace std;
#include <iostream>

int ** generate_matrix(int R, int C);

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Errore nei parametri" << endl;
        return -1;
    }
    int r = atoi(argv[1]);
    int c = atoi(argv[2]);

    int ** m = generate_matrix(r,c);

    if(m != NULL){
         for(int i = 0; i < c; i++){
            for(int j = 0; j < c; j++){
                cout << m[i][j] << "\t";
            }  
            cout << endl;
        }
    }
    //deallocazione

    for(int i = 0; i < r; i++){
        delete[] m[i];
    }
    delete[] m;

   
    return 0;
}

int ** generate_matrix(int R, int C){
    int **m = new (nothrow) int*[R];
    if(m == NULL){
        return NULL;
    }
    for(int i = 0; i < R; i++){
        m[i] = new (nothrow) int[C];
        if(m[i] == NULL)
            return NULL;
    }
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            m[r][c] = rand() % 100 + 1;
        }
    }
    return m;
}
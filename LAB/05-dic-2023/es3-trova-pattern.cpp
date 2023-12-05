using namespace std;
#include <iostream>
#include <cstdlib>

void riempi_random(int*, int);
void stampa_vettore(int *, int);
bool trova_pattern(int *, int, int *, int);


const int DIM = 100;
const int DIM_P = 4;
int main(int argc, char ** argv){
    srand(time(NULL));
    //generazione array e pattern: 
    // int v[DIM];
    // int pattern[DIM_P];
    // riempi_random(v,DIM);
    // riempi_random(pattern, DIM_P);

    int v[6] = {4,5,9,1,7,3};
    int pattern[3] = {9,1,8};
    const int DIM = 6;
    const int DIM_P = 3;

    cout << "-----vettore-----" << endl;
    stampa_vettore(v,DIM);
    cout << "-----pattern-----" << endl;
    stampa_vettore(pattern, DIM_P);
    
    bool ris = trova_pattern(v, DIM, pattern, DIM_P);
    cout << "ris: " << ris << endl;

    return 0;
}

void riempi_random(int *v, int len){
    for(int i = 0; i < len; i++){
        v[i] = rand()%10;    
    }
}
void stampa_vettore(int *v, int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
bool trova_pattern(int *v, int len_v, int *pattern, int len_pt){
    int i,j,u;
    bool trovato = false;
    j = i = u = 0;
    while(i < len_v - len_pt && !trovato){
        trovato =  true;
        u = i;
        while(trovato && j < len_pt && u < len_v){
            if(v[u++] != pattern[j++])
                trovato = false;
        }
        j = 0;
        i++;
    }
    return trovato;
}
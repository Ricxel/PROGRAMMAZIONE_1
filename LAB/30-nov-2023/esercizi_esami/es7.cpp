using namespace std;
#include <iostream>
#include <cstdlib>

void riempi_random(int *, int);
void shift(int * &, int, int);
void print_array(int *v, int len);

int main(int argc, char ** argv){
    int j,n;
    cout << "j e n? ";
    cin >> j >> n;
    srand(time(NULL));

    int *v = new int[n];
    riempi_random(v,n);
    print_array(v, n);

    shift(v, n, j);
    print_array(v,n);


    delete[] v;
    return 0;
}

void riempi_random(int *v, int len){
    for(int i = 0; i < len; i++){
        v[i] = rand() % 10 + 1;
    }
}
void ruota(int * &v, int *u, int len, int j, int i = 0){
    if(i > len - 1){
        return;
    }
    int index;
    index = i + j;
    while(index > len - 1)
        index -= len;
    u[index] = v[i];
    ruota(v,u,len,j,i+1);
}
void shift(int * &v, int len, int j){
    int *u = new int[len];
    ruota(v,u,len,j);
    int *del = v;
    v = u;
    delete[] del;
}
void print_array(int *v, int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
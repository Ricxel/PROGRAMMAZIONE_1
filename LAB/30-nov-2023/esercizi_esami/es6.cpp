using namespace std;
#include <iostream>

void shift(char *, int, int);
void print_array(char *, int);
void cpy_array(char *v, char *u, int len);

int main(int argc, char ** argv){
    char A[5] = {'A','Y','U','I','P'};
    print_array(A,5);
    int j;
    cout << "shift? ";
    cin >> j;

    shift(A, 5, j);
    print_array(A,5);
    return 0;
}

void shift(char *v, int len, int j){
    int index;
    char nuovo_array[len];
    for(int i = 0; i < len; i++){
        index = i + j;
        while(index > len - 1){
            index -= len;
        }
        nuovo_array[index] = v[i];
    }
    cpy_array(v,nuovo_array, len);
}
void print_array(char *v, int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void cpy_array(char *v, char *u, int len){
    for(int i = 0; i < len; i++){
        v[i] = u[i];
    }
}
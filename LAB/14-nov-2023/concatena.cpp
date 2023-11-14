using namespace std;
#include <iostream>

void inizializza_vettore(int [], int);
void stampa_vettore(int [], int);
int bubble_sort(int [], int);
int * concatena(int *, int *, int, int);

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri non validi" << endl;
        return -1;
    } 
    srand(time(NULL));
    int na = atoi(argv[1]);
    int nb = atoi(argv[2]);

    int *pa = new int[na];
    int *pb = new int[nb];

    inizializza_vettore(pa,na);
    inizializza_vettore(pb,nb);

    bubble_sort(pa,na);
    bubble_sort(pb,nb);

    cout << "Vettore A: " << endl;
    stampa_vettore(pa,na);

    cout << "Vettore B: " << endl;
    stampa_vettore(pb,nb);

    int *ris = concatena(pa,pb, na, nb);

    cout << "Vettore C: " << endl;
    stampa_vettore(ris,na+nb);

    delete[] pa,pb,ris;
    return 0;
}

void inizializza_vettore(int v[], int len){
    for(int i = 0; i < len; i++){
        v[i] = rand() % 100 + 1;
    }
}
void stampa_vettore(int v[], int len){
    for(int i = 0; i < len; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int bubble_sort(int v[], int len){
    bool ok;
    int i = 0;
    do{
        ok = true;
        for(int i = 0; i < len -1; i++){
            if(v[i] > v[i + 1]){
                swap(v[i], v[i + 1]);
                ok = false;
            }
        }
        i++;
    }while(!ok);
    return i;
}
int * concatena(int *pa, int *pb, int na, int nb){
    int *pc = new (nothrow) int[na+nb];
    if(pc == NULL){
        return NULL;
    }
    int a = 0,b = 0, c = 0;
    while(a < na && b < nb){
        if(pa[a] < pb[b]){
            pc[c] = pa[a];
            a++;
        }
        else{
            pc[c] = pb[b];
            b++;
        }
        c++;
    }
    while(a < na){
        pc[c] = pa[a];
        a++;
        c++;
    }
    while(b < nb){
        pc[c] = pb[b];
        b++;
        c++;
    }
    return pc;
}
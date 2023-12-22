#include <iostream>

using namespace std;

bool * init(int);
void insert(bool *, int, char *);
bool check(bool *, int, char *);
void deinit(bool *);

int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }
    deinit(bloom_filter);

    return 0;
}

bool * init(int n){
    bool *bloom = new bool[n];
    for(int i = 0; i < n; i++)
        bloom[i] = false;
    return bloom;
}
void insert(bool *bloom, int n, char *s){
    int index;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] < n)
            index = s[i];
        else index = s[i]%n;
        bloom[index] = true;
    }
}
bool check(bool *bloom, int n, char *s){
    bool ris = true;
    int index;
    for(int i = 0; s[i] != '\0' && ris; i++){
        if(s[i] < n)
            index = s[i];
        else index = s[i]%n;
        if(bloom[index] == false)
            ris = false;
    }
    return ris;
}
void deinit(bool *bloom){
    delete[] bloom;
}
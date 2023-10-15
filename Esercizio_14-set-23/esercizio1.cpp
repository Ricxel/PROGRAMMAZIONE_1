using namespace std;
#include <iostream>

void printArray(int *);
void stampaDispari(int,int);
int main()
{
    int x = 10;
    int v[x] = {1,4,6,32,12,78,32,56,13,23};
    int n1,n2;
    cout << "Inserisci il primo numero> ";
    cin >> n1;
    cout << "Inserisci il secondo numero> ";
    cin >> n2;

    stampaDispari(n1,n2);
    return 0;
}
void printArray(int* v){
    for(int i = 0; i < sizeof(v);i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void stampaDispari(int n1, int n2){
    if(n1 % 2 == 0)
        n1++;
    do
    {
        cout << n1 << " ";
        n1 += 2;
    } while (n1 <= n2);
    cout << endl;
    
}
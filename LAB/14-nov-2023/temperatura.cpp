using namespace std;
#include <iostream>
#include <fstream>

int bubble_sort(double v[], int len);
void swap(double &a, double &b);

int main(int argc, char ** argv){
    if(argc != 4){
        cout << "Parametri non validi" << endl;
        return -1;
    }
    const int N_TEMP = atoi(argv[2]);
    const int DIM = atoi(argv[3]);
    double *temp = new double[DIM]; //allocazione array
    
    fstream input; //apertura file
    input.open(argv[1],ios::in);
    if(input.fail()){
        cout << "Errore nell'apertura del file" << endl;
        return -2;
    }

    //salvataggio delle temperature nel file nell'array
    int cont;
    for(cont = 0; !input.eof() && !input.fail(); cont++){
        char s[1024];
        input >> s; 
        temp[cont] = atof(s);
    }
    
    //ordino l'array e stampo i primi N_TEMP elementi
    bubble_sort(temp,cont);
    for(int i = 0; i <  N_TEMP; i++){
        cout << temp[i] << " ";
    }
    cout << endl;

    //dealloco e chiudo il file
    input.close();
    delete[] temp; 
    return 0;
}
void swap(double &a, double &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int bubble_sort(double v[], int len){
    bool ok;
    int i = 0;
    do{
        ok = true;
        for(int i = 0; i < len -1; i++){
            if(v[i] < v[i + 1]){
                swap(v[i], v[i + 1]);
                ok = false;
            }
        }
        i++;
    }while(!ok);
    return i;
}
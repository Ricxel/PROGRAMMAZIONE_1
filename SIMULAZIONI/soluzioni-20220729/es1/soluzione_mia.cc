#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

// La funzione non va modificata, pena l'annullamento dell'esercizio
void sort_array(int * array, int len_array) {
  for (int i=0; i<len_array; i++) {
    for (int j=i+1; j<len_array; j++) {
      if (array[i] > array[j]) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main(int argc, char * argv []) {
	if(argc != 4){
    cout << "Parametri errati" << endl;
    return -1;
  }
  fstream in, out;
  in.open(argv[1], ios::in);
  out.open("output.txt", ios::out);

  if(in.fail() || out.fail()){
    cout << "Errore nell'apertura dei file" << endl;
    exit(-2);
  }

  int dim = atoi(argv[2]);
  int *v = new int[dim];
  int n, i = 0;
  
  while(in >> n){
    v[i++] = n;
  }
  
  sort_array(v, dim);
  cout << "Numeri letti: ";
  for(int i = 0; i < dim; i++){
    cout << v[i] << " ";
  }
  cout << endl;

  int lim = atoi(argv[3]);
  for(int i = dim - 1; i >= dim - lim; i--){
    out << v[i] << endl;
  }
  delete[] v;
  in.close();
  out.close();
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cassert>

const int fprecision = 5;

struct list {
  double info;
  struct list * next;
};

void delete_list(list * & l) {
  while(l != NULL) {
    list * t = l;
    l = l->next;
    delete t;
  }
}

void print_list(list * l) {
  std::cout << "The list of taylor terms is: ";
  while(l != NULL) {
    std::cout << std::setprecision(fprecision) << l->info << ((l->next != NULL) ? " " : "");
    l = l->next;
  }
  std::cout << std::endl;
}

double factorial(int N) {
  double result = 1.0;
  for (int i = 2; i <= N; i++) {
    result *= i;
  }
  return result;
}

// Aggiungere qui sotto la dichiarazione della funzione da
// implementare
list * function(float x, int N, double e);
// Aggiungere qui sopra la dichiarazione della funzione da
// implementare


int main(int argc, char **argv) {
  int N = 10;
  double precision = 1e-10;
  double x = 0.0;

  if (argc == 2) {
    x = atof(argv[1]);
  } else if (argc == 3) {
    x = atof(argv[1]);
    N = atoi(argv[2]);
    assert(N > 0);
  } else if (argc == 4) {
    x = atof(argv[1]);
    N = atoi(argv[2]);
    precision = atof(argv[3]);
    assert(N > 0);
    assert(precision >= 0.0);
  } else {
    std::cerr << "Usage: " << argv[0] << " x [N [P]]" << std::endl;
    std::cerr << "x is a double\nN is an optional integer > 0\nP is an optional precision expressed as a double" << std::endl;
    exit(1);
  }

  std::cout << std::setprecision(fprecision) << "x = " << x << std::endl;
  std::cout << "N = " << N << std::endl;
  std::cout << std::setprecision(fprecision) << "precision = " << precision << std::endl;
  list * result = function(x, N, precision);
  print_list(result);
  if (result != NULL) {
    std::cout << std::setprecision(fprecision) << "function(" << x << ") = " << result->info << std::endl;
  }
  delete_list(result);
  return 0;
}

// Aggiungere qui sotto la definizione della funzione da
// implementare

void funzione_aux(list * &l, float x, int N, double e, int i){double
  if(i <= N){
    double val;
    if(l != NULL)
      val = l->info + pow(x, 2*i+1)/factorial(2*i + 1);
    else val = pow(x, 2*i+1)/factorial(2*i + 1);
    // std::cout << "conta: " << i << ' ';

    if(l != NULL){//esiste un precedente, devo fare il controllo
      double a = val - l->info;
      if(a < 0) a *= -1;

      double b = l->info;
      if(b < 0) b *= -1;
      if(a < e * b){
        return;
      }
    }
    list *nuovo_nodo = new list{val, l};
    l = nuovo_nodo;
    funzione_aux(l,x,N,e,i+1);
    
  }

}
list * function(float x, int N, double e){
  list *root = NULL;
  funzione_aux(root, x, N, e, 0);
  return root;
}
// Aggiungere qui sopra la definizione della funzione da
// implementare

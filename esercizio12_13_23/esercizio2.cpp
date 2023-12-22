#include <iostream>
#include <string>

using namespace std;

typedef struct _list {
  int code;
  struct _list * next;
} list;

#define MAXCODE 100
#define MAXDIP 10

// Add hereafter the declaration of estrai
list * estrai(list *l1, list *l2);
// Add here above the declaration of estrai

list * crea_lista(int num) {
  int * a = new int[num];
  for (int i = 0; i < num; i++) {
    a[i] = rand()%MAXCODE + 1;
    for (int j = 0; j < i; j++) {
      if (a[i] == a[j]) { i--; break;}
    }
  }
  list * res = NULL;
  for (int i = 0; i < num; i++) {
    res = new list{a[i], res};
  }
  delete [] a;
  return res;
}

list * crea_l2(list * const l1, const int t = 5) {
  list * res = NULL;
  for (int k = t; k >= 0; k--) {
    for (list * d = l1; d != NULL; d = d->next) {
      if (rand()%2 == 0) {
        res = new list{d->code, res};
      }
    }
  }
  return res;
}

void print_list(list * l, const char * prefix) {
  std::cout << prefix;
  for( ; l != NULL; l = l->next)
    std::cout << " " << l->code;
  std::cout << std::endl;
}

void delete_list(list * & l) {
  while(l != NULL) {
    list * p = l;
    l = l->next;
    delete p;
  }
}

int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
		//
		// Scommentare la linea seguente per avere comportamento
		// deterministico
		//
		srand(0);

  list * l1 = crea_lista(MAXDIP);
  print_list(l1, "Lista L1:");
  list * l2 = crea_l2(l1);
  print_list(l2, "Lista L2:");
  list * l3 = estrai(l1, l2);
  // list * l3 = estrai(l1, NULL);
  print_list(l3, "Lista L3:");
  delete_list(l1);
  delete_list(l2);
  delete_list(l3);
  return 0;
}

int conta_occorrenze(list *l, int n){
  if(l != NULL){
    if(l->code == n){
      return 1 + conta_occorrenze(l->next, n);
    }
    else return conta_occorrenze(l->next, n);
  }
  else return 0;
}
void estrai_aux(list *l1, list *l2, list * &l3){
  list *nuovo_nodo;
  if(l1 != NULL){
    if(l1->code % 2 == 0){
      int n_occ = conta_occorrenze(l2, l1->code);
      nuovo_nodo = new list{n_occ, NULL};
    }
    else {
      nuovo_nodo = new list{-1,NULL};
    }
    // cout << "val: " << nuovo_nodo->code << endl;
    if(l3 == NULL){
      l3 = nuovo_nodo;
      estrai_aux(l1->next, l2, l3);
    }
    else{
      l3->next = nuovo_nodo;
      estrai_aux(l1->next, l2, l3->next);
    }
  }
}
// Add hereafter the definition of estrai
list * estrai(list *l1, list *l2){
  list *l3 = NULL;
  estrai_aux(l1,l2,l3);
  return l3;
}

// Add here above the definition of estrai

#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct _list list;
#define MAXCODE 100
#define MAXDIP 10

struct _list {
  int code;
  list * next;
};

list * crea_lista_dipendenti(int num) {
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

list * crea_e_u(list * const dipendenti, const int t = 5) {
  list * res = NULL;
  for (int k = t; k >= 0; k--) {
    for (list * d = dipendenti; d != NULL; d = d->next) {
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

// Inserire qui sotto la dichiarazione della funzione estrai
// FILL HERE
list * estrai(list *, list *, list *);
// Inserire qui sopra la dichiarazione della funzione estrai

// Inserire qui sotto la dichiarazione della funzione delete_list
// FILL HERE
void delete_list(list * &);
// Inserire qui sopra la dichiarazione della funzione delete_list

int main() {
  srand(unsigned(time(0)));
		//
		// Scommentare la linea seguente per avere comportamento
		// deterministico
		//
		srand(0);

  list * dipendenti = crea_lista_dipendenti(MAXDIP);
  print_list(dipendenti, "Lista dipendenti:");
  list * entrate = crea_e_u(dipendenti);
  print_list(entrate, "Lista entrate:");
  list * uscite = crea_e_u(dipendenti);
  print_list(uscite, "Lista uscite:");
  list * estratti = estrai(dipendenti, entrate, uscite);
  print_list(estratti, "Estratti:");
  delete_list(dipendenti);
  delete_list(entrate);
  delete_list(uscite);
  delete_list(estratti);
}

// Inserire qui sotto la definizione della funzione estrai
// FILL HERE
int conta_occorrenze(list *l, int code){
  if(l == NULL){
    return 0;
  }
  if(l->code == code)
    return 1 + conta_occorrenze(l->next, code);
  else return conta_occorrenze(l->next, code);
}
void inserisci_nodo(list * &l, list *nuovo_nodo){
  l = nuovo_nodo;
}
void estrai_aux(list *dipendenti, list *entrate, list *uscite, list * &estratti){
  if(dipendenti == NULL){
    return;
  }
  int code = dipendenti->code;
  //contare le occorrenze in entrate
  int n_entrate = conta_occorrenze(entrate, code);
  //contare le occorrenze in uscite
  int n_uscite = conta_occorrenze(uscite, code);

  //se sono uguali inserisco in estratti
  if(n_uscite == n_entrate){
    inserisci_nodo(estratti, new list{code, estratti});
  }
  estrai_aux(dipendenti->next, entrate, uscite, estratti);

} 
list * estrai(list *dipendenti, list *entrate, list *uscite){
  list *estratti = NULL;
  estrai_aux(dipendenti, entrate, uscite, estratti);
  return estratti;
}
// Inserire qui sopra la definizione della funzione estrai


// Inserire qui sotto la definizione della funzione delete_list
// FILL HERE
void delete_list(list * &l){
  if(l == NULL){
    return;
  }
  delete_list(l->next);
  delete l;
}
// Inserire qui sopra la definizione della funzione delete_list

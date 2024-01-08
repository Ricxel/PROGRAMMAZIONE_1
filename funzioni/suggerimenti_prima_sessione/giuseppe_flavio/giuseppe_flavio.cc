#include <iostream>
using namespace std;

#include <stdlib.h>

struct node {
  int dato;
  node * next;
};

int main(int argc, char *argv[]) {
  int i;

  if ((argc == 1) || (argc > 3)) {
    cerr << "Uso: " << argv[0] << " <n> <m> " << endl;
    exit(1);
  }

  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  node * t = new node;
  t->dato = 1; t->next = NULL;
  // lista concatenata circolare
  t->next = t;

  node * x = t;
  // riempiamo l'anello
  for (i = 2; i <= N; i++) {
    node * n = new node;
    n->dato = i; n->next = t;
    x->next = n;
    x = x->next;
  }

  // Stampa dell'anello
  cout << "Anello: " << t->dato << " ";
  for (node * l = t->next; l != t; l = l->next) {
    cout << l->dato << " ";
  }
  cout << endl;

  while (x != x->next) {
    // vai all’elemento M-esimo
    for( i = 1; i < M; i++) x = x->next;
    // memorizzazione elemento da rimuovere
    node * t = x->next;
    x->next = x->next->next;
    t->next = NULL;
    // discarding memory for t
    cout << "Rimozione persona: " << t->dato << endl;
    delete t;
  }
  cout << "La persona eletta e': " << x->dato << endl;
  // discarding memory for x
  delete x;
}

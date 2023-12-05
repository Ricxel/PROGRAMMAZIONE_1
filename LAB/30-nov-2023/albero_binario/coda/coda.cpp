#include <iostream>
#include "coda.h"
 
using namespace std;
 
static coda Q;
 
static bool coda_vuota() {
  return (Q.head == NULL);
}
 
 
void coda_init() {
  Q.head = NULL;
}
 
 
bool coda_enqueue(char *s) {
  
    bool risultatoOperazione;
    listaCoda nuovoNodo = new (nothrow) nodoCoda;
    if (nuovoNodo==NULL) {
        risultatoOperazione = false;
    }
    else {
        nuovoNodo->value=s;
        nuovoNodo->next=NULL;
        if (coda_vuota()) {
            Q.head=nuovoNodo;
        }
        else { 
            Q.tail->next=nuovoNodo;
        }
        Q.tail=nuovoNodo;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
 
bool coda_first(char * &s) { 
    bool risultatoOperazione;
    if (coda_vuota()) {
        risultatoOperazione = false;
    }
    else {
        s = Q.head->value;
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
 
bool coda_dequeue() { 
    bool risultatoOperazione;
    if (coda_vuota()) {
        risultatoOperazione = false;
    }
    else {
        listaCoda primoNodo;
        primoNodo = Q.head;
        Q.head = Q.head->next;
        delete primoNodo; 
        risultatoOperazione = true;
    }
    return risultatoOperazione;
}
 
void coda_deinit() {
    char * tmp;
    while(coda_first(tmp)) {
        coda_dequeue();
    }
}
 
void coda_print() {
 
  if (!coda_vuota()) {
    listaCoda nodoCorrente=Q.head;
    do {
      cout << nodoCorrente->value << endl;
      nodoCorrente = nodoCorrente->next;
    } while (nodoCorrente != NULL);
  }
}
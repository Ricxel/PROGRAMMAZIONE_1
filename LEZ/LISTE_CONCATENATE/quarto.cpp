using namespace std;
#include <iostream>
#include <cstdlib>
#include <cassert>

struct nodo {
    int dato;
    nodo* succ;
};

void stampaLista(nodo* q);
void spostaMax(nodo *&q);
void spostaMaxV2(nodo *&q);
int trovaMax(nodo *q);

int main()
{
    //srand(time(NULL));

    nodo *q = NULL;

    for (int i = 0; i < 5; i++)
    {
        nodo *t = new nodo;
        t->dato = rand() % 100;
        t->succ = q;
        q = t;
    }
    nodo *t = new nodo;
    t->dato = 0;
    t->succ = q;
    q = t;
    stampaLista(q);

    // spostaMax(q);
    spostaMaxV2(q);
    stampaLista(q);

    return 0;
}

void stampaLista(nodo* q) {
    int i=0;
    while (q != NULL && i != 10) {
        cout << "Elemento " << ++i << " = " << q->dato << endl;
        q = q->succ;
    }
    cout << endl;
}

void spostaMax(nodo *&q)
{
    int max = trovaMax(q);

    nodo *s = q;
    nodo *t = new nodo;
    t->dato = max;

    //CASO LIMITE: 'max' si trova in cima alla lista ---> rimuovo il primo elemento della lista e
    //inserisco in coda t->dato (dove ho già salvato 'max')
    if (s->dato == max)
    {
        //PROBLEMA
        nodo* p = s;
        s = s->succ;
        delete p;
	// Devo in questo caso propagare informazione che nuovo primo
	// elemento e' il nuovo s!
	q = s;
    }
    else
    {
        //Faccio scorrere la lista finchè nel nodo successivo a quello in cui mi trovo non è presente 'max'
        while (s->succ != NULL && s->succ->dato != max)
        {
            s = s->succ;
        }

        //CASO LIMITE: 'max' si trova in fondo alla lista ---> ritorno la lista com'è
        if (s->succ == NULL)
	  return;

        //Collego il nodo dove è presente 'max' a t...
        t = s->succ;
        //... e lo escludo dalla lista s
        s->succ = s->succ->succ;
    }

    //Scorro la lista finchè non arrivo in coda
    while (s->succ != NULL)
    {
        s = s->succ;
    }

    //Aggiungo il nodo t in coda
    s->succ = t;
    t->succ = NULL;
}

int trovaMax(nodo *q)
{
    int max = 0;
    while (q != NULL)
    {
        if (q->dato >= max)
        {
            max = q->dato;
        }

        q = q->succ;
    }

    return max;
}

void spostaMaxV2(nodo *&q) {
  if ( q != NULL && q->succ != NULL) {
    // Ci sono almeno due elementi
    if (q->dato > q->succ->dato) {
      // Se il primo e' maggiore del secondo inverto in modo che
      // l'elemento piu' grande tra i due sia il secondo.
      nodo * s = q->succ;
      q->succ = q->succ->succ;
      s->succ = q;
      q = s;
    }
    nodo *p_cmax = q; // Puntatore al predecessore del candidato a max
    nodo *c_max = q->succ; // Puntatore al candidato max
    nodo *p = q->succ;  // predecessore del nodo che scorro, comincio
			// dal secondo elemento
    nodo *s = q->succ->succ; // nodo per scorrerere, comincio dal
			     // secondo elemento, infatti qui so che
			     // secondo elemento e' maggiore del primo
    while (s != NULL) { // fintanto che non ho scorso tutta la
			// rimanente parte della lista
      if (s->dato > c_max->dato) { // Se il valore e' maggiore del
				   // candidato max
	// Aggiorno p_max e c_max
	c_max = s;
	p_cmax = p;
      }
      // Aggiorno p ed s
      p = s;
      s = s->succ;
    }
    // A questo punto ho finito c_max punta al max, p punta a
    // penultimo elemento, e p_cmax e' puntatore all'elemento
    // precedente al max
    p_cmax->succ = p_cmax->succ->succ;
    c_max->succ = NULL;
    p->succ = c_max;
  }
}

#ifndef CODA_ARRAY_H
#define CODA_ARRAY_H

// Idea: gli indice della coda sono circolari (quando l'indice supera la dimensione-1 allora viene fatto il modulo dell'indice),
//       vengono mantenuti due interi, t, e h; quando un numero viene inserito si incrementa t, quando un numero viene estratto, 
//       si incrementa h, in questo modo h "rincorre" t

using namespace std;
const int DIM = 256;

struct coda
{
    int *v;
    int h;
    int t;
};
static coda *c = new coda; 

void coda_init();
void coda_enqueue(int n);
void coda_dequeue();
int coda_first();
void coda_deinit();
bool coda_is_empty();
bool coda_is_full();
int coda_n_elementi();
#endif 
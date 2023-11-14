# FUNZIONI PER GLI ARRAY
## 0. `void inizializza_vettore(int v[], int len)`
>Inizializza un vettore di len elementi a valori casuali fra 1 e 100
   ### DIPENDENZE:
   - cstdlib::rand()
## 1. `void stampa_vettore(int v[], int len)`
>Stampa un vettore di len elementi
   ### DIPENDENZE:
   - iostream
## 2. `int bubble_sort(int v[], int len)`
>Ordina un vettore di len elementi e restituisce il numero di iterazioni
   ### DIPENDENZE:
   - number_operations::swap()
## 3. `static bool confronta_rec(int v[], int len, bool ok, int i)`
>Funzione ausiliaria per il bubblesort ricorsivo
   ### DIPENDENZE:
   - number_operations::swap()
## 4. `int bubble_sort_rec(int v[], int len, int i)`
>Bubblesort ricorsivo, ritorna il numero di iterazioni
   ### DIPENDENZE:
   - number_operations::swap()
   - confronta_rec


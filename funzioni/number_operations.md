# OPERAZIONI SUI NUMERI
## 0. `double pow(double a, int n)`
>Calcola a^n^
## 1. `int binToDec(char bin)`
>Ritorna la conversione in decimale del numero binario dato.
   ### DIPENDENZE:
   - pow
## 2. `bool isPrime(int n)`
>Ritorna true se il numero 'n' è primo.
## 3. `int contaCifre(int n)`
>Ritorna il numero di cifre del numero 'n'.
## 4. `bool invertiNumero(int n)`
>Ritorna il numero 'n' invertito.
   ### DIPENDENZE:
   - contaCifre
   - pow
## 5. `int max(int n1, int n2)`
>Ritorna il massimo fra n1 e n2.
## 6. `void swap(int &n1, int &n2)`
>Scambia i due numeri.
## 7. `void confronta(int &n1, int &n2)`
>Confronta i due numeri e li ordina.
   ### DIPENDENZE:
   - max
   - swap
## 8. `void sort(int &n1, int &n2, int &n3)`
>Ordina i 3 numeri in ordine crescente
   ### DIPENDENZE:
   - max
   - swap
   - confronta

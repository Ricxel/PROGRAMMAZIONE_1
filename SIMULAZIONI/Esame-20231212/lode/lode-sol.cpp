#include <iostream>
#include <cstdlib>

using namespace std;

// Possibile funzione di supporto per il calcolo dei valori della
// continued fraction representation.
// NOTA: Qui si assume che n > 0, se n == 0 va in loop infinito
int gcd(int n, int d) {
  while(n != d) {
    if(n > d)
      n -= d;
    else
      d -= n;
  }
  return n;
}

// Inserire qui sotto la dichiarazione e definizione della procedura
// compute_continued_fraction_elements
void compute_continued_fraction_elements(const int num, const int den,
					 int res[], const int res_maxdim,
					 int pos = 0) {
  // Se il numeratore e' zero, allora abbiamo finito.
  if (num == 0) return;
  // Se ho ancora ancora posizioni disponibili, e non ho ancora
  // terminato raggiungendo caso in cui numeratore e' 0
  if (pos < res_maxdim) {
    int i = num/den;
    // Memorize the current continued fraction value in the result
    res[pos] = i;
    // Calcolo i nuovi valori
    int num_f = num - (i * den);
    int den_f = den;
    // Se il nuovo numeratore e' 0, termino ricorsione
    if (num_f == 0) return;
    // Calcolo versione semplificata della frazione usando GCD(n,d)
    int g = gcd(num_f, den_f);
    // Reduced form for num_f/dem_f
    num_f = num_f/g;
    den_f = den_f/g;
    // Attivo ricorsione su frazione inversa
    compute_continued_fraction_elements(den_f, num_f, res, res_maxdim, pos+1);
  }
}
// Inserire qui sopra la dichiarazione e definizione della procedura
// compute_continued_fraction_elements

int main(int argc, char ** argv) {
    if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <numerator_positivenum> <denominator_positivenum>" << std::endl;
    exit(1);
  }
  int num = atoi(argv[1]);
  int den = atoi(argv[2]);
  int res_maxdim = 20;
  int * res = new int[res_maxdim];

  for(int i = 0; i < res_maxdim; i++) res[i] = -1;

  compute_continued_fraction_elements(num, den, res, res_maxdim);

  cout << "The continued fraction representation for "
       << num << "/" << den << " is" << endl;
  for(int i = 0; ((i < res_maxdim) && (res[i] != -1)); i++)
    cout << " " << res[i];
  cout << endl;

  delete res;
}

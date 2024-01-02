#include <iostream>


// Inserire qui sotto dichiarazione funzione compute_pi
double compute_pi(const int N);
// Inserire qui sopra dichiarazione funzione compute_pi

int main(int argc, char ** argv) {


  int N;

  std::cout << "Inserire numero positivo N= ";
  std::cin >> N;

  std::cout << "Valore approssimato serie Leibniz-Madhava(N="
	    << N << ") = " << compute_pi(N) << std::endl;
  return 0;
}


// Inserire definizione di compute_pi qui sotto
double compute_pi_rec(const int N) {
  if (N >= 0) {
    double sign = ((N % 2) == 0) ? 1.0 : -1.0;
    return sign * (1.0/(2.0 * N + 1.0)) + compute_pi_rec(N-1);
  }
  else
    return 0.0;
}

double compute_pi(const int N) {
  if (N < 0) return -1;
  return 4.0 * compute_pi_rec(N);
}


// Inserire definizione di compute_pi qui sopra

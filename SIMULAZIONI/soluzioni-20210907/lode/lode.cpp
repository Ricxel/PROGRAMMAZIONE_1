#include <iostream>


// Inserire qui sotto dichiarazione funzione compute_pi

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


// Inserire definizione di compute_pi qui sopra

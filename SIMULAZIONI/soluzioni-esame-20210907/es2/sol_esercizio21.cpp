#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract(const char[]);
char * extract_rec(const char[], int, int);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char * extract(const char input[]) {
  return extract_rec(input, 0, 0);
}

char * extract_rec(const char input[], int cur, int lun) {
  char * output;
  if (input[cur] == '\0') { // Abbiamo raggiunto fine parola
    // Caso base alloco l'array per memorizzare soluzione
    output = new char[lun + 1]; // +1 per memorizzare fine stringa
    output[lun] = '\0'; // memorizzo fine stringa
  }
  else if (input[cur] == '@') {
    // Passo ricorsivo in cui devo memorizzare, prima scendo in
    // ricorsione per allocare array del risultato, tenendo conto che
    // numero di elementi noto solo quando la stringa e'stata scorsa
    // tutta.
    output = extract_rec(input, cur+1, lun+1);
    output[lun] = '@';
  }
  else {
    // Passo ricorsivo in cui devo semplciemente procedere oltre,
    // scendendo in ricorsione su caratteri rimanenti. Qui non
    // incremento lun, perche' non necessario memorizzare il carattere
    // corrente.
    output = extract_rec(input, cur+1, lun);
  }
  return output;
}
/* Inserire qui sopra la definizione della funzione estract */

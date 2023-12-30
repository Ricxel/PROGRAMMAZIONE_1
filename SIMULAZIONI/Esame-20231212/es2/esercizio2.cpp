#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract(char *);
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
void extract_aux(char *s, char * &ris, int len, int i, int j){
  if(s[i] == '\0'){
    ris = new char[len+1];
    ris[len] = '\0';
    return;
  }
  if(s[i] == '@'){
    extract_aux(s, ris, len+1, i+1, j+1);
    ris[j] = '@';
  }
  else{
    extract_aux(s, ris, len, i+1, j);
  }
}
char * extract(char *s){
  char *ris;
  extract_aux(s, ris, 0, 0, 0);
  return ris;
} 
/* Inserire qui sopra la definizione della funzione estract */

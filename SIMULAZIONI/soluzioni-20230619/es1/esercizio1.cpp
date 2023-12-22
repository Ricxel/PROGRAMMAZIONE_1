#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;

// è possibile definire funzioni di supporto
void shift_string(char *, char *, int);
int conta_occorrenze(char *, char *);

const int DIM = 256;

int main(int argc, char * argv []) {
  if(argc != 2){
    cout << "Parametri non validi" << endl;
    return -1;
  }
  fstream in;
  in.open(argv[1],ios::in);

  if(in.fail()){
    cout << "Errore nell'apertura dei file" << endl;
    exit(-2);
  }

  //richiesta della parola:
  char s[DIM],s_shiftata[DIM];
  int n;

  cout << "s>";
  cin >> s;
  cout << "n> ";
  cin >> n;

  //shifting
  shift_string(s,s_shiftata,n);
  
  cout << "Stringa shiftata: " << s_shiftata << endl;

  //contare le occorrenze
  char buffer[DIM];
  int ris = 0;
  while(in >> buffer){
    //conta le occorrenze della stringa in ciascuna parola e poi le somma al totale delle occorrenze
    ris += conta_occorrenze(buffer, s_shiftata);
  }

  cout << "Numero di occorrenze: " << ris << endl;
  in.close();
  return 0;

}
void shift_string(char *s, char *s_shiftata, int n){
  int len = strlen(s);
  s_shiftata[len] = '\0';
  n %= len;
  int index;
  for(int i = 0; i < len; i++){
    index = (i+n)%len;
    s_shiftata[index] = s[i];
  }
}
int conta_occorrenze(char *s, char *pattern){
  int cont = 0, j = 0, k;
  bool ok = true;
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == pattern[0]){
      ok = true;
      j = 0;
      k = i;
      while(ok && s[k] != '\0' && pattern[j] != '\0'){
        if(s[k++] != pattern[j++])
          ok = false;
      }
      if(ok && pattern[j] == '\0') cont++;
    }
  }
  return cont;
}
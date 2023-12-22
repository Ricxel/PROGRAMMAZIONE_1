#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire proprie funzioni
bool is_letter(char c){
  return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
void trim(char * &s, char *testa, char *coda){
  //taglio la testa
  bool finetesta = false;
  int j = 0;
  for(int i = 0; s[i] != '\0' && !finetesta; i++){
    if(!is_letter(s[i]))
    {
      cout << s[i];
      testa[j++] = s[i];
      char *canc = s;
      s = s+1;
      delete canc;
    }
    else finetesta = true;
  }
  testa[j] = '\0';
  //faccio andare i fino all'ultima lettera valida
  int i;
  int len_coda = 0;
  for(i = strlen(s) - 1; i >= 0 && !is_letter(s[i]); i--){
    len_coda++;
  }
  //taglio la coda
  j = 0;
  bool finecoda = false;
  for(;j < len_coda; i++){
    if(!is_letter(s[i])){
      coda[j++] = s[i];
      s[i] = '\0';
    }
    else finecoda = true;
  }
  coda[j] = '\0';
  cout << s << endl;
  cout << "testa: " << testa << endl;
  cout << "coda: " << coda << endl;
  
}

int main(int argc, char * argv []) {
  
  fstream in, out;
  int n;
  char *s = new char[256];
  // inserire qui il codice
  if(argc != 3){
    cout << "Parametri inseriti non validi" << endl;
    exit(-1);
  }

  //inserimento del numero di shifting
  do
  {
    if(cin.fail()){
      char buffer[1024];
      cin.clear();
      cin >> buffer;
    }
    cout << "Inserisci il numero di shifting> ";
  } while (!(cin >> n));
  char coda[256], testa[256];
  in.open(argv[1], ios::in);
  while(in >> s){
    trim(s, testa, coda);
    // shift(s,n);
  }

  cout << "dealloco s" << endl;
  delete[] s;
  return 0;

}

#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto

bool controlla(char *s, char c);
int main(int argc, char * argv []) {
  
  // inserire qui il codice
  if(argc != 2){
    cout << "Parametri non validi" << endl;
    return -1;
  }
  fstream in;
  in.open(argv[1], ios::in);

  if(in.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return -2;
  }
  const int DIM = 256;
  char s[DIM];
  char c;
  cin >> noskipws;

  cout << "Inserisci una stringa> ";
  cin.getline(s, DIM);

  in >> noskipws;
  while(in >> c){
    if(controlla(s, c))
      cout << c;
  }
  cout << endl;
  in.close();
  return 0;

}
bool controlla(char *s, char c){
  bool ris = false;
  for(int i = 0; i < strlen(s) && !ris; i++){
    if(tolower(s[i]) == tolower(c))
      ris = true;
  }
  return ris;
}
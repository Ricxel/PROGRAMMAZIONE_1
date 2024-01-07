#include <iostream>
#include <fstream>
using namespace std;

const int DIM = 100;

bool verifica_parola(char *);

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Parametri non validi" << endl;
    return -1;
  }
  fstream in,out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return -2;
  }

  char buffer[DIM];

  while(in.getline(buffer,DIM)){
    if(!verifica_parola(buffer)){
      out << buffer << '\n';
    }
  }

  in.close();
  out.close();
  return 0;
}

bool verifica_parola(char *buffer){
  bool ris = true, prox_I = true;
  int cont_i = 0;
  int i;
  for(i = 0; buffer[i] != '\0' && ris; i++){
    if(buffer[i] == 'U' && !prox_I)
      prox_I = true;
    else if(buffer[i] == 'M')
      prox_I = false;
    else if(buffer[i] == 'I' && prox_I)
      cont_i++;
    else if(buffer[i] == 'I' && !prox_I)
      ris = false;
    
  }
  //controllo prima lettera
  if(buffer[0] == 'U' && buffer[i-1] != 'M')
    ris = false;

  //controllo numero i
  if(cont_i != 0 && cont_i % 2 != 0)
    ris = false;
  return ris;
}

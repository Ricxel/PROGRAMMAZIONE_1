#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Parametri invalidi" << endl;
    return -1;
  }
  fstream in,out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()){
    cout << "Errore nell'apertura dei file" << endl;
    return -2;
  }
  char c;
  bool prox_maiusc = false;
  const int OFFSET = 'a' - 'A';

  //controllo prima lettera
  if(in.get(c)){
    if(c >= 'a' && c <= 'z')
      c -= OFFSET;
  }
  out.put(c);

  while(in.get(c)){
    if(c == '.' || c == '!' || c == '?')
      prox_maiusc = true;
    if(c >= 'a' && c <= 'z' && prox_maiusc){
      c -= OFFSET;
      prox_maiusc = false;
    }
    out.put(c);
  }
  return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool is_minuscola(char c){
  bool ris = false;
  if(c >= 'a' && c <= 'z')
    ris = true;
  return ris;
}
int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Parametri errati..." << endl;
    return -1;
  }
  fstream in,out;
  in.open(argv[1],ios::in);
  out.open(argv[2],ios::out);
  
  if(in.fail() || out.fail()){
    cout << "Problema nell'apertura dei file..." << endl;
    exit(-2);
  }
  char c;
  bool controlla = false;
  const int OFFSET = 'a' - 'A';
  if(in.get(c)){
    if(is_minuscola(c))
      out.put(c-OFFSET);
  }
  while(in.get(c)){
    if(c == '.' || c == '!' || c == '?'){
      controlla = true;
      out.put(c);
      //salta spazio o nuova linea
      in.get(c);
      out.put(c);
    }
    else if(controlla == true){
      if(is_minuscola(c)){
        c -= OFFSET;
      }
      out.put(c);
      controlla = false;
    }
    else{
      out.put(c);
    }
  }



  in.close();
  out.close();
  return 0;
}

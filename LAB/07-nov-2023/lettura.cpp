using namespace std;
#include <iostream>
#include <fstream>
int main(int argc, char ** argv){
  //verifica parametro
  if(argc != 2){
    cout << "Parametri non soddisfatti" << endl;
    return -1;
  }
  cout << "Nome del file: " << argv[1] << endl;
  fstream finput;
  finput.open(argv[1],ios::in);
  //verifica apertura file
  if(finput.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return -1;
  }
  char s[1024];
  while(!finput.eof() && !finput.fail()){
    finput.getline(s,1024);
    cout << s << endl;
  }
  finput.close();
  return 0;
}

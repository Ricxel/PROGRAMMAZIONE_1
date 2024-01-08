#include <iostream>
#include <fstream>
using namespace std;

int conta_caratteri(char *s);
void scorri_parole(fstream &in, fstream &out);
const int DIM = 101;
int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Parametri errati" << endl;
    return -1;
  }
  fstream in,out;

  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()){
    cout << "Errore nell'apertura dei file." << endl;
    return -2;
  }

  scorri_parole(in,out);
  
  in.close();
  out.close();
  return 0;
}
int conta_caratteri(char *s){
  int cont = 0;
  while(s[cont] != '\0'){
    cont++;
  }
  return cont;
}
void scorri_parole(fstream &in, fstream &out){
  char buffer[DIM];
  if(in >> buffer){
    scorri_parole(in, out);
    if(conta_caratteri(buffer) % 2 == 0){
      out << buffer << " ";
    }
  }
}
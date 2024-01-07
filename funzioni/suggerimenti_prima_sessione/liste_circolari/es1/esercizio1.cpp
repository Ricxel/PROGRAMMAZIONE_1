#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire proprie funzioni
bool is_letter(char c){
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return true;
  else return false;
}
const int DIM = 256;
int main(int argc, char * argv []) {
  
  if(argc != 3){
    cout << "Parametri non validi" << endl;
    return -1;
  }

  fstream in,out;
  in.open(argv[1], ios::in);
  out.open(argv[2],ios::out);

  if(in.fail() || out.fail()){
    cout << "Errore nell'apertura di file" << endl;
    exit(-2);
  }

  int n_shift = 1;
  char buffer[DIM];
  int indiceSx = 0, indiceDx = 0;
  while(in >> buffer){
    int len = strlen(buffer);
    indiceSx = 0;
    indiceDx = len-1;
    n_shift %= len;
    //isolo la parola dalla testa
    for(int i = 0; buffer[i] != '\0' && !is_letter(buffer[i]); i++){
      indiceSx++;
    }
    //isolo la parola dalla coda
    for(int i = len-1; i >= 0 && !is_letter(buffer[i]); i--){
      indiceDx--;
    }
    //stampo stringa senza testa e coda
    // cout <<endl;
    // cout << "IndiceSx: " << indiceSx << endl;
    // cout << "IndiceDx: " << indiceDx << endl;
    // for(int i = indiceSx; i <= indiceDx; i++){
    //   cout << buffer[i];
    // }
    // cout << endl;
    //faccio lo shift
    char tmp[DIM];
    int k = 0;
    int index;
    int leng = indiceDx - indiceSx + 1;
    n_shift %= leng;
    tmp[leng] = '\0';
    for(int i = indiceSx; i <= indiceDx; i++){
      int index = k - n_shift;
      if(index < 0){
        index = leng + index;
      }
      tmp[index] = buffer[i];
      k++;
    }
    //converto in minuscola
    for(int i = 0; i < leng; i++){
      if(tmp[i] >= 'A' && tmp[i] <= 'Z')
        tmp[i] += 'a' - 'A';
    }
    //stampo la stringa shiftata
    // for(int i = 0; tmp[i] != '\0';i++){
    //   cout << tmp[i];
    // }
    // cout << endl;
    //copio la stringa
    int j = 0;
    for(int i = indiceSx; buffer[i] != '\0' && i <= indiceDx; i++){
      buffer[i] = tmp[j++];
    }
    out << buffer << ' ';
  }

  in.close();
  out.close();
  return 0;

}

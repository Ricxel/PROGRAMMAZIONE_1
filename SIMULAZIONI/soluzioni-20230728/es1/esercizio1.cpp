#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto

const int DIM = 256;
bool check(char *s, char *pattern){
  int i;
  bool ok = true;
  for(i = 0; s[i] != '\0' && pattern[i] != '\0' && ok;i++){
    if(pattern[i] == '*')
      continue;
    else if(pattern[i] != s[i]){
      ok = false;
    }
  } 
  if(s[i] != '\0' || pattern[i] != '\0')
    ok = false;
  return ok;
}
int main(int argc, char * argv []) {
  
  // inserire qui il codice
  if(argc != 2){
    cout << "Parametri errati" << endl;
    return -1;
  }
  fstream in;
  in.open(argv[1], ios::in);

  if(in.fail()){
    cout << "Errore nell'apertura del file" << endl;
    return -2;
  }
  char pattern[DIM];
  cout << "pattern> ";
  cin >> pattern;

  char buffer[DIM];
  while(in >> buffer){
    if(check(buffer, pattern))
      cout << buffer << endl;
  }

  return 0;

}

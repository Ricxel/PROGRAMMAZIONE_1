#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto

const int DIM = 256;
void shift(char *s, char *s_shiftata, int n_shift);
void minuscola(char *s, char *s_min);
int conta_occorrenze(char *s, char *source);
int main(int argc, char * argv []) {
  
  // inserire qui il codice
  if(argc != 2){
    cout << "Parametri errati" << endl;
    exit(-1);
  }

  fstream in;
  
  //chiedo la stringa
  char s[DIM];
  cout << "s? ";
  cin >> s;

  //chiedo il numero di shifting
  int n_shift;

  do
  {
    cout << "n? ";
    if(cin.fail()){
        char buffer[DIM];
        cin >> buffer;
        cin.clear();
    }
  } while (!(cin >> n_shift));
  //converto in minuscola
  char s_min[DIM];
  minuscola(s,s_min);

  char s_shiftata[DIM];
  shift(s_min,s_shiftata,n_shift);

  cout << "Stringa shiftata: " << s_shiftata << endl;

  //ricerca nel file
  char buffer[DIM];
  int ris = 0;
  in.open(argv[1], ios::in);

  if(in.fail()){
    cout << "Errore nell'apertura del file" << endl;
    exit(-2);
  }

  while(in >> buffer){
    ris += conta_occorrenze(s_shiftata, buffer);
  }

  cout << "n_occorrenze: " << ris << endl;

  in.close();
  return 0;

}
void shift(char *s, char *s_shiftata, int n_shift){
    int len = strlen(s);
    n_shift %= len;
    int i;
    for(i = 0; i < len; i++){
        int index = i - n_shift;
        if(index < 0){
            index = len + index;
        }
        s_shiftata[index] = s[i];
    }
    s_shiftata[i] = '\0';
}
void minuscola(char *s, char *s_min){
    int len = strlen(s);
    const int OFFSET = 'a' - 'A';
    char c;

    for(int i = 0; i <= len; i++){
        c = s[i];
        if(c >= 'A' && c <= 'Z'){
            c += OFFSET;
        }
        s_min[i] = c;
    }
    cout << s_min << endl;
}
int conta_occorrenze(char *s, char *source){
    int len = strlen(source);
    int cont = 0;
    int i = 0;
    int j = 0;
    bool ok;
    for(i = 0; i < len; i++){
        ok = true;
        if(source[i] == s[0]){
            int k = i;
            j = 0;
            while(source[k] != '\0' && ok && s[j] != '\0'){
                cout << s[j] << ' ' <<  source[k] << "|";
                if(source[k] != s[j]){
                    ok = false;
                }
                k++;
                j++;
            }
            if(ok && s[j] != '\0'){
                ok = false;
            }
            if(ok)
                cont++;
        }
    }
    return cont;
}
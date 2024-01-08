#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

int converti_a_dec(char *s, int base);
int operazione(int a, int b, char op);

const int DIM = 11;
int main(int argc, char **argv){
    if(argc != 2){
        cout << "Parametri errati" << endl;
        return -1;
    }

    fstream in, out;
    in.open(argv[1], ios::in);
    out.open("output.txt",ios::out);

    if(in.fail() || out.fail()){
      cout << "Errore nell'apertura del file" << endl;
      return -2;
    }

    char a[DIM];
    char b[DIM];
    char op;

    while(in >> a && in >> op && in >> b){
      int aInt = converti_a_dec(a, 17);
      int bInt = converti_a_dec(b, 17);

      int ris = operazione(aInt, bInt, op);
      out << ris << endl;
    }


    in.close();
    out.close();
    return 0;
}
int converti_a_dec(char *s, int base){
    int cifra;
    int ris = 0;
    int len = strlen(s);
    int esp = 0;
    for(int i = len-1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9')
            cifra = s[i] - '0';
        else if(s[i] >= 'A' && s[i] <= 'Z')
            cifra = s[i] - 'A' + 10;
        else if(s[i] >= 'a' && s[i] <= 'z')
            cifra = s[i] - 'a' + 10;
        ris += pow(base, esp++) * cifra;
    }
    return ris;
}
int operazione(int a, int b, char op){
  int ris;
  switch (op)
  {
  case '+':
    ris = a + b;
    break;
  case '*':
    ris = a*b;
    break;
  case '^':
    ris = pow(a,b);
    break;
  default:
    ris = -1;
    break;
  }
  return ris;
}
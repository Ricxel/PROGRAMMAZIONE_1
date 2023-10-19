using namespace std;
#include <iostream>

double prodottoScalare(double[], double[], int);
bool checkOrtogonali(double[], double[], int);

int main(){
  int len = 4;
  double v1[] = {0,0,0,0};
  double v2[] = {0,0,0,0};
  cout << "checkOrtogonali: " << checkOrtogonali(v1,v2,len);
}

double prodottoScalare(double v1[], double v2[], int len){
  double ris = 0;

  for(int i = 0; i < len ; i++)
    ris += v1[i] + v2[i];

  return ris;
}
bool checkOrtogonali(double v1[], double v2[], int len){
  if(prodottoScalare(v1,v2,len) == 0){
    return true;
  }
  else return false;
}
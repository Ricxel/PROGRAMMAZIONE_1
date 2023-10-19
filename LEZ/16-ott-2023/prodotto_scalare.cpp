using namespace std;
#include <iostream>

double prodottoScalare(double[], double[], int);

int main(){
  double v1[] = {3,6,2,8};
  double v2[] = {2,8,5,1};
  double ris = prodottoScalare(v1,v2,4);
  cout << "Il prodotto scalare è: " << ris << endl;
}

double prodottoScalare(double v1[], double v2[], int len){
  double ris = 0;

  for(int i = 0; i < len ; i++)
    ris += v1[i] + v2[i];

  return ris;
}

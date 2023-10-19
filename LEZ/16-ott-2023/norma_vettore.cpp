using namespace std;
#include <iostream>
#include <cmath>  
double prodottoScalare(double[], double[], int);
double calcoloNorma(double[],int);
int main(){
  int len = 2;
  double v[] = {3,4};
  double norma;

  norma = calcoloNorma(v,len);
  cout << "La norma del vettore è: " << norma << endl;
}

double prodottoScalare(double v1[], double v2[], int len){
  double ris = 0;

  for(int i = 0; i < len ; i++)
    ris += v1[i] + v2[i];

  return ris;
}

double calcoloNorma(double v[], int len){
  double prodotto = prodottoScalare(v,v,len);
  double norma = sqrt(prodotto);

  return norma;
} 

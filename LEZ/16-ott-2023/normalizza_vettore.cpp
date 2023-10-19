using namespace std;
#include <iostream>
#include <cmath>  
void stampaVettore(double[], int);
double prodottoScalare(double[], double[], int);
double calcoloNorma(double[],int);
void normalizzaVettore(double[],int);
int main(){
  int len = 2;
  double v[] = {3,4};
  double norma;
  stampaVettore(v,len);
  
  normalizzaVettore(v,len);

  stampaVettore(v,len);
}

void stampaVettore(double v[], int len){
  for(int i = 0; i < len; i++)
    cout << v[i] << " ";
  cout << endl;
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
void normalizzaVettore(double v[], int len){
  double norma = calcoloNorma(v,len);

  for(int i = 0; i < len; i++){
    v[i] /= norma;
  }
}
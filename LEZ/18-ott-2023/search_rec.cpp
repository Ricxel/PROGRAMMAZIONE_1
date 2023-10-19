using namespace std;
#include <iostream>

int search(int [], int, int, int = 0);
int bin_search(int [], int, int, int, int);

int main(){
  int v[] = {1,2,3,4,5,6,7,8,9,10,11};
  int dim = sizeof(v)/sizeof(int);

  cout << "n> ";
  int n;
  cin >> n;

  int address =  bin_search(v,dim,n,0,dim-1);

  cout << "Il valore è all'indirizzo: " << address << endl;

}

int search(int v[], int len, int target, int cont){
  if(cont < len){
    if(v[cont] == target){
      return cont;
    }
    return search(v,len,target,cont+1);
  }
  else
    return -1;
}
int bin_search(int v[], int len, int target, int left, int right){
  int somma = (right+left);
  int pivot;
  if(somma % 2 == 0)
    pivot = somma;
  else pivot = somma + 1;

  cout << pivot << endl;
  if(left > right){
    return -1;
  }
  if(v[pivot] == target)
    return pivot;
  else{
    if(v[pivot] > target)
      right = pivot;
    else left = pivot;
    return bin_search(v,len,target,left,right);
  }
  
}
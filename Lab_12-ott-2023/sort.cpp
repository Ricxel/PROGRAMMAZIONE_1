using namespace std;
#include <iostream>
#include <cstdlib>

void swap(int &, int &);
int max(int,int);
void confronta(int&,int&);
void sort(int &, int &, int &);

int main(){
	int n1,n2,n3;
	cout << "Inserisci 3 numeri> ";
	cin >> n1 >> n2 >> n3;
	sort(n1,n2,n3);

	cout << "I numeri in ordine sono> " << n1 << " " << n2 << " " << n3 << endl;
}

void swap(int &n1, int &n2){
	int tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
}
int max(int n1, int n2){
	return n1 > n2 ? n1 : n2;
}
void confronta(int &n1, int &n2){
	if(max(n1,n2) == n1){
		swap(n1,n2);
	}
}
void sort(int &n1, int &n2, int &n3){
	confronta(n1,n2);
	confronta(n2,n3);
	confronta(n1,n2);
}

using namespace std;
#include <iostream>
#include <cstdlib>

void inizializzaRandom();
void tiraDado(int &);
int max(int, int);

void swap(int &, int &);
int max(int,int);
void confronta(int&,int&);
void sort(int &, int &, int &);

int main(){
	int dado1_A, dado2_A, dado3_A;
	int dado1_D, dado2_D, dado3_D;

	inizializzaRandom();

	tiraDado(dado1_A);
	tiraDado(dado2_A);
	tiraDado(dado3_A);

	sort(dado1_A, dado2_A, dado3_A);

	tiraDado(dado1_D);
	tiraDado(dado2_D);
	tiraDado(dado3_D);

	sort(dado1_D, dado2_D, dado3_D);

	int countA = 0;
	int countD = 0;

	if(dado1_A > dado1_D)
		countA++;
	else countD++;

	if(dado2_A > dado2_D)
		countA++;
	else countD++;

	if(dado3_A > dado3_D)
		countA++;
	else countD++;

	cout << "Scontri vinti dall'attaccante: " << countA << endl;
	cout << "Scontri vinti dal difensore: " << countD << endl;

	
	
	
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
void inizializzaRandom(){
	srand(time(NULL));
}
void tiraDado(int & dado){
	dado = rand() % 6 + 1;
}

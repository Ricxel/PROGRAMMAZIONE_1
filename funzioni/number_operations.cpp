#include "number_operations.h"
double pow(double a, int n){
    double ris = 1;
    for(int i = 1; i <= n; i++){
        ris *= a;
    }
    return ris;
}
int binToDec(char * bin){
    int dec = 0,i;
    int len = 0;
    for(int i = 0; bin[i] != '\0'; i++){
        len++;
    }
    int p = len - 1;
    for(int i = 0; bin[i] != '\0' && i < len; i++){
        dec += (bin[i]-'0')*pow(2,p);
        p--;
    }
    return dec;
}
bool is_prime(int n){
    bool primo = true;
    for(int i = 2; i <= n/2 && primo; i++){
        if(n%i == 0)
            primo = false;
    }
    return primo;
}
int contaCifre(int n){
    int count = 0;
    do
    {
        n /= 10;
        count++;
    } while (n > 0);
    return count;
}
int invertiNumero(int n){
    //cout << "Conta cifre: " << contaCifre(n) << endl;
    int n_inv = 0;
    for(int i = contaCifre(n) - 1; i >= 0; i--){
        n_inv += (n%10)*pow(10,i);
        n /= 10;
    }
    
    return n_inv;
}
int max(int n1, int n2){
	return n1 > n2 ? n1 : n2;
}
void swap(int &n1, int &n2){
	int tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
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
int custom_atoi(const char* str) {
    int result = 0;
    int sign = 1;
    size_t i = 0;

    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        ++i;
    }

    return sign * result;
}
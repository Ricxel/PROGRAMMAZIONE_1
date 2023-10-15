using namespace std;
#include <iostream>
#include <cstring>
#include <cmath>

int main(int argc, char* argv[]){
    float r;
    cout << "Inserisci il raggio del cerchio> ";
    cin >> r;
    
    //calcolo vaolume sfera
    float vol = (float)4/3*M_PI*pow(r,3);
    cout << "Il volume della sfera e': " << vol << endl; 

}
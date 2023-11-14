using namespace std;
#include <iostream>

int main(){
    int ore,min,sec;
    cout << "Inserisci i secondi da mezzanotte> ";
    cin >> sec;

    ore = sec/3600;
    sec -= ore * 3600;
    min =sec/60;
    sec -= min*60;

    cout << "ore: " << ore << ":" << min << ":" << sec << endl;
}
using namespace std;
#include <iostream>
#include <fstream>
#define DIM 1024

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri errati" << endl;
        return -1;
    }
    
    //apertura stream
    fstream input, output;
    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);
    if(input.fail()){
        cout << "Il file di input non esiste" << endl;
        return 0;
    }
    char c;
    while(!input.eof() && !input.fail() && !output.fail()){
        input.get(c);
        output.put(c);
    }
    cout << "fine copia" << endl;
    return 0;
}
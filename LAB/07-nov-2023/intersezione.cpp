using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#define DIM 100

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri errati" << endl;
        return -1;
    }
    fstream inA,inB,out;
    inA.open(argv[1],ios::in);
    inB.open(argv[2],ios::in);
    out.open("output.txt",ios::out);

    if(inA.fail() || inB.fail() || out.fail()){
        cout << "Errore nell'apertura dei file" << endl;
        return -1;
    }

    char s1[DIM],s2[DIM];

    for(int cont = 0; cont < 1000 && !inA.fail()  && !out.fail(); cont++){
        inA >> s1;
        for(int i = 0; i < 1000 && !inB.fail() && !out.fail(); i++ ){
            inB >> s2;
            cout << s1 << "=" << s2 << endl;
            if(strcasecmp(s1,s2) == 0)
                out << s1 << endl;
        }
        inB.clear();
        inB.seekg(0,std::ios::beg);
    }
    cout << "Fine..." << endl;
    inA.close();
    inB.close();
    out.close();
    return 0;
}
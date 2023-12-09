using namespace std;
#include <iostream>
#include <fstream>

bool check(char *, int = 0);

int main(int argc, char ** argv){
    if(argc != 2){
        cout << "Parametri invalidi" << endl;
        return -1;
    }
    fstream in;
    in.open(argv[1], ios::in);
    if(in.fail()){
        cout << "Errore nell'apertura del file" << endl;
        return -2;
    }
    char buffer[128];
    bool ok = true; // false quando non è un codice di carta di credito
    int cont = 0; //contatore di numeri di carte di credito
    while(in >> buffer){
        if(check(buffer)){ //se trovo 4 numeri validi
            //controllo le 3 stringhe dopo
            ok = true;
            for(int i = 0; i < 3 && ok; i++){
                if(in >> buffer){
                    if(!check(buffer))
                        ok = false;
                }
                else ok = false;
            }   
            if(ok)
                cont++;
        }
    }
    cout << "Nel file ci sono " << cont << " numeri di carte di credito " << endl;
    in.close();
    return 0;
}
bool check(char *s, int i){
    if(*s == '\0'){
        if(i == 4)
            return true;
        else return false;
    }
    if(*s < '0' || *s > '9' || i > 3){
        return false;
    }
    else return check(s + 1,i+1);
}
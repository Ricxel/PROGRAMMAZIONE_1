using namespace std;
#include <iostream>
#include <fstream>

bool is_minuscolo(char c);
bool copia_testo(char *fn_in, char *fn_out);

const int OFFSET = 'a' - 'A';
int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Invalid parameters" << endl;
        return -1;
    }
    bool ris = copia_testo(argv[1], argv[2]);
    if(ris){
        cout << "Operazione riuscita" << endl;
    }
    else cout << "Operazione non riuscita" << endl;
    return 0;
}

bool is_minuscolo(char c){
    bool minuscolo = false;
    if(c >= 'a' && c <= 'z')
        minuscolo = true;
    return minuscolo;
}
//copia il testo corretto, fn_in = filename_input, fn_out = filename output
bool copia_testo(char *fn_in, char *fn_out){
    fstream in,out;

    in.open(fn_in, ios::in);
    out.open(fn_out, ios::out);

    if(in.fail() || out.fail()){
        return false;
    }

    //inzia la copia
    //Tutte le parole dopo . ? ! devono iniziare con la lettera maiuscola

    in >> noskipws;
    char c;

    //controllo il primo carattere: 
    if(in >> c){
        if(is_minuscolo(c))
            out << (char)(c - OFFSET);
        else out << c;
    }
    //controllo gli altri
    while(in >> c){
        switch(c){
            case '.':
            case '?':
            case '!':
                out << c;
                while(in >> c){
                    if(c == ' ' || c == '\n'){
                        out << c;
                    }
                    else{
                        if(is_minuscolo(c)){
                            out << (char)(c - OFFSET);
                        }
                        else out << c;
                        break;
                    }
                }
                break;
            default:
                out << c;
                break;
        }
    }

    in.close();
    out.close();
    return true;
}
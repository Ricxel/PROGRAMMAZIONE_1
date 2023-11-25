using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
const int DIM_DB = 100;
struct Studente{
    char nome[31];
    char cognome[31];
    int matricola;
    float media;
};
//stampa il contenuto di una struct studente
void stampa_studente(const Studente *);
//genera una struttura studente con i dati in input 
Studente* genera_studente(char nome[31], char cognome[31], int matricola, float media);
//genera il db di studenti
bool genera_db(Studente ** db, char *filename, int nstudenti);
//ricerca per matricola
int cerca_matricola(Studente ** database, int matricola, int DIM);
//ricerca per nome e cognome
int cerca_nome_e_cognome(Studente ** database, char * nome, char *cognome, int DIM);
//studente con la media più alta
int studente_top_media(Studente ** database, int DIM);

int main(int argc, char ** argv){
    if(argc != 3){
        cout << "Parametri non corretti" << endl;
        return -1;
    }
    int nstudenti = atoi(argv[2]);
    Studente ** db = new Studente*[DIM_DB];
    genera_db(db,argv[1],nstudenti);
    
    // for(int i = 0; i < nstudenti; i++){
    //      stampa_studente(db[i]);
    // }

    // int matricola;
    // cout << "Inserisci la matricola di uno studente che vuoi cercare> ";
    // cin >> matricola;

    // char nome[31],cognome[31];
    // cout << "Nome e cognome> ";
    // cin >> nome >> cognome;

    int indice = studente_top_media(db,nstudenti); 
    cout << "Indice: " << indice << endl;

    // int indice = cerca_nome_e_cognome(db,nome,cognome,nstudenti);
    // cout << "Indice: " << indice << endl;
    return 0;

}

void stampa_studente(const Studente * s){
    cout << "Nome: " << s->nome << endl;
    cout << "Cognome: " << s->cognome << endl;
    cout << "Matricola: " << s->matricola << endl;
    cout << "Media: " << s->media << endl;
}

Studente* genera_studente(char nome[31], char cognome[31], int matricola, float media){
    Studente *s = new Studente;
    strcpy(s->nome,nome);
    strcpy(s->cognome,cognome);
    s->matricola = matricola;
    s->media = media;
    return s;
}
bool genera_db(Studente ** db, char *filename, int nstudenti){
    fstream in;
    in.open(filename,ios::in);

    if(in.fail()){
        return false;
    }
    char nome[31],cognome[31];
    int matricola;
    char media[31];
    int i = 0;
    while(!in.eof() && !in.fail()){
        in >> nome;
        in >> cognome;
        in >> matricola;
        in >> media;
        db[i] = genera_studente(nome,cognome,matricola,atof(media));
        i++;
    }

    in.close();
    return true;
}
int cerca_matricola(Studente ** database, int matricola, int DIM){
    int indice = -1;
    bool trovato = false;
    for(int i = 0; i < DIM && !trovato; i++){
        if(database[i]->matricola == matricola){
            trovato = true;
            indice = i;
        }
    }
    return indice;
}
int cerca_nome_e_cognome(Studente ** database, char * nome, char *cognome, int DIM){
    int indice = -1;
    bool trovato = false;
    for(int i = 0; i < DIM && !trovato; i++){
        if(strcasecmp(database[i]->nome,nome) == 0 && strcasecmp(database[i]->cognome,cognome) == 0){
            trovato = true;
            indice = i;
        }
    }
    return indice;
}
int studente_top_media(Studente ** database, int DIM){
    float max = -1;
    int indice = -1;
    for(int i = 0; i < DIM; i++){
        if(database[i]->media > max){
            max = database[i]->media;
            indice = i;
        }
    }
    cout << "Max: " << max << endl;
    return indice;
}
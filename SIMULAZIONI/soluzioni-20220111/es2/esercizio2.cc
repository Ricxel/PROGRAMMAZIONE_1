#include <iostream>
#include <cstdlib>
#include <cassert>

struct node {
		char info;
		node * next;
};

void dealloca(node *& s) {
		while(s != NULL) {
				node * t = s;
				s = s->next;
				delete t;
		}
}

void stampa_lista(const char * testo, node * s) {
		std::cout << testo;
		for( ; s!= NULL; s=s->next) {
				std::cout << " " << s->info;
		}
		std::cout << std::endl;
}

// Scrivere qui sotto la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char *, node * &, node * &);
// Scrivere qui sopra la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

int main(int argc, char **argv) {
		if (argc != 2) {
				std::cout << "Usage: " << argv[0]
														<< " \"stringa di caratteri\"" << std::endl;
				exit(1);
		}
		node * s1, * s2;
		std::cout << "La stringa da analizzare e': " << argv[1] << std::endl;

		compute_lists(argv[1], s1, s2);

		stampa_lista("Lista s1:", s1);
		stampa_lista("Lista s2:", s2);
		dealloca(s1);
		dealloca(s2);
}

// Scrivere qui sotto la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
char trasforma(char c){
	if(c >= 'A' && c <= 'M'){
		c = 'm' - (c + ('a' - 'A') - 'a');
	}	
	else if(c >= 'N' && c <= 'Z'){
		c = 'z' - (c + ('a' - 'A') - 'n');
	}
	return c;
}
void compute_lists(const char *s, node * &l1, node * &l2){
	std::cout << "carattere : " << *s << std::endl;
	//alloco le liste se non lo sono
	if(l1 != NULL && l2 != NULL){
		std::cout << "Allocato" << std::endl;
		l1 = l2 = NULL;
	}
	if(*s == '\0')
		return;
	else if(*s >= 'A' && *s <= 'M'){
		std::cout << "Compreso A-M" << std::endl;
		//elaboro
		char c = trasforma(*s);
		compute_lists(s+1,l1,l2);
		//inserisco nella lista 1
		node *nuovo_nodo = new node{c, l1};
		l1 = nuovo_nodo;
	}
	else if(*s >= 'N' && *s <= 'Z'){
		std::cout << "Compreso N-Z" << std::endl;
		//elaboro
		char c = trasforma(*s);
		compute_lists(s+1,l1,l2);
		//inserisco nella lista 1
		node *nuovo_nodo = new node{c, l2};
		l2 = nuovo_nodo;
	}
	else{
		compute_lists(s+1,l1,l2);
	}
}
// Scrivere qui sopra la definizione della funzione compute_lists ed
// eventuali funzioni accessorie

using namespace std;
#include <iostream>
#include <cstring>

#include "persona.h"
#include "tree.h"

void init_tree (tree & t) {
  t=NULL;
}

void deinit_tree_data(tree & t) {

}

void deinit_tree(tree & t, bool dealloca) {
  if (t!=NULL) {
    deinit_tree(t->left, dealloca);
    deinit_tree(t->right, dealloca);
    if (dealloca) delete t->p;
    delete t;
  }
}

tree  inserisci_cognome(tree t, persona * p) {
  if (t==NULL) {
    t = new nodo;
    t->p = p;
    t->left = NULL;
    t->right = NULL;
  }
  else if (strcmp(p->cognome,t->p->cognome)<=0)
    t->left = inserisci_cognome(t->left, p);
  else
    t->right = inserisci_cognome(t->right, p);
  return t;
}

tree  inserisci_nome(tree t, persona * p) {
  if (t==NULL) {
    t = new nodo;
    t->p = p;
    t->left = NULL;
    t->right = NULL;
  }
  else if (strcmp(p->nome,t->p->nome)<=0)
    t->left = inserisci_nome(t->left, p);
  else
    t->right = inserisci_nome(t->right, p);
  return t;
}

tree  cerca_cognome (tree  t,char * cognome) {
  tree res;
  if ((t==NULL) || (strcmp(cognome,t->p->cognome)==0))
    res = t;
  else if (strcmp(cognome,t->p->cognome)<0)
    res = cerca_cognome(t->left,cognome);
  else
    res = cerca_cognome(t->right,cognome);
  return res;
}

tree  cerca_nome (tree  t,char * nome) {
  tree res;
  if ((t==NULL) || (strcmp(nome,t->p->nome)==0))
    res = t;
  else if (strcmp(nome,t->p->nome)<0)
    res = cerca_nome(t->left,nome);
  else
    res = cerca_nome(t->right,nome);
  return res;
}


tree  modifica_indirizzo_cognome (tree  t,char * cognome,char * indirizzo)
{
  tree tmp = cerca_cognome(t,cognome);
  if (tmp!=NULL)
    strncpy(tmp->p->indirizzo,indirizzo,MAX_DIM);
  return tmp;
}

tree  modifica_indirizzo_nome (tree  t,char * nome,char * indirizzo)
{
  tree  tmp = cerca_nome(t,nome);
  if (tmp!=NULL)
    strncpy(tmp->p->indirizzo,indirizzo,MAX_DIM);
  return tmp;
}


void stampa_ordinata(tree  t) {
  if (t!=NULL) {
    stampa_ordinata(t->left);
    stampa_persona(t->p);
    stampa_ordinata(t->right);
  }
}

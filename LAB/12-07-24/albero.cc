using namespace std;
#include "albero.h"
#include <iostream>
void init(Tree &t){
    t = 0;
}
boolean empty(const Tree& t){
    if(t == 0){
        return TRUE;
    }
    else return FALSE;
}
boolean insert(Tree& t, char  val){
    Tree nuovo_nodo = new Node{val,0,0};
    if(t == 0){
        t = nuovo_nodo;
    }
    Tree tree = t;
    bool inserito = false;
    boolean ok = TRUE;
    while(tree != 0 && !inserito && ok == TRUE){
        if(val == tree->val){
            ok = FALSE;
        }
        else{
            if(val < tree->val){
                if(tree->left == 0){
                    tree->left = nuovo_nodo;
                    inserito = true;
                }
                else tree = tree->left;
            }
            else{
                if(tree->right == 0){
                    tree->right = nuovo_nodo;
                    inserito = true;
                }
                else tree = tree->right;
            }
        }
    }
    return ok;
}
boolean search(const Tree& t, char val){
    if(t == 0){
        return FALSE;
    }
    if(val == t->val){
        return TRUE;
    }
    boolean ok1 = search(t->left, val);
    boolean ok2 = search(t->right,val);
    boolean ris = FALSE;
    if(ok1 == TRUE || ok2 == TRUE){
        ris = TRUE;
    }
    return ris;
}
void print(const Tree& t){
    if(t == 0){
        return;
    }
    print(t->left);
    cout << t->val << " ";
    print(t->right);
}
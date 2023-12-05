#include "albero_binario.h"

void albero_init(albero & t){
    t = NULL;
}

void albero_insert(albero & tree, int n){
    albero nuovo_nodo = new node{n,NULL,NULL};
    bool stop = false;
    if(tree == NULL){
        tree = nuovo_nodo;
    }
    else{
        albero t = tree;
        while(!stop &&  t!= NULL){
            if(n <= t->value){
                if(t->left != NULL){
                    t = t->left;
                }
                else{
                    t->left = nuovo_nodo;
                    stop = true;
                }
            }
            else{
                if(t->right != NULL){
                    t = t->right;
                }
                else{
                    t->right = nuovo_nodo;
                    stop = true;
                }
            }
        }
    }
}
void albero_insert_rec(albero & radice, node *nuovo_nodo){
    if(radice == NULL){
        radice = nuovo_nodo;
        return;
    }   
    albero tree = radice;
    if(nuovo_nodo->value <= tree->value){
        if(tree->left != NULL){
            albero_insert_rec(tree->left, nuovo_nodo);
        }
        else tree->left = nuovo_nodo;
    }
    else{
        if(tree->right != NULL){
            albero_insert_rec(tree->right, nuovo_nodo);
        }
        else tree->right = nuovo_nodo;
    }
}
 
void stampaAlbero(albero radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}
// void albero_stampa_crescente(albero tree){
//     if(tree->right == NULL){
//         pila_push(tree->value);
//         return;
//     }
//     else{
//         if(pila->left != NULL){

//         }
//     }

// }
void albero_ricerca(albero tree, int target){
    //per memorizzare il percorso: coda di stringhe
    coda_init();
    int cont_des = 0, cont_sin = 0;
    bool trovato = false;
    while(tree != NULL && !trovato){
        if(tree->value == target){
            trovato = true;
        }
        else{
            if(target < tree->value){
                cont_sin++;
                //cout << tree->value << ",sinistra" << endl;
                char *s = new char[dim]{"sinistra"};
                coda_enqueue(s);
                tree = tree->left;
            }
            else{
                cont_des++;
                //cout << tree->value << ",destra" << endl;
                char *s = new char[dim]{"destra"};
                coda_enqueue(s);
                tree = tree->right;
            }
        }
    }
}
node* albero_ricerca_rec(albero & radice, int target){
    if(radice == NULL){
        return NULL;
    }
    albero tree = radice;
    if(tree->value == target){
        return tree;
    }
    else if(target < tree->value){
        return albero_ricerca_rec(tree->left, target);
    }
    else{
        return albero_ricerca_rec(tree->right, target);
    }

}
void albero_dealloca(albero radice){
    if(radice == NULL){
        return;
    }
    albero_dealloca(radice->left);
    albero_dealloca(radice->right);
    delete radice;
}
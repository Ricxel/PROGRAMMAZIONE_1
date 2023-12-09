#ifndef ALBERO_H
#define ALBERO_H
struct Node {
    char  val;
    Node *left;
    Node *right;
};

typedef Node *Tree;
enum boolean { FALSE, TRUE };

void    init(Tree& t);
boolean empty(const Tree& t);
boolean insert(Tree& t,
               char  val);
boolean search(const Tree& t,
               char        val);
void    print(const Tree& t);

#endif // ifndef ALBERO_H

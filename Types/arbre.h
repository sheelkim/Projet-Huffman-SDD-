#ifndef ARBRE_H
#define ARBRE_H

typedef struct Noeud{
    struct Noeud *gauche;
    struct Noeud *droit;
    char lettre;
    int occurrence;
}Noeud;

typedef struct Noeud *Arbre;

Noeud* creer_noeud(char lettre, int occurrence);
void afficher_noeud(Arbre arbre);


#endif // ARBRE_H




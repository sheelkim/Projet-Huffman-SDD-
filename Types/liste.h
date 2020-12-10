#ifndef LISTE_H
#define LISTE_H

#include "arbre.h"

typedef struct Element{
        Noeud *noeud;
        struct Element *suiv;
}Element;

typedef struct Element *Liste;

Element* creer_element(Noeud* noeud);
extern void afficher_liste(Liste liste);

#endif // LISTE_H


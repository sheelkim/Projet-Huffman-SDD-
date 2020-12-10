#include <stdio.h>
#include <stdlib.h>

#include "arbre.h"


Noeud* creer_noeud(char lettre, int occurrence)
{
    Noeud *noeud = malloc(sizeof(Noeud));
    noeud->lettre = lettre;
    noeud->occurrence = occurrence;
    noeud->gauche = NULL;
    noeud->droit = NULL;
    return noeud;
}

void afficher_noeud(Arbre arbre)
{
    if(arbre != NULL)
    {
        printf(" |%c %d| ", arbre->lettre, arbre->occurrence);
        afficher_noeud(arbre->gauche);
        afficher_noeud(arbre->droit);
    }
}



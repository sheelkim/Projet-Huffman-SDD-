#include <stdio.h>
#include <stdlib.h>

#include "huffman.h"


/// Partie 1

/// A
void caractere_binaire(char ch, char bit[9])
{
    for(int i = 7; i >= 0; i--)
    {
        bit[i] = '0' + (ch % 2);
        ch = ch / 2;
    }
    bit[8] = '\0';
}

void ecriture_texte(char *fichier1, char *fichier2)
{
    FILE *lecture = fopen(fichier1, "r");
    FILE *ecriture = fopen(fichier2, "w");

   if (lecture == NULL || ecriture == NULL)
        exit(EXIT_FAILURE);

    char ch;
    char bit[9];


    while ((ch = fgetc(lecture)) != EOF) 
    {
        caractere_binaire(ch, bit);
        fprintf(ecriture, "%s", bit);
    }
    fclose(lecture);
    fclose(ecriture);
}

/// B
int compter_caractere(char *fichier)
{
    FILE *f = fopen(fichier, "r");
    char caractere;
    int cmp = 0;

    if(f == NULL)
        exit(EXIT_FAILURE);

    while(((caractere) = fgetc(f)) != EOF)
    {
        cmp++;
    }

    fclose(f);

    return cmp;
}

/// Partie 2

///C
Liste occurrence_texte(char *fichier)
{
    FILE *f = fopen(fichier, "r");
    if(f == NULL){
        exit(EXIT_FAILURE);
    }

    Liste liste = NULL;
    Element *tmp = NULL;

    char caractere;
    while ((caractere = fgetc(f)) != EOF)
    {
        tmp = liste;

        while (tmp != NULL && tmp->noeud->lettre != caractere)
        {
            tmp = tmp->suiv;
        }

        if(tmp != NULL)
        {
            tmp->noeud->occurrence = tmp->noeud->occurrence + 1; 

        }
        else
        {
            Element* nouv_element = creer_element(creer_noeud(caractere, 1));
            nouv_element->suiv = liste;
            liste = nouv_element;
        }
    }

    fclose(f);
    return liste;
}


/// D
Arbre arbre_huffman(Liste liste)
{
    if(liste == NULL)
        exit(EXIT_FAILURE);

        Arbre arbre = liste->noeud; // on rentre dans l'arbre le premier noeud
        Noeud *noeud1 = NULL; 
        Noeud *noeud2 = NULL;

        while (liste->suiv != NULL)
        {
            noeud1 = petit_element(&liste);
            noeud2 = petit_element(&liste);

            /// on ne met pas de lettre mais juste le nombre d'occurrences cf. consigne huffman
            arbre = creer_noeud(0, noeud1->occurrence + noeud2->occurrence);
            arbre->gauche = noeud1;
            arbre->droit = noeud2;

            Element* element = creer_element(arbre);
            element->suiv = liste;
            liste = element;
        }

        free(liste);

        return arbre;

}

/// pour trouver le plus petit element
Noeud* petit_element(Liste *liste)
{
    if ((*liste) == NULL){
        exit(EXIT_FAILURE);
    }

        Liste *tmp = liste;
        Liste *petit = tmp;

        while (*tmp != NULL)
        {
            if((*petit)->noeud->occurrence > (*tmp)->noeud->occurrence)
            {
                petit = tmp;
            }
            tmp = &(*tmp)->suiv;
        }

    Noeud *noeud = (*petit)->noeud;
    Element *ancien = *petit;
    *petit = (*petit)->suiv;
    free(ancien);

    return noeud;
}



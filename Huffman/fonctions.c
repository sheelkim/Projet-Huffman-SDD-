#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"

void convertion(void)
{
    printf("\n");
    ecriture_texte("texte.txt", "binaire.txt");
}

void caractere_texte(void)
{
    printf("\n");
    printf("Nombre de caractere dans le fichier texte.txt : %d\n", compter_caractere("texte.txt"));
    printf("Nombre de caractere dans le fichier binaire : %d\n", compter_caractere("binaire.txt"));
}

void huffman(void)
{
    printf("\n");
    Liste liste = occurrence_texte("texte.txt");
    Arbre arbre = arbre_huffman(liste);
    afficher_noeud(arbre);
}


void menu(void)
{
    int menu;
    printf(" 1. Conversion texte en binaire\n 2. Affichage du nombre de caractere dans chaque fichier\n 3. Affichage de l'arbre de Huffman\n");
    printf(" Choix : ");
    scanf("%d", &menu);
    switch(menu)
    {
        case 1 :
            convertion();
            break;

        case 2 :
            caractere_texte();
            break;

        case 3 :
            huffman();
            break;
    }

}

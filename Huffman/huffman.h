#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "../Types/arbre.h"
#include "../Types/liste.h"

extern void caractere_binaire(char ch, char bit[9]);
extern void ecriture_texte(char *fichier1, char *fichier2);
extern int compter_caractere(char *fichier);
extern Liste occurrence_texte(char *fichier);
extern Arbre arbre_huffman(Liste liste);
extern Noeud* petit_element(Liste *liste);
#endif // HUFFMAN_H


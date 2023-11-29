#include <stdio.h>
#include <stdlib.h>
#include "arbre_lexicographique.h"


int main(int argc, char **argv)
{
  
  char *mot_a_chercher = argv[1];
  int nombre_repetitions = atoi(argv[2]);

  PNoeud dico = lire_dico("french_za");

  for (int i = 0; i < nombre_repetitions; i++) {
    rechercher_mot(dico, mot_a_chercher);
  }

  detruire_dico(dico);

  return 0;
}


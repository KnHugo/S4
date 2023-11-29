#include <stdlib.h>
#include <stdio.h>
#include "arbre_lexicographique_tab.h"

int main(int argc, char **argv) {

  char *mot_a_chercher = argv[1];
  int nombre_repetitions = atoi(argv[2]);

  PNoeudTab racine = lire_dico("french_za");

  for (int i = 0; i < nombre_repetitions; i++) {
    rechercher_mot(racine, mot_a_chercher);
  }

  detruire_dico(racine);

  return 0;
}

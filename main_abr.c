#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "abr.h"

int main(int argc, char **argv)
{

  char *mot_a_chercher = argv[1];
  int nombre_repetitions = atoi(argv[2]);

  Lm_mot * lm=lire_dico_Lmot("french_za");

  Nd_mot * arbre=Lm2abr(lm);

  for (int i = 0; i < nombre_repetitions; i++) {
    chercher_Nd_mot(arbre, mot_a_chercher);
  }
  // On écrit dans le terminal chmod +x ./main_abr puis time ./main_abr bateau 5000
  //pour bateau 5000 : real    0m0,935s pour bateau 500 000 on a 1m6,854s pour bateau 1 000 000 2m8,681s

  detruire_abr_mot(arbre);


  return 0;
}

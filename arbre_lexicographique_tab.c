#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"

PNoeudTab creer_noeud(char lettre) {
    PNoeudTab nouveau_noeud = (PNoeudTab)malloc(sizeof(NoeudTab));
    assert(nouveau_noeud != NULL);

    nouveau_noeud->lettre = lettre;
    nouveau_noeud->fin_de_mot = non_fin;

    for (int i = 0; i < 26; i++) {
        nouveau_noeud->fils[i] = NULL;
    }

    return nouveau_noeud;
}

PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {

    PNoeudTab noeud_courant = racine;

    while (*mot != '\0') {
        int indice = *mot - 'a';

        if (noeud_courant->fils[indice] == NULL) {
            noeud_courant->fils[indice] = creer_noeud(*mot);
        }

        noeud_courant = noeud_courant->fils[indice];
        mot++;
    }

    noeud_courant->fin_de_mot = fin;

    return racine;
}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
    if (n == NULL) {
        return;
    }

    mot_en_cours[index++] = n->lettre;

    if (n->fin_de_mot == fin) {
        mot_en_cours[index] = '\0';
        printf("%s\n", mot_en_cours);
    }

    for (int i = 0; i < 26; i++) {
        if (n->fils[i] != NULL) {
            afficher_mots(n->fils[i], mot_en_cours, index);
        }
    }
}

void afficher_dico(PNoeudTab racine) {
    char mot_en_cours[LONGUEUR_MAX_MOT];
    afficher_mots(racine, mot_en_cours, 0);
}

void detruire_dico(PNoeudTab dico) {
    if (dico == NULL) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        detruire_dico(dico->fils[i]);
    }

    free(dico);
}

int rechercher_mot(PNoeudTab dico, char *mot) {
    while (*mot != '\0') {
        int indice = *mot - 'a';

        if (dico->fils[indice] == NULL) {
            return 0; // Le mot n'est pas présent dans le dictionnaire
        }

        dico = dico->fils[indice];
        mot++;
    }

    return dico->fin_de_mot; // Retourne 1 si le mot complet est trouvé, 0 sinon
}

PNoeudTab lire_dico(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    PNoeudTab racine = creer_noeud('\0');
    char mot[LONGUEUR_MAX_MOT];

    while (fscanf(fichier, "%s", mot) != EOF) {
        racine = ajouter_mot(racine, mot);
    }

    fclose(fichier);
    return racine;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nom[30];
    char ip[16];
    int est_actif;
} Equipement;

Equipement* allouer_parc(int nb_equipements);
void saisir_parc(Equipement *parc, int nb_equipements);
void afficher_parc(const Equipement *parc, int nb_equipements);
void changer_etat(Equipement *eq);

int main(void) {
    int n = 0;
    Equipement *mon_parc = NULL;

    printf("--- GESTION DU PARC RESEAU ---\n");
    printf("Combien d'equipements voulez-vous gerer ? ");
    scanf("%d", &n);

    mon_parc = allouer_parc(n);

    // Verification du pointeur
    if (mon_parc == NULL) {
        printf("Erreur : allocation memoire impossible.\n");
        return 1;
    }

    // TODO: Saisie des equipements
    // saisir_parc(...);

    // TODO: Affichage du parc
    // afficher_parc(...);

    // TODO: Changement d'etat du premier equipement
    // printf("\nChangement d'etat du premier equipement...\n");
    // changer_etat(...);

    // TODO: Re-affichage pour verification
    // afficher_parc(...);

    // TODO: Liberation de la mémoire
    // free(...);

    printf("\nMemoire liberee avec succes.\n");
    return 0;
}

Equipement* allouer_parc(int nb_equipements) {
    Equipement *parc = malloc(nb_equipements * sizeof(Equipement));

    if (parc == NULL) {
        return NULL;
    }

    return parc;
}

void saisir_parc(Equipement *parc, int nb_equipements) {
    // TODO
}

void afficher_parc(const Equipement *parc, int nb_equipements) {
    // TODO
}

void changer_etat(Equipement *eq) {
    // TODO
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Définition de la structure
typedef struct {
    int id;
    char nom[30];
    char ip[16];
    int est_actif; // 1 = Actif, 0 = Inactif
} Equipement;

// 2. Prototypes des fonctions
Equipement* allouer_parc(int nb_equipements);
void saisir_parc(Equipement *parc, int nb_equipements);
void afficher_parc(const Equipement *parc, int nb_equipements);
void changer_etat(Equipement *eq);

// 3. Programme principal
int main(void) {
    int n = 0;
    Equipement *mon_parc = NULL;

    printf("--- GESTION DU PARC RESEAU ---\n");
    printf("Combien d'equipements voulez-vous gerer ? ");
    scanf("%d", &n);

    // TODO: Allocation dynamique du parc
    // mon_parc = allouer_parc(...);

    // TODO: Verification du pointeur (NULL ?)

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

// --------------------------------------------------
// 4. Définitions des fonctions à compléter ci-dessous
// --------------------------------------------------

Equipement* allouer_parc(int nb_equipements) {
    // TODO: Utiliser malloc et vérifier si l'allocation a réussi
    return NULL;
}

void saisir_parc(Equipement *parc, int nb_equipements) {
    // TODO: Remplir les champs de chaque équipement avec une boucle
}

void afficher_parc(const Equipement *parc, int nb_equipements) {
    // TODO: Parcourir le tableau et afficher les informations
}

void changer_etat(Equipement *eq) {
    // TODO: Modifier la valeur de est_actif en passant par le pointeur
}

Fin du TP !!!! youppi

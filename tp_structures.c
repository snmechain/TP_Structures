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
    mon_parc = allouer_parc(n);

    // TODO: Verification du pointeur (NULL ?)
    if (mon_parc == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire.\n");
        return -1;
    }

    // TODO: Saisie des equipements
    saisir_parc(mon_parc, n);

    // TODO: Affichage du parc
    afficher_parc(mon_parc, n);

    // TODO: Changement d'etat du premier equipement
    printf("\nChangement d'etat du premier equipement...\n");
    changer_etat(&mon_parc[0]);

    // TODO: Re-affichage pour verification
    afficher_parc(mon_parc, n);

    // TODO: Liberation de la mémoire
    free(mon_parc);

    printf("\nMemoire liberee avec succes.\n");
    return 0;
}

// --------------------------------------------------
// 4. Définitions des fonctions à compléter ci-dessous
// --------------------------------------------------

Equipement* allouer_parc(int nb_equipements) {
    // TODO: Utiliser malloc et vérifier si l'allocation a réussi
    Equipement *parc = malloc(nb_equipements * sizeof(Equipement));
    if (parc == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire.\n");
        return NULL;
    }
    return parc;
}

void saisir_parc(Equipement *parc, int nb_equipements) {
    // TODO: Remplir les champs de chaque équipement avec une boucle
    for (int i = 0; i < nb_equipements; i++) {
        printf("Equipement N° %d:\n", i + 1);
        printf("  ID: ");
        scanf("%d", &parc[i].id);
        printf("  Nom: ");
        scanf("%29s", parc[i].nom);
        printf("  IP: ");
        scanf("%15s", parc[i].ip);
        printf("  Etat (1=Actif, 0=Inactif): ");
        scanf("%d", &parc[i].est_actif);
    }
}

void afficher_parc(const Equipement *parc, int nb_equipements) {
    // TODO: Parcourir le tableau et afficher les informations
    printf("\n--- Parc Réseau ---\n");
    for (int i = 0; i < nb_equipements; i++) {
        printf("Equipement N° %d:\n", i + 1);
        printf("  ID: %d\n", parc[i].id);
        printf("  Nom: %s\n", parc[i].nom);
        printf("  IP: %s\n", parc[i].ip);
        printf("  Etat: %s\n", parc[i].est_actif ? "Actif" : "Inactif");
    }
}

void changer_etat(Equipement *eq) {
    // TODO: Modifier la valeur de est_actif en passant par le pointeur
    eq->est_actif = !eq->est_actif;
}

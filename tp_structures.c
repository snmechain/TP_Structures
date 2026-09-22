//
// TP_STRUCTURES_FINAL.C
// Programme de gestion d'un parc réseau avec structures et allocation dynamique
// Auteur: [Dallencourt Gaetan]
// Date: 22-09-2026

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

    if (n <= 0) {
        printf("Nombre d'equipements invalide.\n");
        return 1;
    }

    // Allocation dynamique du parc
    mon_parc = allouer_parc(n);

    // Verification du pointeur
    if (mon_parc == NULL) {
        printf("Erreur lors de l'allocation memoire !\n");
        return 1;
    }

    // Saisie des equipements
    saisir_parc(mon_parc, n);

    // Affichage du parc
    afficher_parc(mon_parc, n);

    // Changement d'etat du premier équipement
    printf("\nChangement d'etat du premier equipement...\n");
    changer_etat(&mon_parc[0]);

    // Liberation de la mémoire
    free(mon_parc);
    mon_parc = NULL; // Bonne pratique pour éviter les dangling pointers

    printf("\nMemoire liberee avec succes.\n");
    return 0;
}

// --------------------------------------------------
// 4. Définitions des fonctions complétées
// --------------------------------------------------

Equipement* allouer_parc(int nb_equipements) {
    // Utilisation de malloc pour allouer la taille exacte sur le tas
    return (Equipement*) malloc(nb_equipements * sizeof(Equipement));
}

void saisir_parc(Equipement *parc, int nb_equipements) {
    for (int i = 0; i < nb_equipements; i++) {
        printf("\n--- Saisie de l'equipement %d ---\n", i + 1);
        printf("ID : ");
        scanf("%d", &parc[i].id);
        printf("Nom : ");
        scanf("%29s", parc[i].nom); // %29s pour éviter les dépassements de buffer
        printf("Adresse IP : ");
        scanf("%15s", parc[i].ip);
        printf("Actif (1: Oui, 0: Non) : ");
        scanf("%d", &parc[i].est_actif);
    }
}

void afficher_parc(const Equipement *parc, int nb_equipements) {
    printf("\n--- LISTE DES EQUIPEMENTS ---\n");
    for (int i = 0; i < nb_equipements; i++) {
        printf("ID: %d | Nom: %-12s | IP: %-15s | Etat: %s\n",
               parc[i].id,
               parc[i].nom,
               parc[i].ip,
               parc[i].est_actif ? "ACTIF" : "INACTIF");
    }
}

void changer_etat(Equipement *eq) {
    if (eq != NULL) {
        // Inverse l'état (si 1 devient 0, si 0 devient 1)
        eq->est_actif = (eq->est_actif == 1) ? 0 : 1;
        printf("L'equipement %d est maintenant %s.\n", eq->id, eq->est_actif ? "ACTIF" : "INACTIF");
    }
      
}
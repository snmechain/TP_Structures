#define _CRT_SECURE_NO_WARNINGS
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
void saisir_parc(Equipement* parc, int nb_equipements);
void afficher_parc(const Equipement* parc, int nb_equipements);
void changer_etat(Equipement* eq);

// 3. Programme principal
int main(void) {
    int n = 0;
    Equipement* mon_parc = NULL;

    printf("--- GESTION DU PARC RESEAU ---\n");
    printf("Combien d'equipements voulez-vous gerer ? ");
    scanf("%d", &n);

    // Allocation dynamique du parc
    mon_parc = allouer_parc(n);

    // Vérification du pointeur
    if (mon_parc == NULL) {
        printf("Erreur : impossible d'allouer la mémoire.\n");
        return 1;
    }

    // Saisie des équipements
    saisir_parc(mon_parc, n);

    // Affichage du parc
    afficher_parc(mon_parc, n);

    // Changement d'état du premier équipement
    printf("\nChangement d'etat du premier equipement...\n");
    changer_etat(&mon_parc[0]);

    // Ré-affichage pour vérification
    afficher_parc(mon_parc, n);

    // Libération de la mémoire
    free(mon_parc);

    printf("\nMemoire liberee avec succes.\n");
    return 0;
}

// --------------------------------------------------
// 4. Définitions des fonctions
// --------------------------------------------------

Equipement* allouer_parc(int nb_equipements) {
    Equipement* parc = (Equipement*)malloc(nb_equipements * sizeof(Equipement));
    if (parc == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return NULL;
    }
    return parc;
}

void saisir_parc(Equipement* parc, int nb_equipements) {
    for (int i = 0; i < nb_equipements; i++) {
        parc[i].id = i + 1;

        printf("\nEquipement %d\n", parc[i].id);

        printf("Nom : ");
        scanf("%s", parc[i].nom);

        printf("IP : ");
        scanf("%s", parc[i].ip);

        printf("Actif ? (0/1) : ");
        scanf("%d", &parc[i].est_actif);
    }
}

void afficher_parc(const Equipement* parc, int nb_equipements) {
    printf("\n--- LISTE DES EQUIPEMENTS ---\n");
    for (int i = 0; i < nb_equipements; i++) {
        printf("ID : %d\n", parc[i].id);
        printf("Nom : %s\n", parc[i].nom);
        printf("IP : %s\n", parc[i].ip);
        printf("Etat : %s\n", parc[i].est_actif ? "Actif" : "Inactif");
        printf("----------------------\n");
    }
}

void changer_etat(Equipement* eq) {
    eq->est_actif = !eq->est_actif;
}

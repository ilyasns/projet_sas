#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Constantes
#define MAX_CLIENTS 100
#define MAX_PRODUCTS 100
#define MAX_ACHATS 100

// Structures
typedef struct {
    int jour, mois, annee;
} date;

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    float solde;
} client;

typedef struct {
    int id_prod;
    char nom_prod[50];
    char categorie_prod[50];
    float prix_prod;
    int stock_prod;
    char discription[150];
} produit;

typedef struct {
    int id_achat;
    int id_produit;
    float prix;
    int quantity;
    date date_achat;
} achat;

// Prototypes
void pause();
void generer_email(client* clt);
void initialiser_produits(produit arr_produits[], int* n);
void afficher_produit(const produit* p);
void afficher_catalogue(const produit arr_produits[], int n);

// Fonctions
void pause() {
    printf("Appuyer sur Entrée pour continuer <3  ");
    getchar();
    getchar();
}

void generer_email(client* clt) {
    snprintf(clt->email, sizeof(clt->email), "%s.%s@client.com", clt->prenom, clt->nom);
    // Mise en minuscules
    for (int i = 0; clt->email[i]; i++) {
        clt->email[i] = tolower(clt->email[i]);
    }
}

void initialiser_produits(produit arr_produits[], int* n) {
    *n = 5;
    arr_produits[0] = (produit){1, "Ordinateur portable", "Electronique", 799.00, 5, "PC wa3er a as7bi aji 5odo"};
    arr_produits[1] = (produit){2, "Smartphone", "Electronique", 499.00, 10, "3laxe txri iphone o nta t9dr txri had tele o t3tini lfloss li b9at ;)"};
    arr_produits[2] = (produit){3, "Casque Audio", "Electronique", 89.00, 15, "best head phones from l9ri3a"};
    arr_produits[3] = (produit){4, "Souris", "Electronique", 25.00, 20, "Souris nadia 3la 7ssabi"};
    arr_produits[4] = (produit){5, "Clavier", "Electronique", 45.00, 12, "Clavier dial l gamers o dakxi hh"};
}

void afficher_produit(const produit* p) {
    printf("ID:%d | %s | Catégorie: %s | Prix: %.2f MAD | Stock: %d | %s\n",
           p->id_prod, p->nom_prod, p->categorie_prod, p->prix_prod, p->stock_prod, p->discription);
}

void afficher_catalogue(const produit arr_produits[], int n) {
    printf("\n=== Catalogue des Produits ===\n");
    for (int i = 0; i < n; i++) {
        afficher_produit(&arr_produits[i]);
    }
}

// Main menu
int main() {
    int choix;
    produit produits[MAX_PRODUCTS];
    int nb_produits = 0;

    initialiser_produits(produits, &nb_produits);

    do {
        printf("\n=== SYSTÈME D'ACHAT CLIENT ===\n");
        printf("1.  Gestion du profil client\n");
        printf("2.  Gestion du solde virtuel\n");
        printf("3.  Consultation des produits\n");
        printf("4.  Effectuer un achat\n");
        printf("5.  Mes statistiques\n");
        printf("0.  Quitter l'application\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Gestion du profil client (à implémenter)\n");
                pause();
                break;
            case 2:
                printf("Gestion du solde virtuel (à implémenter)\n");
                pause();
                break;
            case 3:
                afficher_catalogue(produits, nb_produits);
                pause();
                break;
            case 4:
                printf("Effectuer un achat (à implémenter)\n");
                pause();
                break;
            case 5:
                printf("Mes statistiques (à implémenter)\n");
                pause();
                break;
            case 0:
                printf("Merci d'avoir utilisé l'application !\n");
                break;
            default:
                printf("Choix invalide, réessayez.\n");
                pause();
        }
    } while (choix != 0);

    return 0;
}
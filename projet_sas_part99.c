#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_CLIENTS 100
#define MAX_PRODUCTS 100
#define MAX_ACHATS 100


// Structures 
typedef struct
{
    int jour, mois, annee;
} date;

typedef struct
{
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    float solde;
} client;

typedef struct
{
    int id_prod;
    char nom_prod[50];
    char categorie_prod[50];
    float prix_prod;
    int stock_prod;
    char description[150];
} produit;

typedef struct
{
    int id_achat;
    int id_produit;
    float prix;
    int quantity;
    date date_achat;
} achat;


// Variables Glob
client clt;
produit arr_produits[MAX_PRODUCTS];
int nombre_produit = 0;
achat arr_achats[MAX_ACHATS];
int nombre_achats = 0;
int id_gen = 0;


// fonctionattttttt
void pause() {
    printf("Appuyer sur Entree pour continuer <3  ");
    getchar();
    getchar();
}

void afficher_date(){
    printf("        Date actuelle: 03/11/2025\n         ");
}
// initialisation des produit
void intialisations_prod() {
    nombre_produit = 8;
    arr_produits[0] = (produit){1, "Ordinateur portable", "Electronique", 799.00, 5, "PC wa3er a as7bi aji 5odo"};
    arr_produits[1] = (produit){2, "Smartphone", "Electronique", 499.00, 10, "3laxe txri iphone o nta t9dr txri had tele o t3tini lfloss li b9at ;)"};
    arr_produits[2] = (produit){3, "Casque Audio", "Electronique", 89.00, 15, "best head phones from l9ri3a"};
    arr_produits[3] = (produit){4, "Souris", "Electronique", 25.00, 20, "Souris nadia 3la 7ssabi"};
    arr_produits[4] = (produit){5, "Clavier", "Electronique", 45.00, 12, "Clavier dial l gamers o dakxi hh"};
    // produit d autre categorie
    arr_produits[5] = (produit){6, "Ferrari SF 25", "Voiture", 2500000.00, 300, "ghadi tji nta l5r f race wa5a tkoun msab9a m3a rask"};
    arr_produits[6] = (produit){7, "porshe GT3RS", "Voiture", 1200000.00, 400, "90000 rpm o 0-100 f 3.2s axe ba9i baghi"};
    arr_produits[7] = (produit){8, "koenigsegg ccx", "Voiture", 50000000.00, 10, "Tonobil automatique o manuelle f nafs lwa9t"};
}// drnaha hna 9bl affichage catalog baxe ikoun 3amr

// affichage
void afficher_produit(int index) {
    printf("ID: %d | Nom: %s | Categorie: %s | Prix: %.2f MAD | Stock: %d | Description: %s\n",
           arr_produits[index].id_prod,
           arr_produits[index].nom_prod,
           arr_produits[index].categorie_prod,
           arr_produits[index].prix_prod,
           arr_produits[index].stock_prod,
           arr_produits[index].description);
}

void afficher_cataloge() {
    printf("        Catalogue des produits:     \n");
    for (int i = 0; i < nombre_produit; i++) {
        afficher_produit(i);
    }
}


//generation et initialisation 
void generer_email() {
    snprintf(clt.email, sizeof(clt.email), "%s.%s@client.com", clt.prenom, clt.nom);
    for (int i = 0; clt.email[i]; i++) {
        clt.email[i] = tolower(clt.email[i]);
    }
}

// recherche dans produits
void rechercher_produit_par_nom() {
    char nom_recherche[50];
    int found = 0;
    printf("Entrez le nom du produit a rechercher: ");
    scanf("%49s", nom_recherche);
    for (int i = 0; i < nombre_produit; i++) {
        if (strstr(arr_produits[i].nom_prod, nom_recherche) != NULL) {
            afficher_produit(i);
            found = 1;
            return;
        }
    }
    if (!found) {
        printf("Produit non trouve.\n");
    }
}
void rechercher_produit_par_categorie() {
    printf("les categories disponibles sont :\n");
    printf("1. Electronique\n");
    printf("2. Voiture\n");
    char categorie[50];
    int found = 0;
    printf("Entrez nom de la categorie du produit a rechercher: ");
    scanf("%49s", categorie);
    printf("Produits dans la categorie %s:\n", categorie);
    for (int i = 0; i < nombre_produit; i++) {
        if (strcmp(arr_produits[i].categorie_prod, categorie) == 0) {
            afficher_produit(i);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun produit trouve dans cette categorie.\n");
    }
}
void rechercher_produits(){
    int choice;
    printf("Choisissez le critere de recherche:\n");
    printf("1. Par nom\n");
    printf("2. Par categorie\n");
    printf("Votre choix: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            rechercher_produit_par_nom();
            break;
        case 2:
            rechercher_produit_par_categorie();
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}

// trie des produits abule
void trier_produits_par_prix() {
    for (int i = 0; i < nombre_produit - 1; i++) {
        for (int j = 0; j < nombre_produit - i - 1; j++) {
            if (arr_produits[j].prix_prod > arr_produits[j + 1].prix_prod) {
                produit temp = arr_produits[j];
                arr_produits[j] = arr_produits[j + 1];
                arr_produits[j + 1] = temp;
            }
        }
    }
    printf("Produits tries par prix croissant:\n");
    for (int i = 0; i < nombre_produit; i++) {
        afficher_produit(i);
    }
}
void trier_produits_par_nom_alphabetique() {
    for (int i = 0; i < nombre_produit - 1; i++) {
        for (int j = 0; j < nombre_produit - i - 1; j++) {
            if (strcmp(arr_produits[j].nom_prod, arr_produits[j + 1].nom_prod) > 0) {
                produit temp = arr_produits[j];
                arr_produits[j] = arr_produits[j + 1];
                arr_produits[j + 1] = temp;
            }
        }
    }
    printf("Produits tries par nom alphabetique:\n");
    for (int i = 0; i < nombre_produit; i++) {
        afficher_produit(i);
    }
}
void triage_produits() {// pour conbiner les deux fonctions dial tri
    int choice;
    printf("Choisissez le critere de tri:\n");
    printf("1. Par prix (croissant)\n");
    printf("2. Par nom (alphabetique)\n");
    printf("Votre choix: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            trier_produits_par_prix();
            break;
        case 2:
            trier_produits_par_nom_alphabetique();
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}


// gestion du profil 
void creer_profil() {
    printf("         Entrez votre nom:  ");
    scanf("%49s", clt.nom);
    printf("\n       Entrez votre prenom: ");
    scanf("%49s", clt.prenom);
    generer_email();
    clt.id = 1;
    clt.solde = 0.0;
    printf("             Profil cree avec succes!        \n");
    printf("    ID: %d | Nom: %s | Prenom: %s | Email: %s | Solde: %.2f MAD\n",
           clt.id, clt.nom, clt.prenom, clt.email, clt.solde);
}
void modifier_profil() {
    printf("            Modifier votre profil:\n");
    printf("        Entrez votre nouveau nom (actuel: %s): ", clt.nom);
    scanf("%49s", clt.nom);
    printf("        Entrez votre nouveau prenom (actuel: %s): ", clt.prenom);
    scanf("%49s", clt.prenom);
    generer_email();
    printf("yay Profil modifie avec succes!\n");
    printf("ID: %d | Nom: %s | Prenom: %s | Email: %s | Solde: %.2f MAD\n",
           clt.id, clt.nom, clt.prenom, clt.email, clt.solde);
}
void afficher_profil() {
    printf("            Votre profil:           \n");
    printf("     ID: %d | Nom: %s | Prenom: %s | Email: %s | Solde: %.2f MAD        \n",
           clt.id, clt.nom, clt.prenom, clt.email, clt.solde);
}
void supprimer_profil() {
    printf("donner le nom et prenom de profil a supprimer :\n");
    char suprimer_nom[50], suprimer_prenom[50];
    scanf("%49s %49s", suprimer_nom, suprimer_prenom);
    if (strcmp(clt.nom, suprimer_nom) != 0 || strcmp(clt.prenom, suprimer_prenom) != 0) {
        printf("Nom ou prenom incorrect. Suppression annulee.\n");
        return;
    }
    clt.id = 0;
    strcpy(clt.nom, "");
    strcpy(clt.prenom, "");
    strcpy(clt.email, "");
    clt.solde = 0.0;
    printf("Profil supprime avec succes!\n");
}


// gestion du solde
void gestion_solde() {
    int choice;
    float amount;
    printf("          ********************gestion de solde: ********************\n");
    printf("                        1. Ajouter du soldes\n");
    printf("                        2. Aficher votre solde\n");
    printf("                        3. Retirer du solde\n");
    printf("                        4. Retour au menu principal\n");
    printf("\n Votre choix:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("            Donner le montant a ajouter:");
            scanf("%f", &amount);
            if (amount > 0) {
                clt.solde += amount;
                printf("Montant ajoute avec succes! Nouveau solde: %.2f MAD   :)\n ", clt.solde);
            } else {
                printf("Montant invalide, le montant est negatif Operation annulee.  :/\n");
            }
            break;
        case 2:
            printf("Votre solde actuel est: %.2f MAD\n", clt.solde);
            break;
        case 3:
            printf("            Donner le montant a retirer:");
            scanf("%f", &amount);
            if (amount > 0 && amount <= clt.solde) {
                clt.solde -= amount;
                printf("Montant retire avec succes! Nouveau solde: %.2f MAD\n", clt.solde);
            } else {
                printf("Montant invalide ou solde insuffisant. Opération annulee.\n");
            }
            break;
        case 4:
            return;
        default:
            printf("Choix invalide. Retour au menu principal.\n");
            break;
    }
    pause();
}


// tijara hh
void afectuer_achat() {
    int id_produit, quantity;
    int found = 0;
    if (clt.id == 0) {
        printf("Veuillez creer un profil client avant d'effectuer un achat pour avoir un solde.\n");
        pause();
        return;
    }

    afficher_cataloge();

    printf("            Entrez l'ID du produit à acheter:       ");
    scanf("%d", &id_produit);
    float total_price = 0;
    for (int i = 0; i < nombre_produit; i++) {
        if (arr_produits[i].id_prod == id_produit) {
            found = 1;
            printf("        Produit trouve: %s | Prix: %.2f MAD | Stock: %d\n       ",
                   arr_produits[i].nom_prod, arr_produits[i].prix_prod, arr_produits[i].stock_prod);
            printf("        Entrez la quantite a acheter:       ");
            scanf("%d", &quantity);
            if (quantity > 0 && quantity <= arr_produits[i].stock_prod) {
                total_price = arr_produits[i].prix_prod * quantity;
                if (clt.solde >= total_price) {
                    clt.solde -= total_price;
                    arr_produits[i].stock_prod -= quantity;

                    arr_achats[nombre_achats] = (achat){++id_gen, id_produit, arr_produits[i].prix_prod, quantity, {0,0,0}};
                    nombre_achats++;
                    printf("Achat effectue avec succes! Total: %.2f MAD | Nouveau solde: %.2f MAD\n",
                           total_price, clt.solde);
                } else {
                    printf("        Solde insuffisant pour efectuer cette operation.  :/        \n");
                }
            } else {
                printf("            Quantite invalide ou stock insuffisant. Achat annule.  :/       \n");
            }
            break;
        }
    }
    if (!found) {
        printf("Produit non trouve.\n");
    }
    pause();
}


//statistiques
void afficher_stats_produits() {
    printf(" Stock des produits mettes a jour \n");
    for (int i = 0; i <nombre_produit ; i++)
    {
                    printf("      Produit : %s | Stock: %d\n       ",
                   arr_produits[i].nom_prod, arr_produits[i].stock_prod);
    }
    
    pause();
}
// histoire des achats
void afficher_historique_achats() {
    if (nombre_achats == 0) {
        printf("Aucun achat effectue. :( \n");
        return;
    }
    printf("            **********Historique des achats:**********          \n");
    for (int i = 0; i < nombre_achats; i++) {
        printf("ID Achat: %d | ID Produit: %d | Prix: %.2f MAD | Quantite: %d\n",
               arr_achats[i].id_achat, arr_achats[i].id_produit, arr_achats[i].prix, arr_achats[i].quantity);
    }
    pause();
}


// main et menu
int main() {
    intialisations_prod();
    printf("        Bienvenue dans le systeme d'achat client! :3        \n");
    afficher_date();
    creer_profil();
    int choice;
    while (1) {
        printf("                 *************** Menu Principal ***************                 \n");
        printf("                 1. Afficher le catalogue de produits                 \n");
        printf("                 2. Rechercher un produit                  \n");
        printf("                 3. Trier les produits                  \n");
        printf("                 4. Gerer le profil client                 \n");
        printf("                 5. Gerer le solde du compte                 \n");
        printf("                 6. Effectuer un achat                 \n");
        printf("                 7. Afficher les statistiques d'achat                 \n");
        printf("                 8. Afficher l'historique des achats                 \n");
        printf("                 0. Quitter                 \n");
        printf("\n                          Votre choix: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                afficher_cataloge();
                pause();
                break;
            case 2:
                rechercher_produits();
                pause();
                break;
            case 3:
                triage_produits();
                pause();
                break;
            case 4:
                {
                    int profil_choice;
                    printf("                     Gestion du profil client:\n");
                    printf("                 1. Afficher le profil\n");
                    printf("                 2. Modifier le profil\n");
                    printf("                 3. Supprimer le profil\n");
                    printf("                 4. Retour au menu principal\n");
                    printf("\n                   Votre choix: ");
                    scanf("%d", &profil_choice);
                    switch (profil_choice) {
                        case 1:
                            afficher_profil();
                            pause();
                            break;
                        case 2:
                            modifier_profil();
                            pause();
                            break;
                        case 3:
                            supprimer_profil();
                            pause();
                            break;
                        case 4:
                            break;
                        default:
                            printf("\n                 Choix invalide.                 \n");
                            pause();
                            break;
                    }
                }
                break;
            case 5:
                gestion_solde();
                pause();
                break;
            case 6:
                afectuer_achat();
                pause();
                break;
            case 7:
                afficher_stats_produits();
                pause();
                break;
            case 8:
                afficher_historique_achats();   
                pause();
                break;
            case 0:
                printf("                         Au revoir! :3                \n");
                
            default:
                printf("           Choix invalide. Veuillez reessayer.  :/    \n");
                pause();
                break;
        }
    }
    return 0;
}

























//where tf the function
//where tf the function
//where tf the function
// bb giiiiiiiiiiiiiiiiiiiiirl

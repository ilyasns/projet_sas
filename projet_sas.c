
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



//les constontes uni

#define MAX_CLIENTS 100
#define MAX_PRODUCTS 100
#define MAX_ACHATS 100



//structures

typedef struct 
{
    int jour,mois,annee;
}date;

typedef struct 
{
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    float solde;
}client;

typedef struct 
{
    int id_prod;
    char nom_prod[50];
    char categorie_prod[50];
    float prix_prod;
    int stock_prod;
    char discription[150];
}produit;

typedef struct 
{
    int id_achat;
    int id_produit;
    float prix;
    int quantity;
    int date_achat;
}achat;


//globale variables

client clt;
produit arr_produits[MAX_PRODUCTS];
int nombre_produit = 0;
achat arr_achats[MAX_ACHATS];
int nombre_achats = 0;
int id_gen = 0;

// fonctions

void pause(){
    printf("Appuyer sur Entrée pour continuer <3  ");
    getchar();
    getchar();
}

void generer_email(){
    snprintf(clt.email, "%s.%s@client.com",
             clt.prenom, clt.nom);
    for (int i = 0; i < clt.email[i]; i++)
    {
        clt.email[i] = tolower(clt.email[i]);
    }
}

void intialisations_prod(){
    nombre_produit = 5;
    arr_produits[0] = (produit){1,"Ordinateur portable","Electronique",799.00,5,"PC wa3er a as7bi aji 5odo "};
    arr_produits[1] = (produit){2,"Smartphone","Electronique",499.00,10,"3laxe txri iphone o nta t9dr txri had tele o t3tini lfloss li b9at ;)"};
    arr_produits[2] = (produit){3,"Casque Audio","Electronique",89.00,15,"best head phones from l9ri3a"};
    arr_produits[3] = (produit){4,"Souris","Electronique",25.00,20,"Souris nadia 3la 7ssabi"};
    arr_produits[4] = (produit){5,"Clavier","Electronique",45.00,12;"Clavier dial l gamers o dakxi hh"};
}


void afficher_cataloge(){
    printf("\n=== Catalogue des Produits ===\n");
    for (int i = 0; i < nombre_produit; i++) {
        afficher_produit(&arr_produits[i]);
    }
}



void rechercher_produit_par_nom(){
    char nom_recherche[50];
    int found = 0;
    printf("Entrez le nom du produit à rechercher: ");
    scanf("%49s", nom_recherche);
    for (int i = 0; i < nombre_produit; i++) {
        if (strstr(arr_produits[i].nom_prod, nom_recherche) != NULL) {
            afficher_produit(i);
            found = 1;
            return;
        }
    }
    if (!found ){
        printf("Produit non trouve.\n");
    }
}

void rechercher_produit_par_categorie(){
    char categorie[50];
    int found = 0;
    printf("Entrez la categorie du produit a rechercher: ");
    scanf("%49s", categorie);
    printf("Produits dans la categorie %s:\n", categorie);
    for (int i = 0; i < nombre_produit; i++) {
        if (strcmp(arr_produits[i].categorie_prod, categorie) == 0) {
            afficher_produit(i);
            found = 1;
        }
    }
    if (!found ){
        printf("Aucun produit trouve dans cette categorie.\n");
    }
}

void trier_produits_par_prix(){
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


void creer_profil(){
    printf("Entrez votre nom: ");
    scanf("%49s", clt.nom);
    printf("Entrez votre prenom: ");
    scanf("%49s", clt.prenom);
    generer_email();
    clt.id = 1; 
    clt.solde = 0.0;
    printf("Profil cree avec succes!\n");
    printf("ID: %d | Nom: %s | Prenom: %s | Email: %s | Solde: %.2f MAD\n",
           clt.id, clt.nom, clt.prenom, clt.email, clt.solde);
}

void modifier_profil(){
    printf("Modifier votre profil:\n");
    printf("Entrez votre nouveau nom (actuel: %s): ", clt.nom);
    scanf("%49s", clt.nom);
    printf("Entrez votre nouveau prenom (actuel: %s): ", clt.prenom);
    scanf("%49s", clt.prenom);
    generer_email();
    printf("yay Profil modifie avec succes!\n");
    printf("ID: %d | Nom: %s | Prenom: %s | Email: %s | Solde: %.2f MAD\n",
           clt.id, clt.nom, clt.prenom, clt.email, clt.solde);
}

void afficher_profil(){
    printf("Votre profil:\n");
    printf("ID: %d | Nom: %s | Prenom: %s | Email: %s | Solde: %.2f MAD\n",
           clt.id, clt.nom, clt.prenom, clt.email, clt.solde);
}

void supprimer_profil(){
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


void gestion_solde(){
    int choice;
    float amount;
    printf("gestion de solde: \n");
    printf("1. Ajouter du soldes\n");
    printf("2. Aficher votre solde\n");
    printf("3. Retirer du solde\n");
    printf("4. Retour au menu principal\n");
    printf(" Votre choix:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf(" Donner le montant a ajouter:");
            scanf("%f", &amount);
            if (amount > 0) {
                clt.solde =clt.solde + amount;
                printf("Montant ajoute avec succès! Nouveau solde: %.2f MAD\n", clt.solde);
            } else {
                printf("Montant invalide, le montant est negatif Operation annulee.\n");
            }
            break;
        case 2:
            printf("Votre solde actuel est: %.2f MAD\n", clt.solde);
            break;
        case 3:
            amount = 0;
            printf("Donner le montant a retirer:"); 
            scanf("%f", &amount);
            if (amount>0 && amount <= clt.solde){
                clt.solde = clt.solde - amount;
            }else
            {
                printf("Montant invalide ou solde insuffisant. Opération annulee.\n");
            }
            break;
        case 4:
            return; 
            default:
            printf("Choix invalide. Retour au menu principal.\n");
            break;
        } pause();
}

void afectuer_achat(){
    int id_produit, quantity;
    int found = 0;
    if (clt.id == 0) {
        printf("Veuillez creer un profil avant d'effectuer un achat.\n");
        pause();
        return;
    }
    aficher_cataloge();

    printf("Entrez l'ID du produit à acheter: ");
    scanf("%d", &id_produit);
    int found = 0;
    float total_price ;
    for (int i = 0; i < nombre_produit; i++) {
        if (arr_produits[i].id_prod == id_produit) {
            found = 1;
            printf("Produit trouve: %s | Prix: %.2f MAD | Stock: %d\n",
                   arr_produits[i].nom_prod, arr_produits[i].prix_prod, arr_produits[i].stock_prod);
            printf("Entrez la quantite à acheter: ");
            scanf("%d", &quantity);
            if (quantity > 0 && quantity <= arr_produits[i].stock_prod) {
                float total_price = arr_produits[i].prix_prod * quantity;
                if (clt.solde >= total_price) {
                    clt.solde -= total_price;
                    arr_produits[i].stock_prod -= quantity;
                    arr_achats[nombre_achats] = (achat){++id_gen, id_produit, arr_produits[i].prix_prod, quantity, {0,0,0}};
                    nombre_achats++;
                    printf("Achat effectue avec succes! Total: %.2f MAD | Nouveau solde: %.2f MAD\n",
                           total_price, clt.solde);
                } else {
                    printf("Solde insuffisant. Achat annule.\n");
                }
            } else {
                printf("Quantite invalide ou stock insuffisant. Achat annule.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Produit non trouve.\n");
    }
    pause();
}




void afficher_stats(){
    if (nombre_achats == 0) {
        printf("Aucun achat effectue.\n");
        return;
    }
    printf("Historique des achats:\n");
    for (int i = 0; i < nombre_achats; i++) {
        printf("ID Achat: %d | ID Produit: %d | Prix: %.2f MAD | Quantite: %d | Date: %02d/%02d/%04d\n",
               arr_achats[i].id_achat, arr_achats[i].id_produit, arr_achats[i].prix, arr_achats[i].quantity,
               arr_achats[i].date_achat.jour, arr_achats[i].date_achat.mois, arr_achats[i].date_achat.annee);
    }
    pause();
}




 
// Main menu 
int main() {
        intialisations_prod();
        creer_profil();
        int choice;
        while (1) {
            printf("*************** Menu Principal ***************\n");
            printf("1. Afficher le catalogue de produits\n");
            printf("2. Rechercher un produit par nom\n");
            printf("3. Rechercher un produit par categorie\n");
            printf("4. Trier les produits par prix\n");
            printf("5. Gerer le profil client\n");
            printf("6. Gerer le solde du compte\n");
            printf("7. Effectuer un achat\n");
            printf("8. Afficher les statistiques d'achat\n");
            printf("0. Quitter\n");
            printf("Votre choix: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    afficher_cataloge();
                    pause();
                    break;
                case 2:
                    rechercher_produit_par_nom();
                    pause();
                    break;
                case 3:
                    rechercher_produit_par_categorie();
                    pause();
                    break;
                case 4:
                    trier_produits_par_prix();
                    pause();
                    break;
                case 5:
                    {
                        int profil_choice;
                        printf("Gestion du profil client:\n");
                        printf("1. Afficher le profil\n");
                        printf("2. Modifier le profil\n");
                        printf("3. Supprimer le profil\n");
                        printf("4. Retour au menu principal\n");
                        printf("Votre choix: ");
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
                                printf("Choix invalide.\n");
                                pause();
                                break;
                        }
                    }
                    break;
                case 6:
                    gestion_solde();
                    pause();
                    break;
                case 7:
                    afectuer_achat();
                    pause();
                    break;
                case 8:
                    afficher_stats();
                    pause();
                    break;
                case 0:
                    printf("Au revoir!\n");
                    exit(0);
                default:
                    printf("Choix invalide. Veuillez reessayer.\n");
                    pause();
                    break;
            }
        }
  

    return 0;
}
 

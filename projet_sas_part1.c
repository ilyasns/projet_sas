
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
    int date_achat
}achat;



// fonctions

void pause(){
    printf("Appuyer sur Entrée pour continuer <3  ");
    getchar();
    getchar();
}

void generer_email(){
    snprintf(clt->email, sizeof(clt->email), "%s.%s@client.com",
             clt->prenom, clt->nom);
    tolower(clt->email);
}

void intialisations_prod( produit arr_produits, int* n){
    *n = 5;
    arr_produits[0] = (produit){1,"Ordinateur portable","Electronique",799.00,5,"PC wa3er a as7bi aji 5odo "};
    arr_produits[1] = (produit){2,"Smartphone","Electronique",499.00,10,"3laxe txri iphone o nta t9dr txri had tele o t3tini lfloss li b9at ;)"};
    arr_produits[2] = (produit){3,"Casque Audio","Electronique",89.00,15,"best head phones from l9ri3a"};
    arr_produits[3] = (produit){4,"Souris","Electronique",25.00,20,"Souris nadia 3la 7ssabi"};
    arr_produits[4] = (produit){5,"Clavier","Electronique",45.00,12;"Clavier dial l gamers o dakxi hh"};
}

void afficher_produit(const produit* p){
    printf("ID:%d | %s | Catégorie: %s | Prix: %.2f MAD | Stock: %d\n",
            p->id_prod, p->nom_prod, p->categorie_prod, p->stock_prod, p->discription);
}

void rechercher_produit_par_nom(const  )












 
// Main menu 
int main() {
    int choix;
  

    return 0;
}
 






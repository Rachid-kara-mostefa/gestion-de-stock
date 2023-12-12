#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int exist(int num);
int existnom(char c[20]);
void affichers();
void afficherm();
void choice();

void creer();
void ajouter();
void afficher();
void rechercher();
void supprimer();
void modifier();
void mouvement();
void maj(FILE* f, FILE* m);
void affichermaj();

typedef struct {
	int numero;
	char nom[50];
	int quantite;
	float prix;
}article;
 article art;
                     // ***** FONCTION SECONDAIRES 
                     
// fonction qui verifie si un article existe
int existnom(char c[20]){
	
	int a;
		FILE *f;
	f = fopen("stock.txt","r");
		do{
		fscanf(f," %d \t %s \t %d \t %f \n",&art.numero, &art.nom, &art.quantite, &art.prix);
		a=stricmp(art.nom,c);
		if(a==0)
		return 1;
			
	}while(!feof(f));
	fclose(f);
	fflush(stdin);
}
   
// fonction afficher apres suppression
void affichers(){
	FILE* fs;
	fs=fopen("stocksup.txt","r");
	printf(" CONTENU DU FICHIER STOCK APRES SUPPRESSION : \n");
	printf(" numero  nom \t \t quantite \t prix unite  \t \t prix total \n");
	do{
		fscanf(fs," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
		printf(" %d   \t",art.numero);
		printf(" %s   \t",art.nom);
		printf(" %d   \t",art.quantite);
		printf(" \t %f \t",art.prix);
		printf(" \t %f \n",art.prix*art.quantite);		
	} while(!feof(fs));
	fclose(fs);
	fflush(stdin);
}   

// fonction afficher apres modification
void afficherm(){
		FILE* fm;
	fm=fopen("stockmod.txt","r");
	printf(" CONTENU DU FICHIER STOCK APRES MODIFICATION : \n");
	printf(" numero  nom \t \t quantite \t prix unite  \t \t prix total \n");
	do{
		fscanf(fm," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
		printf(" %d   \t",art.numero);
		printf(" %s   \t",art.nom);
		printf(" %d   \t",art.quantite);
		printf(" \t %f \t",art.prix);
		printf(" \t %f \n",art.prix*art.quantite);		
	} while(!feof(fm));
	fclose(fm);
	fflush(stdin);
}

// fonction afficher mise a jour
void affichermaj(){
	FILE* f;
	f=fopen("stockmaj.txt","r");
	printf(" CONTENU DU FICHIER STOCK MIS A JOUR : \n");
	printf(" numero  nom \t \t quantite \t prix unite  \t \t prix total \n");
	do{
		fscanf(f," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
		printf(" %d   \t",art.numero);
		printf(" %s   \t",art.nom);
		printf(" %d   \t",art.quantite);
		printf(" \t %f \t",art.prix);
		printf(" \t %f \n",art.prix*art.quantite);		
	} while(!feof(f));
	fclose(f);
	fflush(stdin);
}

// fonction switch                
void choice(){
	FILE *f,*m;
	printf("\n");
int choix;
char v[20];

printf("Que voulez vous faire ? \n\n");
printf("0- Creer un fichier de stockage de produits \n");
printf("1- Ajouter des articles dans ce fichier STOCK \n");	
printf("2- Afficher les articles de ce fichier STOCK \n");
printf("3- Rechercher des articles dans ce fichier STOCK \n");
printf("4- Supprimer des articles de ce fichier STOCK \n");	
printf("5- Modifier des articles de ce fichier STOCK \n");	
printf("     partie 2 : \n");
printf("7- Creer un fichier MOUVEMENT \n");
printf("8- Mettre a jour le fichier STOCK  \n");	
printf("9- Verifier la mise a jour \n");
printf("\n\t");
scanf("%d",&choix);

switch(choix){
	case 0 : 
		creer();
		printf("Votre fichier de stockage : STOCK a bien ete cree\n");
		choice();
		break;
	case 1 : 
		ajouter();
		printf("Votre article a bien ete ajoute dans le fichier de stockage \n");
		printf(" \n voulez vous ajouter un autre article ? \n");
		printf("y = oui\n");
		printf("n = non\n\n");
		scanf("%s", &v);
			if(stricmp(v,"y") == 0)
				{ajouter();
				choice();}
			else 
			   choice();
		break;
	case 2 : 
		afficher();
		printf("\n ");
		choice();
		break;
	case 3 : 
		rechercher();
		printf(" \n voulez vous rechercher un autre article ? \n");
		printf("y = oui\n");
		printf("n = non\n\n");
		scanf("%s", &v);
			if(stricmp(v,"y") == 0)
				{rechercher();
				choice();}
			else 
			   choice();
		break;
	case 5 : 
		modifier();
		printf(" \n voulez vous modifier un autre article  ? \n");
		printf("y = oui\n");
		printf("n = non\n\n");
		scanf("%s", &v);
			if(stricmp(v,"y") == 0)
				{modifier();
				choice();}
			else 
			   choice();
		break;
	case 4 : 
		supprimer();
		printf(" \n voulez vous supprimer un autre article ? \n");
		printf("y = oui\n");
		printf("n = non\n\n");
		scanf("%s", &v);
			if(stricmp(v,"y") == 0)
			{	supprimer();
				choice();}
			else 
			   choice();
		break;
	case 7 :
		mouvement();
		choice();
		break;	
	case 8 :
		maj(f,m);
		choice();
		break;
	case 9 :
		affichermaj();
		printf("\n ");
		choice();
		break;
	default :
		printf(" veuillez entrer un nombre entre 1 et 9\n");
		choice();
		break;
	}

}
                
                     // ****** FONCTIONS PRINCIPALES
// fonction creer
void creer(){
	FILE* f;
	f=fopen("stock.txt","a");
	if(f == NULL)
	printf("erreur lors de l'ouverture du fichier STOCK \n");
	fclose(f);
	printf(" creation du fichier avec succes\n");
}

// fonction ajouter *
void ajouter(){
	FILE* f;
	f=fopen("stock.txt","a");
	char nom[50];
	int t;
		printf(" entrez le nom de l'article que vous voulez ajouter\n  ");
		scanf("%s",&nom);
		printf("Bien, maintenant \n");
				if( existnom(nom) == 1){
					printf("  cet article existe deja \n\n");
				}	
				else
					{
					printf(" numero de l'article: ");	    scanf("%d",&art.numero);
					printf(" quantite de l'article : ");	scanf("%d",&art.quantite);
					printf(" prix unitaire en euro: ");	    scanf("%f",&art.prix);
					fprintf(f," %d \t %s \t %d \t %f \n",art.numero, nom, art.quantite, art.prix);
		
				}
	fflush(stdin);
	fclose(f);
}

// fonction afficher
void afficher(){
	FILE* f;
	f=fopen("stock.txt","r");
	printf(" CONTENU DU FICHIER STOCK : \n");
	printf(" numero  nom \t \t quantite \t prix unite  \t \t prix total \n");
	do{
		fscanf(f," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
		printf(" %d   \t",art.numero);
		printf(" %s   \t",art.nom);
		printf(" %d   \t",art.quantite);
		printf(" \t %f \t",art.prix);
		printf(" \t %f \n",art.prix*art.quantite);		
	} while(!feof(f));
	fclose(f);
	fflush(stdin);
}

// fonction supprimer *
void supprimer(){
	char c[15]; char mot[50];int exi,temp,r;
	printf("Entrez l'article que vous voulez supprimer \n");
	scanf("%s",&mot);
		exi=existnom(mot);
		fflush(stdin);
	if( exi == 1 ){
		printf("Voulez vous vraiment supprimer cet article ? \n ");
		printf("oui/non\n");
		scanf("%s",&c);
		temp=stricmp(c,"oui");
		if( temp == 0){
			FILE* fs; FILE* f;
			f=fopen("stock.txt","r");
			fs=fopen("stocksup.txt","w+");
			do{
				fscanf(f," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
				r=stricmp(mot,art.nom);
					if( r!=0){
					fprintf(fs," %d \t %s \t %d \t %f \n",art.numero ,art.nom ,art.quantite ,art.prix);
					}
			}while(!feof(f));
	
		fclose(fs);
		fclose(f);
		remove("stock.txt");
	if( rename("stocksup.txt","stock.txt") == 0)
		printf("suppression reussie\n"); 
	else
	printf(" not okay");
		 
	
				}
			else
		printf("suppression annulee");
	}
	else
	printf("l'article que vous voulez supprimer n'existe pas dans STOCK \n");
	
	fflush(stdin);
}

// fonction rechercher 
void rechercher(){
		char c[50];
	int a;
	printf("entrez un  l'article que vous voulez rechercher ? \n");
		scanf("%s",&c);
		if(existnom(c) != 1){
			printf("Cet article n'existe pas dans le fichier STOCK");
		}
		else{
		FILE *f;
		f = fopen("stock.txt","r");
		do{
		fscanf(f," %d \t %s \t %d \t %f \n",&art.numero, &art.nom, &art.quantite, &art.prix);
		a=stricmp(art.nom,c);
		if(a==0){
	printf("  Voici les informations sur cet article \n"); 
printf(" le numero de l'article : %d\n le nom de l'article : %s\n la quantite de l'article : %d\n le prix de l'article : %f \n",art.numero, art.nom, art.quantite, art.prix);
	}
		
	}while(!feof(f));
	fclose(f);
	}
}

// fonction modifier *
void modifier(){
char c[15]; 	char mot[50];	int exi,temp,r;
	printf("entrez l'article que vous voulez modifier \n");
	scanf("%s",&mot);
		exi=existnom(mot);
		fflush(stdin);
	if( exi == 1 ){
		printf("voulez vous vraiment modifier cet article ? \n ");
		scanf("%s",&c);
		temp=stricmp(c,"oui");
		if( temp == 0){
			FILE* fm; FILE* f;
			f=fopen("stock.txt","r");
			fm=fopen("stockmod.txt","w+");
			do{
				fscanf(f," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
				r=stricmp(mot,art.nom);
					if( r!=0){
						fprintf(fm," %d \t %s \t %d \t %f \n",art.numero ,art.nom ,art.quantite ,art.prix);
					}
					else  {
						printf(" entrez le nouveau numero de l'article: \t");	    scanf("%d",&art.numero);
						printf(" entrez le nouveau nom de l'article: \t");	    scanf("%s",&art.nom);
						printf(" entrez la nouvelle quantite de l'article : \t");	scanf("%d",&art.quantite);
						printf(" entrez le nouveau prix unitaire en dinar: \t");	    scanf("%f",&art.prix);
						fprintf(fm," %d \t %s \t %d \t %f \n",art.numero, art.nom, art.quantite, art.prix);
					}
			}while(!feof(f));
	
		fclose(f);
		fclose(fm);
			remove("stock.txt");
	if( rename("stockmod.txt","stock.txt") == 0)
		printf("suppression reussie\n"); 
	else
	printf(" not okay");
				}
			else
		printf("modification annulee");
	}
	else
	printf("l'article que vous voulez modifier n'existe pas dans STOCK \n");
	
	fflush(stdin);
}

// fonction mouvement
void mouvement(){
	FILE* m;
	m=fopen("mouvement.txt","a");
	if(m == NULL)
	printf("erreur lors de l'ouverture du fichier MOUVEMENT \n");
	fclose(m);
	printf(" creation du fichier MOUVEMENT avec succes\n");
}

// fonction mise a jour *
void maj(FILE* f , FILE* m){

	f = fopen("stock.txt","r");
	FILE* j;
	j=fopen("stockmaj.txt","w");
		do{
			fscanf(f," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
			fprintf(j," %d \t %s \t %d \t %f \n",art.numero ,&art.nom ,art.quantite ,art.prix);
			}while( !feof(f) );
	fclose(f);
	m = fopen("mouvement.txt","r");
		do{
			fscanf(m," %d \t %s \t %d \t %f \n",&art.numero ,&art.nom ,&art.quantite ,&art.prix);
			fprintf(j," %d \t %s \t %d \t %f \n",art.numero ,&art.nom ,art.quantite ,art.prix);
			}while( !feof(m) );
	fclose(m);
		fclose(j);
		printf("fichier stock mis a jour \n");

}

main(){
	// carreee d'etoiles
	int i,j,k;
	for(i=0;i<12;i++){
			if(i == 0 || i == 11){
				for(j=0;j<15;j++){
					printf(" * ");
					}
			}
			else if(i == 5){
				printf(" *  BIENVENUE DANS LE SYSTEME DE STOCKAGE  *\n *        DE VOTRE ENTREPRISE  \t\t   * ");
			}
			else{
				for(k=0;k<15;k++){
					if(k == 0 || k == 14){
						printf(" * ");
										}
					else
						printf("   ");
					}
				}	
					printf("\n");
}
// switch
choice();



}
	
		
		
		
		

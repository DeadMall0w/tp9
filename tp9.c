// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"


int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier file.c");
printf("\n 2 : tester mon fichier pile.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 20 : File - Initialisation ");
printf("\n 21 : File - Ajouter ");
printf("\n 22 : File - Retirer ");
printf("\n 23 : File - Vide ");
printf("\n 24 : File - Pleine ");
printf("\n 25 : File - Affichage ");



// printf("\n 4 : afficher et compter les solutions pour un échiquier ");
// printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

int main()
{
T_File mafile;
T_Pile mapile;
int chx;
int res;
// int taille;
//char chaine[20];

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		//testez toutes vos fonctions par un jeu de test de votre choix
		//testPile(&mapile); //TP9 partie 1 : à ecrire 
		break;
	case 2 : //testez toutes vos fonctions par un jeu de test de votre choix
		// testFile(&mafile); //TP9 partie 1 : à ecrire 

		printf("Intialisation de la file \n");
		initFile(&mafile);
		printf("Test 1 - Voir si la file est pleine/vide\n");
		res = fileVide(&mafile);
		if (res == 0)
			printf("File non vide\n");
		else
			printf("File vide\n");
		
		printf("\n");

		res = filePleine(&mafile);
		if (res == 0)
			printf("File non pleine\n");
		else
			printf("File pleine\n");

		printf("Test 2 - Ajout de 10 d'éléments\n");
		for  (int i = 0; i < 10; i++)
		{
			T_Elt t = i;
			printf("Ajout de %d \n", t);
			res = ajouter(&mafile, &t);

			if (res == 0)
				printf("Ajout réussi !\n");
			else
				printf("Erreur : file pleine \n");
		}

		printf("Test 3 - Voir si la file est pleine/vide\n");
		res = fileVide(&mafile);
		if (res == 0)
			printf("File non vide\n");
		else
			printf("File vide\n");
		
		printf("\n");

		res = filePleine(&mafile);
		if (res == 0)
			printf("File non pleine\n");
		else
			printf("File pleine\n");



		printf("Affichage de la file : \n");
		afficherFile(&mafile);

		printf("Test 4 - Tenter d'enlever et afficher 10 éléments\n");
		for  (int i = 0; i < 10; i++)
		{
			T_Elt t;
			res = retirer(&mafile, &t);

			if (res ==0)
				afficherElt(&t);
			else 
				printf("Erreur : file vide\n");
		}

		printf("Test 5 - Ajout et suppression d'éléments\n");

		printf("Ajout de 17\n");
		T_Elt t = 17;
		res = ajouter(&mafile, &t);
		
		printf("Ajout de 18\n");
		t = 18;
		res = ajouter(&mafile, &t);

		printf("Ajout de 19\n");
		t = 19;
		res = ajouter(&mafile, &t);
		
		printf("Affichage du premier élément\n");

		T_Elt te;
		res = retirer(&mafile, &te);
		afficherElt(&te);


		printf("Affichage du premier élément\n");
		te;
		res = retirer(&mafile, &te);
		afficherElt(&te);

		
		printf("Ajout de 20\n");
		t = 20;
		res = ajouter(&mafile, &t);
		
		printf("\nAffichage du premier élément\n");
		te;
		res = retirer(&mafile, &te);
		afficherElt(&te);

		
		
		printf("Ajout de 21\n");
		t = 21;
		res = ajouter(&mafile, &t);
		
		printf("\nAffichage du premier élément\n");
		te;
		res = retirer(&mafile, &te);
		afficherElt(&te);

		
		printf("\nAffichage du premier élément\n");
		te;
		res = retirer(&mafile, &te);
		afficherElt(&te);

		




		break; 
	case 3 : 
		//scanf("%s",chaine); //une chaine de longueur <=MAX
		//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;
	case 20:
		//* Initialiser la pile
		initFile(&mafile);
		
		break;
	case 21:
		//* Ajouter un element da la pile
		T_Elt e;
		printf("Entrer une valeur à ajouter : ");
		saisirElt(&e);
		res = ajouter(&mafile, &e);
		if (res == 0)
			printf("Ajout réussi !\n");
		else
			printf("Erreur : file pleine \n");
		break;
	case 22:
		//* Défiler un élément
		T_Elt tet;
		res = retirer(&mafile, &tet);
		if (res ==0)
			afficherElt(&tet);
		else 
			printf("Erreur : file vide\n");
		break;
	case 23:
		//* Renvoie 1 ou 0 si la file est vide ou pas
		res = fileVide(&mafile);
		if (res == 0)
			printf("File non vide\n");
		else
			printf("File vide\n");
		// printf("Etat de remplissage de la pile : %d \n", fileVide(&mafile));
		break;
	case 24:
		res = filePleine(&mafile);
		if (res == 0)
			printf("File non pleine\n");
		else
			printf("File pleine\n");
		
		break;
	case 25:
		printf("Affichage de la file : \n");
		afficherFile(&mafile);
		break;
	case 26:
		//* AJouter 3 éléments dans la pile
		for (int i = 0; i < 3; i++)
		{
			T_Elt e;
			printf("Entrer une valeur à ajouter : ");
			saisirElt(&e);
			ajouter(&mafile, &e);
		}
	case 27:
		// T_Elt e;  
		T_Elt ett = premier(&mafile); //valeur en tete de file
		afficherElt(&ett);
		break;		

	case 29:
		debugFile(&mafile);
		break;
	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}

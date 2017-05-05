#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int 			main(int ac, char **av)
{
	const int 	MIN = 1;
	int 	 	MAX = 100;
	int			nombre_mystere;
	int			choix;
	int			continuer;
	int 		compteur = 1;
	bool		restart = 1;
	int 		difficulte = 0;
	// Intro
	printf("Bonjour et bienvenue sur mon Plus ou Moins !\n");
	printf("Merci beaucoup de prendre du temps pour me corriger ;)\n");
	// Menu de difficulte
	printf("Quel niveau de difficulte desirez vous ?\n");
	printf("1 = nombre mystere entre 1 et 100\n2 = nombre mystere entre 1 et 1000\n3 = nombre mystere entre 1 et 10000\n");
	scanf("%d", &difficulte);
	if (difficulte == 1)
		MAX = 100;
	else if (difficulte == 2)
		MAX = 1000;
	else if (difficulte == 3)
		MAX = 10000;
	else
		MAX = 100;
	printf("Vous avez choisis la difficulte %d le nombre mystere sera donc entre 1 et %d\n", difficulte, MAX);
	while (restart == 1)
	{
		// Choix du nombre random
		srand(time(NULL));
		nombre_mystere = (rand() % (MAX - MIN + 1)) + MIN;
		// Debut boucle
		while (choix != nombre_mystere)
		{
			// Choix nombre
			printf("Entrez un nombre : ");
			scanf("%d", &choix);
			// Comparaison
			if (choix < nombre_mystere)
				printf("C'est plus !\n");
			else if (choix > nombre_mystere)
				printf("C'est moins !\n");
			else
			{
				printf("C'est bon !!!\nVous avez trouve le nombre mystere en %d coups. BRAVO !\n", compteur);
				compteur = 0;
			}
			compteur++;
		}
		printf("Souhaitez vous refaire une partie ? (1 = Oui / 0 = Non) ");
		scanf("%d", &continuer);
		if (continuer == 1)
			restart = 1;
		else
			restart = 0;
	}
	printf("Merci d'avoir joue !\n");
	return 0;
}
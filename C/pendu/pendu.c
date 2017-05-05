#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void		get_stars(char *mot_mystere, int *tab, int word_len, char c)
{
	int		i = 0;

	while (i < word_len)
	{
		if (c == mot_mystere[i] || tab[i] == 1)
		{
			tab[i] = 1;
			printf("%c", mot_mystere[i]);
		}
		else
		{
			tab[i] = 0;
			printf("*");
		}
		i++;
	}
	printf("\n");
}

char 		read_char() 
{ 
    char 	caractere = 0;
 
    caractere = getchar();
    caractere = toupper(caractere);
    while (getchar() != '\n')
    	;
    return caractere;
}

int 		check(char *mot_mystere, int word_len, char c)
{
	int 	i = 0;
	while (i < word_len)
	{
		if (c == mot_mystere[i])
			return 1;
		else
			i++;
	}
	return 0;
}

int 		win(int *tab, int word_len)
{
	int 	i = 0;
	int 	won = 1;

	while (i < word_len)
	{
		if (tab[i] == 0)
			won = 0;
		i++;
	}
	return won;
}

int 		main(int ac, char **av)
{
	char 	*mot_mystere = "MARRON";
	int 	*tab;
	int 	word_len = strlen(mot_mystere);
	char 	c;
	int		coups = 10;

	tab = malloc(sizeof(int) * word_len + 1);
	// INTRO
	printf("Bienvenue sur le Pendu \n");
	printf("Merci beaucoup de prendre du temps pour me corriger ;)\n\n");
	// Boucle tant qu'il reste des coups
	while (coups > 0 && !win(tab, word_len))
	{
		if (coups > 1)
			printf("Il vous reste %d coups a jouer\n", coups);
		else
			printf("Il vous reste %d coup a jouer\n", coups);
		printf("Quel est le mot secret ? ");
		get_stars(mot_mystere, tab, word_len, c);
		printf("Proposez une lettre : ");
		c = read_char();
		if (check(mot_mystere, word_len, c) == 0)
			coups--;
		else
			;
	}
	if (coups == 0)
		printf("\nDOMMAGE :( Le mot a trouver etait : %s\n", mot_mystere);
	else
		printf("\nBRAVO !!! Vous avez trouve le mot mystere : %s\n", mot_mystere);
	return 0;
}
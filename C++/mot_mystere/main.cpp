#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int		restart()
{
	char recommencer;

	cout << "Voulez-vous refaire une partie ? o/n" << endl;
	cin >> recommencer;
	if (recommencer == 'n')
		return 0;
	else
		return 1;
}

string 	melangeur(string motMystere)
{
	string 	motMelanger;
	int		position(0);

	while (motMystere.size() != 0)
	{
		position = rand() % motMystere.size();
		motMelanger += motMystere[position];
		motMystere.erase(position, 1);
	}
	return motMelanger;
}

string	dictionnaire()
{
	ifstream dico("dico.txt");
	string a, b;
	int i = 0;

	if (dico)
	{
		int	position(0);
		int	nbMots(0);
		while (getline(dico, a))
			nbMots++;
		dico.clear();
		dico.seekg(0, ios::beg);
		position = rand() % nbMots;
		while (i < position)
		{
			getline(dico, b);
			i++;
		}
		return b;
	}
	else
		cout << "Impossible d'ouvrir le fichier dico.txt" << endl;
	return 0;
}

int 	main()
{
	string 	motMystere, motMelanger, motSaisi;
	int		recommencer = 1, essais = 5;
	char	res;

	srand(time(0));
	while (recommencer == 1)
	{
		int couts = 0;

		motMystere = dictionnaire();
		motMelanger = melangeur(motMystere);
		while (motSaisi != motMystere && couts != essais)
		{
			cout << "Quel est ce mot ? " << motMystere << endl;
			cin >> motSaisi;
			if (motSaisi == motMystere)
			{
				cout << "BRAVO ! Vous avez trouvé en " << couts+1 << " essais !" << endl;
				recommencer = restart();
			}
			else
			{
				cout << "Ce n'est pas le bon mot..." << endl << "Il vous reste " << essais-couts-1 << " essais." << endl;
				couts++;
			}
			if (couts == essais)
			{
				cout << "Vous avez atteins le nombre maximal d'essais..." << endl << "Le mot mystere etait \"" << motMystere << "\" !" << endl;
				recommencer = restart();
			}
		}
	}
	return 0;
}
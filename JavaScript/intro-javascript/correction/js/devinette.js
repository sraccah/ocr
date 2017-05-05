/* 
Activité : jeu de devinette
*/

// NE PAS MODIFIER OU SUPPRIMER LES LIGNES CI-DESSOUS
// COMPLETEZ LE PROGRAMME UNIQUEMENT APRES LE TODO

console.log("Bienvenue dans ce jeu de devinette !");

// Cette ligne génère aléatoirement un nombre entre 1 et 100
var solution = Math.floor(Math.random() * 100) + 1;

// Décommentez temporairement cette ligne pour mieux vérifier le programme
console.log("(La solution est " + solution + ")");

// TODO : complétez le programme
var reponseJoueur;      // réponsde saisie par le joueur
var tour;               // comptage du nopmbre de tours (déclarée car utile en dehors de la boucle FOR)

// Une boucle permet au joueur de faire 6 essais
for (tour = 1;tour <= 6; tour++) {
    // on demande au joueur d'entrer un nombre
    reponseJoueur = Number(prompt("Devinez le nombre secret. \nEntrez un nombre entre 1 et 100."));
    // on compare le nombre saisi par le joueur à la solution :
    if (reponseJoueur < solution) {                         // si la réponse du joueur est trop petite..
        console.log(reponseJoueur + " est trop petit.");
    }
    else if (reponseJoueur > solution) {                    // si la réponse du joueur est trop grande..
        console.log(reponseJoueur + " est trop grand.");
    }
    else {                                                  // si la réponse du joueur est la bonne..
        console.log("Bravo ! La solution était " + solution);
        console.log("Vous avez trouvé en  " + tour + " essai(s)");
        tour=8;         // on met la variable tour à 8 pour sortir de la boucle FOR
    }                   // mais aussi pour esquiver le message de la ligne 38.
}

// si tour=7 c'est qu'on est sorti de la boucle FOR sans avoir gagné.. donc en ayant perdu 
if (tour === 7) {       
    console.log("Perdu ! La solution était " + solution);
}
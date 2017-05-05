<?php

// Connexion à la base de données
try
{
	$bdd = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', 'root');
}
catch(Exception $e)
{
	die('Erreur : '.$e->getMessage());
}

// Insertion du message à l'aide d'une requête préparée
$req = $bdd->prepare('INSERT INTO minichat (time, pseudo, message) VALUES(NOW(), ?, ?)');
$req->execute(array($_POST['pseudo'], $_POST['message']));

// On créer un cookie pour pouvoir récupérer le pseudo de l'utilisateur plus tard
setcookie('pseudo', $_POST['pseudo'], time() + 365*24*3600, null, null, false, true);

// Redirection vers la page du minichat
header('Location: minichat.php');

?>
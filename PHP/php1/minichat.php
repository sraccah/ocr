<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>Mini-Chat</title>
    </head>

    <!-- Style -->
    <style>
        form {
            text-align: center;
            border: 1px solid black;
        }
        .titre {
            text-align: center;
        }
        input {
            margin: 5px;
        }
        .chat {
            border: 1px solid black;
            padding-left: 10px;
        }
        .date {
            color: green;
        }
    </style>
    
    <body>
    
    <!-- Formulaire -->
    <h2 class="titre">Formulaire d'envoi :</h2>
    <form action="minichat_post.php" method="post">
        <p>
            <label for="pseudo">Pseudo</label> : <input type="text" name="pseudo" id="pseudo" value="<?php echo $_COOKIE['pseudo'] ?>" /><br />
            <label for="message">Message</label> :  <input type="text" name="message" id="message" /><br />
            <input type="submit" value="Envoyer" />
        </p>
    </form>

    <!-- Chat -->
    <h2 class="titre">Boîte de dialogue :</h2>
    <div class="chat">

<?php

// Connexion à la base de données
try
{
    // Ne pas oublier de mettre votre mot de passe (si vous en avez paramétré un) pour ne pas avoir une erreur 'SQLSTATE[HY000] [1045]'
    $bdd = new PDO('mysql:host=localhost;dbname=test;charset=utf8', 'root', 'root');
}
catch(Exception $e)
{
        die('Erreur : '.$e->getMessage());
}

// Récupération des 10 derniers messages
$reponse = $bdd->query('SELECT pseudo, message, DATE_FORMAT(time, "%d/%m/%Y %H:%i:%s") AS time FROM minichat ORDER BY ID DESC LIMIT 0, 10');

// Affichage de chaque message (toutes les données sont protégées par htmlspecialchars)
while ($donnees = $reponse->fetch())
{
    echo '<p>[<span class="date"><strong>' . $donnees['time'] .'</span>] ' . htmlspecialchars($donnees['pseudo']) . '</strong> : ' . htmlspecialchars($donnees['message']) . '</p>';
}

$reponse->closeCursor();

?>

    </div>

    </body>
</html>
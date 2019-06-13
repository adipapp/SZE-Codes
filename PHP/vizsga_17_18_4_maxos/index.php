<!DOCTYPE html>
<html lang="hu">
    <head>
        <title>Torpedó</title>
        <meta charset="UTF-8">
    </head>
    <body>
    	<h1>Torpedó</h1>

        <?php
            session_start();
            require_once 'tabla.php';

            if(!isset($_POST['jatekos']) && !isset($_SESSION['tabla'])){
                echo "<form method='post' action='".$_SERVER['PHP_SELF']."'>Játékos neve: <input type='text' name='jatekos'/><br/>";
                echo "Tábla szélessége: <input type='number' min='5' max='15' name='szel' /><br/>";
                echo "Tábla magassága: <input type='number' min='5' max='15' name='mag' /><br/>";
                echo "<input type='submit' value='Játék'/></form>";
                exit();
            }
        ?>

    	<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
    	<?php
            $tabla = null;
            if(isset($_POST['jatekos'])){
                $tabla = new Tabla($_POST['szel'], $_POST['mag'], $_POST['jatekos']);
            }
    		else if(isset($_SESSION['tabla'])){
    			$tabla = unserialize($_SESSION['tabla']);
            }
            if(isset($_POST['loves'])){
                $tabla->loves($_POST['loves']);
            }
            echo "<h3>".$tabla->jatekos." eddigi lövéseinek száma: ". count($tabla->lovesek) ."</h3>";
            echo $tabla->getHTML();
            $_SESSION['tabla'] = serialize($tabla);
    	?>
    	<input type="submit" name="kuld" value="Lövés">
    	</form>
    	<?php
    		if($tabla->elsullyedthajok == 4){
                require_once 'database.php';
                $database = new database("papp.com", "adam", "Kinemtalalod98", "php_vizsga");
                $database->insert("torpedo", "nev, lovesek", "'".$tabla->jatekos."', '".count($tabla->lovesek)."'", "");
                $database->runQuery();
                $database->select("torpedo", "*", "1", "order by lovesek asc limit 3");
                $database->runQuery();
                echo "<table><thead><tr><td>Helyezés</td><td>Név</td><td>Lövések száma</td></tr></thead><tbody>";
                $i = 1;
                while ($row = $database->getRow()) {
                    echo "<tr><td>".$i."</td><td>".$row['nev']."</td><td>".$row['lovesek']."</td></tr>";
                    $i += 1;
                }
    			echo "</tbody></table><br/><h3>Vége a játéknak!<br/><a href='".$_SERVER['PHP_SELF']."'>Új játék</a></h3>";
    			session_destroy();
    		}
    	?>
    </body>
</html>
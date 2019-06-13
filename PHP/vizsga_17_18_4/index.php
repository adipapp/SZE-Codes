<!DOCTYPE html>
<html lang="hu">
    <head>
        <title>Torpedó</title>
        <meta charset="UTF-8">
    </head>
    <body>
    	<h1>Torpedó</h1>
    	<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
    	<?php
    		session_start();
    		require_once 'tabla.php';
    		$tabla = new Tabla(10, 10);
    		if(isset($_SESSION['tabla'])){
    			$tabla = unserialize($_SESSION['tabla']);
    		}
    		if(isset($_POST['loves'])){
    			$tabla->loves($_POST['loves']);
    		}
    		echo "<h3>Eddigi lövések száma: ". count($tabla->lovesek) ."</h3>";
    		echo $tabla->getHTML();
    		$_SESSION['tabla'] = serialize($tabla);
    	?>
    	<input type="submit" name="kuld" value="Lövés">
    	</form>
    	<?php
    		if($tabla->elsullyedthajok == 4){
    			echo "<h3>Vége a játéknak!<br/><a href='".$_SERVER['PHP_SELF']."'>Új játék</a></h3>";
    			session_destroy();
    		}
    	?>
    </body>
</html>
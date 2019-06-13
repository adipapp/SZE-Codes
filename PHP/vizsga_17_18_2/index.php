<!DOCTYPE html>

<html lang="hu">
    <head>
        <title>Futóverseny</title>
        <meta charset="UTF-8">
    </head>
    <body>
        <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
            Rajtszám: <input type="number" name="rajtszam" required="required"> <p/>
            Ellenőrző pont: <input type="number" name="ellenorzopont" required="required" min="0" max="3"> <p/>
            Óra: <input type="number" name="ora" required="required" min="0" max="23"> <p/>
            Perc: <input type="number" name="perc" required="required" min="0" max="59"> <p/>
            Másodperc: <input type="number" name="mp" required="required" min="0" max="59"> <p/>
            <input type="submit" value="Elküld"> <p/>
        </form>
        <p/>

<?php

session_start();
ini_set('display_errors', 1);
require_once 'Meres.php';
require_once 'Futo.php';

if(!isset($_SESSION['futok'])){
	$_SESSION['futok'] = serialize(array());
}

$futok = unserialize($_SESSION['futok']);
if(isset($_POST['rajtszam'])){
	$elindult = false;
	$befutott = false;
	$meres = new Meres($_POST['rajtszam'], $_POST['ellenorzopont'], $_POST['ora'], $_POST['perc'], $_POST['mp']);

	foreach ($futok as $f) {
		if($f->getRajtszam() == $_POST['rajtszam']){
			if($f->getStatus() == 'még nem ért célba'){
				$f->addMeres($meres);
				$elindult = true;
			}
			else {
				$befutott = true;
			}
		}
	}

	if($elindult != true && $befutott != true){
		array_push($futok, new Futo($meres->getRajtszam(), $meres));
	}

	if($befutott != true){
		if(file_exists('futoverseny.json')){
			$temp = json_decode(file_get_contents('futoverseny.json'))->futoverseny;
		}
		else{
			echo 'aaa';
			$temp = array();
		}
		$t = array('rajtszam' => $meres->getRajtszam(), 'ellenorzopont' => $meres->getEllpont(), 'ora' => $meres->getOra(), 
			'perc' => $meres->getPerc(), 'mp' => $meres->getMp());
		array_push($temp, $t);
		file_put_contents('futoverseny.json', json_encode(array('futoverseny' => $temp)));
	}
}

echo "<table>";
foreach ($futok as $f) {
	echo $f->getHTML();
}
echo "</table>";



$_SESSION['futok'] = serialize($futok);

?>

    </body>
</html>
<!DOCTYPE html>

<html lang="hu">
    <head>
        <title>Időpontok egyeztetése</title>
        <meta charset="UTF-8">
    </head>
    <body>
        <h1>Időpontok egyeztetése</h1>

<?php

ini_set('display_errors', 1);
require_once 'Idopont.php';

$idopontok = array();

if(file_exists('idopontok.json')){
		$temp = json_decode(file_get_contents('idopontok.json'))->idopontok;
		$idopontok = array();
		foreach ($temp as $t) {
			array_push($idopontok, new Idopont($t->nev, $t->hetfo, $t->kedd, $t->szerda, $t->csutortok, $t->pentek));
		}
}
else{
	$idopontok = array();
}

if(isset($_POST['nev'])){
	$idopont = new Idopont($_POST['nev'], isset($_POST['hetfo']), isset($_POST['kedd']), isset($_POST['szerda']), isset($_POST['csutortok']), isset($_POST['pentek']));
	array_push($idopontok, $idopont);

	foreach ($idopontok as $i) {
		echo $i->toHTML();
	}

}

?>


<form action='<?php echo $_SERVER['PHP_SELF']; ?>' method='POST'>
            <input type='text' name='nev' required='required'>
            <input type='checkbox' name='hetfo'>
            <input type='checkbox' name='kedd'>
            <input type='checkbox' name='szerda'>
            <input type='checkbox' name='csutortok'>
            <input type='checkbox' name='pentek'> <p/>
            <input type='submit' value='Kész'> <p/>
</form>

<?php

	echo 'Eredmény';

	foreach (array('hetfo', 'kedd', 'szerda', 'csutortok', 'pentek') as $nap) {
		$mindjo = true;
		foreach ($idopontok as $i) {
			if(!($i->idopontok[$nap])){
				echo ' ';
				$mindjo = false;
				break;
			}
			if($mindjo){
				echo 'X';
			}
		}
	}

	$temp = array();
	foreach ($idopontok as $i) {
		array_push($temp, get_object_vars($i));
	}

	file_put_contents('idopontok.json', json_encode(array('idopontok' => $temp)));

?>

</body>
</html>
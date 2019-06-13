<?php

require_once 'Konyv.php';
require_once 'Konyvtar.php';

$konyv1 = new Konyv("The da-Vinci Code", "Dan Brown", "1234567891011", array("Robert Langdon", "Paris"));
$konyv2 = new Konyv("Inferno", "Dan Brown", "1234567891011", array("Florence", "Dante"));

$konyvtar = new Konyvtar();

//echo $konyv1."<br/>";
//echo "Ennyi kulcsszo egyezik: ".$konyv1->kulcsszavakSzama(array("Paris", 15, "0.55555", "asd"))."<br/>";
$konyv1->setISBN(9999999999999)."<br/>";
//echo $konyv1."<br/>";
//echo $konyv2;

$konyvtar->addKonyv($konyv1);
$konyvtar->addKonyv($konyv2);
echo $konyvtar;
$konyvtar->saveToFile("/var/www/adam/php/5_gyak/konyvtar.json");
echo json_encode($konyv1);
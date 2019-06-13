<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Fogadások</title>
</head>
<body>
<?php

function betolt($fajlnev){
    $fajl = fopen($fajlnev, "r");
    $adat = [];
    while(($s = fgets($fajl)) !== FALSE){
        //!feof($fajl)
        //$s = fgets($fajl);
        
        $sor = explode(" ", $s);
        $adat[] = $sor;
    }
    fclose($fajl);
    return $adat;
}

$meccsek = betolt("meccs.txt");
$fogadasok = betolt("fogadasok.txt");

echo "A kiválasztott fogadások:<br/>";
$odds = 0.0;


//for ($f = 0; $f < count($fogadasok); $f++) {
//    $i;
//    print_r($fogadasok);
//    switch ($fogadasok[$f][1]) {
//        case 'H': $i = 2;  break;
//        case 'D': $i = 3;  break;
//        case 'V': $i = 4;  break;
//    }
//    echo $i;
//    if($f != 0){
//        $odds += $meccsek[$fogadasok[$f][0]][$i];
//    }
//    else{
//        $odds += $meccsek[0][$i];
//    }
//    
//    echo $meccsek[$fogadasok[$f][0]][0]." - ".$meccsek[$fogadasok[$f][0]][1].": ".$f[1]."<br/>";
//    
//}
















function kurvaanyad($k){
    $i;
    switch ($fogadasok[$k][1]) {
        case 'H': $i = 2;  break;
        case 'D': $i = 3;  break;
        case 'V': $i = 4;  break;
    }
    $odds += $meccsek[$fogadasok[$k][0]][$i];
    echo $meccsek[$fogadasok[$k][0]][0]." - ".$meccsek[$fogadasok[$k][0]][1].": ".$f[1]."<br/>";
}










for($f =0;$f<count($fogadasok); $f++){
    kurvaanyad($f);
}




















echo "A kombinált odds: ".$odds;

?>
</body>
</html>

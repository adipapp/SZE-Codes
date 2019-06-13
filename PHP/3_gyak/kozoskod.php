<?php

function betolt($fajlnev){
    $t=[];
    if(($f= fopen($fajlnev, "r")) !== FALSE){
        $paratlan = true;
        while(($sor=fgets($f))!==FALSE){
            if($paratlan){
                $seged = [$sor];
            }
            else{
                $seged[] = $sor;
                $t[] = $seged;
            }
            $paratlan = !$paratlan;
        }
        fclose($f);
    }
    return $t;
}

function hasonlit($a, $b) {
    return $b[1] - $a[1];
}

$szemelyek = betolt("jolviselkedok.txt");
usort($szemelyek, "hasonlit");

$ajandekok = betolt("ajandekok.txt");
usort($ajandekok, "hasonlit");
<?php

require_once 'Konyv.php';

class Konyvtar{
    private $konyvek;
    
    public function addKonyv($ujkonyv){
        $this->konyvek[] = $ujkonyv;
    }
    
    public function __toString() {
        $s="";
        foreach ($this->konyvek as $konyv) {
            $s .= $konyv->__toString();
        }
        return $s;
    }
    
    public function saveToFile($fajlnev){
        $s = "";
        //$f = fopen($fajlnev, "rw");
        foreach ($this->konyvek as $konyv) {
            $s .= serialize($konyv).PHP_EOL;
        }
        //fwrite($f, $s);
        //fclose($f);
        file_put_contents($fajlnev, $s);
    }
}
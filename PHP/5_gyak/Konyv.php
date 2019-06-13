<?php

class Konyv{
    private $cim;
    private $szerzo;
    private $ISBN;
    private $kulcsszavak;
    
    public function __construct($cim, $szerzo, $ISBN, $kulcsszavak) {
        $this->cim = $cim;
        $this->szerzo = $szerzo;
        try{
            if(strlen($ISBN) != 13){
                throw new Exception ("Az ISBN 13 hosszu legyen!");
            }
            $this->ISBN = $ISBN;
        } catch (Exception $ex) {
            echo $ex->getMessage();
        }
        $this->ISBN = $ISBN;
        $this->kulcsszavak = $kulcsszavak;
    }
    
    public function getCim(){
        return $this->cim;
    }
    
    public function getSzerzo(){
        return $this->szerzo;
    }
    
    public function getISBN(){
        return $this->ISBN;
    }
    
    public function getKulcsszavak(){
        return $this->kulcsszavak;
    }
    
    public function setCim($cim){
        $this->cim=$cim;
    }
    
    public function setSzerzo($szerzo){
        $this->szerzo=$szerzo;
    }
    
    public function setISBN($ISBN){
        try{
            if(strlen($ISBN) != 13){
                throw new Exception ("Az ISBN 13 hosszu legyen!");
            }
            $this->ISBN = $ISBN;
        } catch (Exception $ex) {
            echo $ex->getMessage();
        }
    }
    
    public function setKulcsszavak($kulcsszavak){
        $this->kulcsszavak=$kulcsszavak;
    }
    
    public function __toString() {
        $s= "{$this->szerzo}:{$this->cim}({$this->ISBN}): ";
        foreach ($this->kulcsszavak as $ksz) {
            $s .= $ksz." ";
        }
        return $s;
    }
    
    public function kulcsszavakSzama($megadott){
        $i=0;
        foreach ($megadott as $ksz) {
            if(in_array($ksz, $this->kulcsszavak)){
                $i++;
            }
        }
        return $i;
    }
}


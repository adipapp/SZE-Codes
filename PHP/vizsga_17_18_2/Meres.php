<?php

class Meres{
	private $rajtszam;
	private $ellenorzopont;
	private $ora;
	private $perc;
	private $mp;
	
	public function __construct($rajtszam, $ellenorzopont, $ora, $perc, $mp){
		$this->rajtszam = $rajtszam;
		$this->ellenorzopont = $ellenorzopont;
		$this->ora = $ora;
		$this->perc = $perc;
		$this->mp = $mp;
	}
	
	public function getRajtszam(){
		return $this->rajtszam;
	}
	
	public function getEllpont(){
		return $this->ellenorzopont;
	}
	
	public function getTime(){
		return ($this->ora . ':' . $this->perc . ':' . $this->mp);
	}
	
	public function getTimeFormat(){
		return ($this->ora*3600+$this->perc*60+$this->mp);
	}

	public function getOra(){
		return $this->ora;
	}

	public function getPerc(){
		return $this->perc;
	}

	public function getMp(){
		return $this->mp;
	}
}
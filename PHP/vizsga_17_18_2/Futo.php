<?php 

require_once 'Meres.php';

class Futo{
	private $rajtszam;
	private $meresek = array();
	private $status;
	
	public function __construct($rajtszam, $meres){
		$this->rajtszam = $rajtszam;
		array_push($this->meresek, $meres);
		$this->status = 'még nem ért célba';
	}
	
	public function addMeres($meres){
		if(count($this->meresek) != 0 && end($this->meresek)->getEllpont() + 1 != $meres->getEllpont()){
			$this->status = 'versenyből kizárva';
		}
		else if($meres->getEllpont() == 3){
			$start = $this->meresek[0]->getTimeFormat();
			$end = $meres->getTimeFormat();
			$time = $end - $start;
			$ora = intdiv($time, 3600);
			$perc = intdiv(($time % 3600), 60);
			$mp = $time % 60;
			$this->status = $ora . ':' . $perc . ':' . $mp;
		}
		array_push($this->meresek, $meres);
	}
	
	public function getStatus(){
		return $this->status;
	}

	public function getRajtszam(){
		return $this->rajtszam;
	}
	
	public function getUtolsoIdo(){
		return end($this->meresek)->getTime();
	}
	
	public function getUtolsoEllpont(){
		return end($this->meresek)->getEllpont();
	}
	
	public function getHTML(){
		return ("<tr><td>" . $this->rajtszam . "</td><td>" . $this->getUtolsoEllpont() . "</td><td>" . $this->getUtolsoIdo() . "</td><td>" . $this->status . "</td></tr>");
	}

}
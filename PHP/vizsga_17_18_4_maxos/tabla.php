<?php

require_once 'hajo.php';

class Tabla
{
	public $szel;
	public $mag;
	public $tabla;
	public $hajok;
	public $lovesek;
	public $elsullyedthajok;
	public $jatekos;
	
	function __construct($szel, $mag, $jatekos)
	{
		$this->jatekos = $jatekos;
		$this->tabla=array();
		$this->lovesek=array();
		$this->hajok=array();
		$this->szel=$szel;
		$this->mag=$mag;
		for ($i=0; $i < $mag*$szel; $i++) {
			array_push($this->tabla, " ");
		}
		array_push($this->hajok, new Hajo($szel, $mag));
		while(count($this->hajok) != 4) {
			$ujhajo = new Hajo($szel, $mag);
			$atfed = false;
			foreach ($this->hajok as $h) {
				if($ujhajo->atfed($h)){
					$atfed = true;
				}
			}
			if(!$atfed){
				array_push($this->hajok, $ujhajo);
			}
		}
	}

	function loves($l){
		if(in_array($l, $this->lovesek)){ return; }
		$talalt = false;
		array_push($this->lovesek, $l);
		foreach ($this->hajok as $h) {
			if($h->talalt($l)){
				$talalt = true;
				$this->tabla[$l-1] = "o";
				$h->eltalalt_mezok += 1;
				break;
			}
		}
		if(!$talalt){
			$this->tabla[$l-1] = "-";
		}
		$sunk = 0;
		foreach ($this->hajok as $h) {
			if($h->eltalalt_mezok == 4){
				$t = $h->hajopontjai;
				$sunk += 1;
				foreach ($t as $m) {
					$this->tabla[$m-1] = "X";
				}
			}
		}
		$this->elsullyedthajok = $sunk;
	}

	function getHTML(){
		$html = "<table><tr>";
		for ($i=1; $i <= $this->szel*$this->mag; $i++) { 
			if($this->tabla[$i-1] == " "){
				$html .= "<td><input type='checkbox' name='loves' value='".$i."' /></td>";
			}
			else{
				$html .= "<td>".$this->tabla[$i-1]."</td>";
			}
			if($i % $this->szel == 0){
				$html .= "</tr><tr>";
			}
		}
		$html .= "</tr></table>";
		return $html;
	}
}
<?php

class Idopont{
	public $nev;
	public $idopontok = array();

	public function __construct($nev, $hetfo, $kedd, $szerda, $csutortok, $pentek){
		$this->nev = $nev;
		$this->idopontok = array('hetfo' => $hetfo, 'kedd' => $kedd, 'szerda' => $szerda, 'csutortok' => $csutortok, 'pentek'=> $pentek);
	}

	public function toHTML(){
		$s = "<form><input type='text' disabled='disabled' name='nev' value='" . $this->nev . "'>";
		foreach ($this->idopontok as $i => $v) {
			$s .= "<input type='checkbox' disabled='disabled' checked='";
			if($v){
				$s .= "checked";
			}
			$s .= "'>";
		}
		$s .= "</form>";
		return $s;
	}
}
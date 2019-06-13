<?php

class Hajo
{
	public $balfelso;
	public $eltalalt_mezok;
	public $hajopontjai;

	function __construct()
	{
		$this->balfelso=rand(1, 89);
		while ($this->balfelso % 10 == 0) {
			$this->balfelso=rand(1, 89);	
		}
		$this->hajopontjai = array($this->balfelso, $this->balfelso+1, $this->balfelso+10, $this->balfelso+11);
		$this->eltalalt_mezok=0;
	}

	function atfed($masikhajo){
		foreach ($masikhajo->hajopontjai as $p) {
			if(in_array($p, $this->hajopontjai)){
				return true;
			}
		}
		return false;
	}

	function talalt($l){
		return in_array($l, $this->hajopontjai);
	}
}
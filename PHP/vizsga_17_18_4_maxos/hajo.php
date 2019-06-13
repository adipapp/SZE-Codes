<?php

class Hajo
{
	public $balfelso;
	public $eltalalt_mezok;
	public $tipus;
	public $hajopontjai;

	function __construct($szel, $mag)
	{
		$this->tipus = rand(1,3); # 1: 2x2, 2: 4x1, 3: 1x4
		switch ($this->tipus) {
			case 1:
			$this->balfelso=rand(1, ($szel-1)*$mag-1);
			while ($this->balfelso % $szel == 0) {
				$this->balfelso=rand(1, ($szel-1)*$mag-1);	
			}
			$this->hajopontjai = array($this->balfelso, $this->balfelso+1, $this->balfelso+$szel, $this->balfelso+$szel+1);
			break;
			case 2:
			$this->balfelso=rand(1, $szel*$mag);
			while ($this->balfelso % $szel == 0 || $this->balfelso % $szel > $szel-3) {
				$this->balfelso=rand(1, $szel*$mag);	
			}
			$this->hajopontjai = array($this->balfelso, $this->balfelso+1, $this->balfelso+2, $this->balfelso+3);
			break;
			case 3:
			$this->balfelso=rand(1, ($szel-3)*$mag);
			$this->hajopontjai = array($this->balfelso, $this->balfelso+$szel, $this->balfelso+2*$szel, $this->balfelso+3*$szel);
			break;
		}
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
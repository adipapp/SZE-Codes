# AI, Halo, OS /// SzAR, SzR, SzT
# Dani, Kristof, Isti /// Balint, Adam, Niki
# 10, 4, 4, 8, 5, 9, 2, 3, 15

set Emberek;
set Targyak;

param mennyiert{e in Emberek, t in Targyak};

var megcsinalja{e in Emberek, t in Targyak}, binary;

s.t. EgyEmberMaxEgyet{e in Emberek}:
 sum{t in Targyak} megcsinalja[e, t] <= 1;
 
s.t. MindenTargyatMinEgyEmber{t in Targyak}:
 sum{e in Emberek} megcsinalja[e, t] >= 1;
 
minimize KTG:
 sum{e in Emberek, t in Targyak} megcsinalja[e, t] * mennyiert[e, t];

data;

set Emberek := Dani Kristof Isti;
set Targyak := AI Halo OS;

param mennyiert:
		AI	Halo OS :=
Dani	10	4	 4
Kristof	8	5	 9
Isti	2	3	15
;

end;

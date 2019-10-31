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

set Emberek := Tomi Patrik Istvan Benjamin;
set Targyak := Matek Dave Prog Tesi;

param mennyiert:
		Matek Dave Prog Tesi :=
Tomi	500     20   30  0
Patrik	10      100  1   2.5
Istvan	1       2    3   4
Benjamin 8      7    6   5
;

end;

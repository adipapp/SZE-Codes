set Fest;
set Band;

param p{f in Fest, b in Band}, binary; #1. dim/ind: sorok, 2. dim/ind: oszlopok

var participate{f in Fest}, binary;

s.t. Fest_Band{b in Band}:
 sum{f in Fest} p[f, b]*participate[f]>=1;
 
minimize Fest_participation:
 sum{f in Fest} participate[f];

data;

set Fest := F1 F2 F3 F4 F5;
set Band := Hag Str Epi Dal Apo Liv Elu;

param p (tr): #(tr) transponált mtx: dimeziók felcserélése
	F1 F2 F3 F4 F5 := 
Hag 1  0  1  1  0
Str 1  1  1  0  1
Epi 1  1  0  1  1
Dal 0  0  1  0  1
Apo 0  0  0  1  0
Liv 0  1  1  1  1
Elu 0  0  1  0  1
;

end;

set Targyak;
set Emberek;

param dij{Emberek,Targyak};

var y{Emberek,Targyak} binary;

s.t. LegalabbEgyJegyzet{t in Targyak}:
  sum{e in Emberek} y[e,t] >= 1;

s.t. MindenkiMaxEgyet{e in Emberek}:
  sum{t in Targyak} y[e,t] <= 1;

minimize OsszesPenz:
  sum{e in Emberek, t in Targyak} y[e,t]*dij[e,t];

solve;

printf "Osszes penz: %g\n\n",OsszesPenz;

for{e in Emberek, t in Targyak: y[e,t]==1}
{
  printf "%20s\t%10s\t%4g\n",t,e,dij[e,t];
}

data;

set Targyak := OS Halo AI Donteselokeszites;
set Emberek := Ancsi Joska Pisti Zsuzsi Sanyi;

param dij:
          OS    Halo    AI    Donteselokeszites:=
  Ancsi   4     3       8     99
  Joska   6     9       15    5 
  Zsuzsi  3     5       4     3
  Pisti   2     6       8     1
  Sanyi   6     12      54    0
;

end;

var xKF>=0;
var xNF>=0;
var xHL>=0;
var xHM>=0;
var xVHM>=0;
var xKuF>=0;
var xSF>=0;
var xPF>=0;

s.t. BorKeszlet:
 0.1*xKF+0.2*xNF+0.1*xHL+0.3*xHM+0.2*xVHM+0.9*xKuF+0.1*xSF+0.6*xPF<=100;
 
s.t. SzodaKeszlet:
 0.1*xKF+0.1*xNF+0.2*xHL+0.2*xHM+0.3*xVHM+0.1*xKuF+0.9*xSF+0.3*xPF<=150;

maximize Profit: 
 110*xKF+200*xNF+120*xHL+260*xHM+200*xVHM+800*xKuF+200*xSF+550*xPF;
 
end;

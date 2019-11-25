param days;
param initialBudget;
set Farmers;
param price{Farmers};
param dailyIncome{Farmers};

var dailyStartBalance{1..days} >= 0;
var boughtFarmers{1..days,Farmers} >= 0 integer;

s.t. FirstDayBalance:
	dailyStartBalance[1] = initialBudget;

s.t. DailyStartBalance{d in 2..days}:
	dailyStartBalance[d] = dailyStartBalance[d-1] - sum{f in Farmers} boughtFarmers[d-1, f] * price[f] + sum{delta in 1..d-2} sum{f in Farmers} boughtFarmers[delta, f] * dailyIncome[f];

s.t. DontOverBuy{d in 1..days}:
	dailyStartBalance[d] - sum{f in Farmers} boughtFarmers[d, f] * price[f] >= 0;

maximize LastDayBalance:
	dailyStartBalance[days];

solve;



data;

param days := 25;
param initialBudget := 20;
set Farmers := Peasant Plower Harvester;
param price := Peasant 10 Plower 30 Harvester 100;
param dailyIncome := Peasant 2 Plower 10 Harvester 30;

end;

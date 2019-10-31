set Resource;
set Demand;

param resource{j in Resource};
param demand{i in Demand};
param dist{i in Demand, j in Resource};
param maxLiter;
param fCost;

var cost{i in Demand, j in Resource} >= 0;
var fNo{i in Demand, j in Resource} integer;

s.t. DemandConstraint{i in Demand}: sum{j in Resource} cost[i,j] >= demand[i];

s.t. ResourceDemand{j in Resource}: sum{i in Demand} cost[i,j] <= resource[j];

s.t. FutarConstraint{i in Demand, j in Resource}: cost[i,j] <= maxLiter * fNo[i,j];

minimize FullCost: sum{i in Demand, j in Resource} (cost[i,j] * dist[i,j] + fNo[i,j]*fCost*2*dist[i,j]);

data;

set Resource := Komarom Veszprem Sarvar;
set Demand := Gyor Szombathely;

param resource := Komarom 50
                  Veszprem 200
                  Sarvar 150;

param demand := Gyor 280
                Szombathely 120;

param dist: Komarom Veszprem Sarvar :=
Gyor        40      80          85
Szombathely 160     150         50;

param maxLiter := 20;

param fCost := 10;

end;

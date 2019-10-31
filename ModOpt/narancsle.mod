set Resource;
set Demand;

param resource{j in Resource};
param demand{i in Demand};
param dist{i in Demand, j in Resource};

var cost{i in Demand, j in Resource} >= 0;

s.t. DemandConstraint{i in Demand}: sum{j in Resource} cost[i,j] >= demand[i];

s.t. ResourceDemand{j in Resource}: sum{i in Demand} cost[i,j] <= resource[j];

minimize FullCost: sum{i in Demand, j in Resource} cost[i,j] * dist[i,j];

data;

set Resource := Komarom Veszprem Sarvar;
set Demand := Gyor Szombathely;

param resource := Komarom 50
                  Veszprem 150
                  Sarvar 200;

param demand := Gyor 280
                Szombathely 120;

param dist: Komarom Veszprem Sarvar :=
Gyor        40      85          80
Szombathely 160     50         150;

end;
